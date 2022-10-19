#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair <int, int> pii;
#define x first
#define y second

const int MAXN = 2000005;

int N, M;
map <int, vector <pii> > Q;
vector <int> sol[MAXN];
int row[MAXN], col[MAXN];
vector <int> E[MAXN];
int maks[MAXN];
vector <int> comp;
bool bio[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            Q[x].push_back(pii(i, j));
        }
}

int dfs(int x) {
    if (bio[x]) return 0;
    bio[x] = true;
    comp.push_back(x);
    int res = maks[x];
    for (int i = 0; i < E[x].size(); i++)
        res = max(res, dfs(E[x][i]));
    return res;
}

void solve() {
    for (int i = 0; i < N; i++)
        sol[i].resize(M);
    
    for (map <int, vector <pii> > :: iterator it = Q.begin(); it != Q.end(); it++) {
        vector <pii> tmp = it -> second;
        for (int i = 0; i < tmp.size(); i++) {
            E[tmp[i].x].push_back(tmp[i].y + N);
            E[tmp[i].y + N].push_back(tmp[i].x);
            int val = max(row[tmp[i].x], col[tmp[i].y]) + 1;
            maks[tmp[i].x] = max(maks[tmp[i].x], val);
            maks[tmp[i].y + N] = max(maks[tmp[i].y + N], val);
        }
        
        for (int i = 0; i < tmp.size(); i++) {
            int val = dfs(tmp[i].x);
            for (int j = 0; j < comp.size(); j++)
                maks[comp[j]] = val;
            comp.clear();
            val = dfs(tmp[i].y + N);
            for (int j = 0; j < comp.size(); j++)
                maks[comp[j]] = val;
            comp.clear();
        }
        
        for (int i = 0; i < tmp.size(); i++) {
            sol[tmp[i].x][tmp[i].y] = maks[tmp[i].x];
            row[tmp[i].x] = max(row[tmp[i].x], sol[tmp[i].x][tmp[i].y]);
            col[tmp[i].y] = max(col[tmp[i].y], sol[tmp[i].x][tmp[i].y]);
        }
        
        for (int i = 0; i < tmp.size(); i++) {
            E[tmp[i].x].clear();
            E[tmp[i].y + N].clear();
            maks[tmp[i].x] = maks[tmp[i].y + N] = 0;
            bio[tmp[i].x] = bio[tmp[i].y + N] = false;
        }
    }
    
    for (int i = 0; i < N; i++, puts(""))
        for (int j = 0; j < M; j++)
            printf("%d ", sol[i][j]);
}

int main() {
    load();
    solve();
    return 0;
}