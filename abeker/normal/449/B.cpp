#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
    int to, w, idx;
    edge(int to, int w, int idx) : to(to), w(w), idx(idx) {}
    edge() : to(0), w(0), idx(0) {}
};

int N, M, K;
vector <edge> E[MAXN];
int s[MAXN], y[MAXN];   
ll dist[MAXN];
bool bio[MAXN];

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs])     
            return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

set <int, cmp> S;

void add_edge(int u, int v, int x, int id) {
    E[u].push_back(edge(v, x, id));
    E[v].push_back(edge(u, x, id));
}

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        add_edge(u, v, x, 0);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d%d", s + i, y + i);
        add_edge(1, s[i], y[i], 1);
    }
}

int solve() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= N; i++)
        S.insert(i);
        
    while (!S.empty()) {
        int x = *S.begin();
        S.erase(x);
        bio[x] = true;
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i].to;
            if (bio[nxt]) continue;
            ll cand = dist[x] + E[x][i].w;
            if (cand < dist[nxt]) {
                S.erase(nxt);
                dist[nxt] = cand;
                S.insert(nxt);
            }
        }
    }
    
    int sol = 0;
    for (int i = 2; i <= N; i++) {
        vector <bool> tmp;
        for (int j = 0; j < E[i].size(); j++) 
            tmp.push_back(dist[E[i][j].to] + E[i][j].w == dist[i]);
        bool has = false;
        int cnt = 0;
        for (int j = 0; j < tmp.size(); j++) 
            if (E[i][j].idx) cnt++;
            else has |= tmp[j];
        sol += cnt - 1 + has;
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}