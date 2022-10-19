#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N, M;
vector <int> tot[MAXN], occ[MAXN][2];
vector <pii> E[MAXN];
bool bio[MAXN], was[MAXN];
pii dad[MAXN];
int sol[MAXN];
vector <int> cycle;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            occ[abs(x)][x > 0].push_back(i);
            tot[abs(x)].push_back(i);
        }
    }
}

void add_edge(int a, int b, int c) {
    E[a].push_back(pii(b, c));
    E[b].push_back(pii(a, c));
}

void set(int var, int val) {
    if (sol[var] != -1) return;
    for (int i = 0; i < 2; i++)
        if (count(occ[var][i].begin(), occ[var][i].end(), val))
            sol[var] = i;
}

void flood(int x) {
    bio[x] = true;
    for (int i = 0; i < E[x].size(); i++) { 
        int nxt = E[x][i].first;
        if (bio[nxt]) continue;
        set(E[x][i].second, nxt);
        flood(nxt);
    }
}

bool dfs(int x, pii prev) {
    if (bio[x]) return false;
    dad[x] = prev;
    was[x] = true;
    for (int i = 0; i < E[x].size(); i++) {
        int node = E[x][i].first;
        int edge = E[x][i].second;
        if (edge == prev.second) continue;
        if (was[node]) {
            set(edge, x);
            while (x != node) {
                cycle.push_back(x);
                set(dad[x].second, dad[x].first);
                x = dad[x].first;
            }
            cycle.push_back(node);
            for (int i = 0; i < cycle.size(); i++)
                bio[cycle[i]] = true;
            return true;
        }
        if (dfs(node, pii(x, edge))) 
            return true;
    }
    return false;
}

void solve() {
    for (int i = 1; i <= M; i++) 
        if (tot[i].size() == 2)
            add_edge(tot[i][0], tot[i][1], i);
            
    memset(sol, -1, sizeof sol);
    for (int i = 1; i <= M; i++)
        for (int j = 0; j < 2; j++)
            if (occ[i][j ^ 1].empty()) {
                for (int k = 0; k < occ[i][j].size(); k++)
                    if (!bio[occ[i][j][k]]) flood(occ[i][j][k]);
                sol[i] = j;
            }
    
    for (int i = 0; i < N; i++) {
        if (bio[i] || was[i]) continue;
        if (!dfs(i, pii(-1, 0))) {
            puts("NO");
            return;
        }
        for (; !cycle.empty(); cycle.pop_back())
            flood(cycle.back());
    }
    
    puts("YES");
    for (int i = 1; i <= M; i++)
        printf("%d", sol[i] == -1 ? rand() % 2 : sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}