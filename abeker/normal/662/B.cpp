#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
vector <pii> E[MAXN];
int color[MAXN], sol[MAXN];
vector <int> comp;

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        char c;
        scanf("%d%d %c", &u, &v, &c);
        E[u].push_back(pii(v, c == 'B'));
        E[v].push_back(pii(u, c == 'B'));
    }   
}

bool dfs(int x, int c) {
    if (color[x] != -1) 
        return color[x] == c;
    color[x] = c;
    comp.push_back(x);
    for (int i = 0; i < E[x].size(); i++)
        if (!dfs(E[x][i].first, c ^ E[x][i].second))
            return false;
    return true;
}

void solve() {
    int K = N + 1;
    for (int k = 0; k < 2; k++) {
        memset(color, -1, sizeof color);
        bool ok = true;
        int tot = 0;
        for (int i = 1; i <= N; i++) {
            comp.clear();
            if (color[i] != -1) continue;
            if (!dfs(i, 0)) {
                ok = false;
                break;
            }
            int cnt = 0;
            for (int j = 0; j < comp.size(); j++)
                cnt += color[comp[j]];
            int alt = (int)comp.size() - cnt;
            tot += min(alt, cnt);
            if (cnt > alt) 
                for (int j = 0; j < comp.size(); j++)
                    color[comp[j]] ^= 1;
        }
        if (ok && tot < K) {
            K = tot;
            memcpy(sol, color, sizeof sol);
        }
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < E[i].size(); j++)
                E[i][j].second ^= 1;
    }
    
    if (K > N) {
        puts("-1");
        return;
    }
    
    printf("%d\n", K);
    for (int i = 1; i <= N; i++)
        if (sol[i]) printf("%d ", i);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}