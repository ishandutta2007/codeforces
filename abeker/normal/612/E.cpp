#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1000005;

int N;
int p[MAXN];
bool bio[MAXN];
int sol[MAXN];
vector < vector <int> > V[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i);
}

void dfs(int x) {
    if (bio[x]) return;
    vector <int> cyc;
    for (; !bio[x]; x = p[x]) {
        cyc.push_back(x);
        bio[x] = true;
    }
    
    int sz = cyc.size();
    if (sz % 2) {
        vector <int> tmp(sz);
        for (int i = 0; i < sz; i++)
            tmp[2 * i % sz] = cyc[i];
        for (int i = 0; i < sz; i++)
            sol[tmp[i]] = tmp[(i + 1) % sz];
        return;
    }
    
    V[sz].push_back(cyc);
}

void merge(vector <int> a, vector <int> b) {
    vector <int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    int sz = c.size();
    for (int i = 0; i < sz; i++)
        sol[c[i]] = c[(i + 1) % sz];
}

void solve() {
    for (int i = 1; i <= N; i++) 
        dfs(i);

    for (int i = 1; i <= N; i++) {
        if (V[i].size() % 2) {
            puts("-1");
            return;
        }
        for (int j = 0; j < V[i].size(); j += 2)
            merge(V[i][j], V[i][j + 1]);
    }   
    
    for (int i = 1; i <= N; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}