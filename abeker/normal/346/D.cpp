#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;

int N, M;
int s, t;
vector <int> inv[MAXN];
int deg[MAXN];
int dist[MAXN];

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) 
            return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set <int, cmp> S;

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int u, v;
        scanf("%d%d", &u, &v);
        inv[v].push_back(u);
        deg[u]++;
    }
    scanf("%d%d", &s, &t);
}

int solve() {
    memset(dist, INF, sizeof dist);
    dist[t] = 0;
    for (int i = 1; i <= N; i++)
        S.insert(i);
    
    while (!S.empty()) {
        int x = *S.begin();
        S.erase(x);
        for (int i = 0; i < inv[x].size(); i++) {
            int nxt = inv[x][i];
            if (dist[x] < dist[nxt]) {
                deg[nxt]--;
                S.erase(nxt);
                dist[nxt] = dist[x] + !!deg[nxt];
                S.insert(nxt);
            }
        }
    }
    
    return dist[s] < INF ? dist[s] : -1;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}