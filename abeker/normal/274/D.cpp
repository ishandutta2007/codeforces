#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;

int N, M;
vector <int> E[MAXN];
int bio[MAXN];
vector <int> sol;
int dummy;

void add_edge(int x, int y) {
    E[y].push_back(x);
}

void load() {
    scanf("%d%d", &N, &M);
    dummy = M;
    for (int i = 0; i < N; i++) {
        vector <pii> tmp;
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            if (x != -1) 
                tmp.push_back(pii(x, j));
        }
        sort(tmp.begin(), tmp.end());
        vector <int> curr;
        for (int j = 0; j < tmp.size(); j++)
            if (!j || tmp[j].first != tmp[j - 1].first)
                curr.push_back(j);
        curr.push_back(tmp.size());
        for (int j = 1; j < (int)curr.size() - 1; j++) {
            for (int k = curr[j - 1]; k < curr[j]; k++) 
                add_edge(tmp[k].second, dummy);
            for (int k = curr[j]; k < curr[j + 1]; k++)
                add_edge(dummy, tmp[k].second);
            dummy++;
        }
    }
}

bool dfs(int x) {
    if (bio[x] == 2) return false;
    if (bio[x] == 1) return true;
    bio[x] = 1;
    for (int i = 0; i < E[x].size(); i++)
        if (dfs(E[x][i])) return true;
    sol.push_back(x);
    bio[x] = 2;
    return false;
}

void solve() {
    for (int i = 0; i < dummy; i++)
        if (dfs(i)) {
            puts("-1");
            return;
        }
        
    for (int i = 0; i < sol.size(); i++)
        if (sol[i] < M) printf("%d ", ++sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}