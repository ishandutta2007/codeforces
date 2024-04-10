#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 10005;
const int MAXK = 205;
const ll INF = 0x3f3f3f3fll;
const char msg[5][5] = {"WIN", "DRAW", "LOSE"};

int N, M, K;
int s1, s2, f;
int u[MAXK], v[MAXK], l[MAXK], r[MAXK];
vector <pii> E[MAXN];
vector <int> spec;
ll dist[MAXN];
bool bio[MAXN];
ll graph[MAXK][MAXK], ngraph[MAXK][MAXK];
int idx[MAXN];
int dad[MAXK];
bool bad[MAXK];
ll to[MAXK];
bool in[MAXK];
ll sol = -INF;

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (dist[lhs] != dist[rhs]) 
            return dist[lhs] < dist[rhs];
        return lhs < rhs;
    }
};

void load() {
    scanf("%d%d%d", &N, &M, &K);
    scanf("%d%d%d", &s1, &s2, &f);
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[b].push_back(pii(a, c));
    }
    for (int i = 0; i < K; i++)
        scanf("%d%d%d%d", u + i, v + i, l + i, r + i);
}

void dijkstra(int node) {
    memset(dist, INF, sizeof dist);
    memset(bio, false, sizeof bio);
    dist[node] = 0;
    set <int, cmp> S;
    for (int i = 1; i <= N; i++)
        S.insert(i);
    
    while (!S.empty()) {
        int x = *S.begin();
        S.erase(x);
        bio[x] = true;
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i].first;
            if (bio[nxt]) continue;
            ll cand = dist[x] + E[x][i].second;
            if (cand < dist[nxt]) {
                S.erase(nxt);
                dist[nxt] = cand;
                S.insert(nxt);
            }
        }
    }
      
    for (int i = 1; i <= N; i++)
        if (idx[i] != -1)
            graph[idx[node]][idx[i]] = dist[i];
}

ll get(int x) {
    return to[x] + dist[x];
}

bool process() {
    memset(dist, INF, sizeof dist);
    dist[f] = 0;
    
    memset(bio, false, sizeof bio);
    for (int i = 0; i < spec.size(); i++) {
        if (bad[i]) bio[i] = true;
        dad[i] = f;
    }
    
    for (int i = 1; i < spec.size(); i++) {
        ll mini = INF + 1;
        int x = spec.size();
        for (int j = 0; j < spec.size(); j++)
            if (!bio[j] && dist[j] < mini) {
                mini = dist[j];
                x = j;
            }
        bio[x] = true;
        for (int j = 0; j < spec.size(); j++) {
            ll cand = dist[x] + graph[x][j];
            if (bad[j] || cand >= dist[j]) continue;
            dist[j] = cand;
            dad[j] = x;
        }
    }
    
    vector <int> path;
    for (int x = s1; x != f; x = dad[x])
        path.push_back(x);
    path.push_back(f);
    
    int opt = path[0];
    for (int i = 0; i < path.size(); i++)
        if (get(path[i]) < get(opt)) opt = path[i];
    
    bad[opt] = true;
    ll cand = get(opt) - dist[s1];
    if (cand > sol) {
        sol = cand;
        memset(in, false, sizeof in);
        for (int i = 1; i < path.size(); i++)
            for (int j = 0; j < K; j++)
                if (u[j] == path[i - 1] && v[j] == path[i] && graph[v[j]][u[j]] == l[j])    
                    in[j] = true;
    }
    
    return opt != s1 && opt != f;
}

int sgn(ll val) {
    if (val > 0) return 0;
    if (val < 0) return 2;
    return 1;
}

void precalc() {
    for (int i = 0; i < spec.size(); i++)
        for (int j = 0; j < spec.size(); j++)
            ngraph[i][j] = graph[j][i];
    
    for (int i = 0; i < K; i++)
        ngraph[u[i]][v[i]] = min(ngraph[u[i]][v[i]], (ll)r[i]);
    
    memset(dist, INF, sizeof dist);
    dist[s2] = 0;
    
    memset(bio, false, sizeof bio);
    for (int i = 1; i < spec.size(); i++) {
        ll mini = INF + 1;
        int x = spec.size();
        for (int j = 0; j < spec.size(); j++)
            if (!bio[j] && dist[j] < mini) {
                mini = dist[j];
                x = j;
            }
        bio[x] = true;
        for (int j = 0; j < spec.size(); j++) 
            dist[j] = min(dist[j], dist[x] + ngraph[x][j]); 
    }
        
    memcpy(to, dist, sizeof to);
}

void norm(int &ref) {
    ref = idx[ref];
}

void solve() {
    spec.push_back(s1);
    spec.push_back(s2);
    spec.push_back(f);
    for (int i = 0; i < K; i++) {
        spec.push_back(u[i]);
        spec.push_back(v[i]);
    }
    
    sort(spec.begin(), spec.end());
    spec.resize(unique(spec.begin(), spec.end()) - spec.begin());
    memset(idx, -1, sizeof idx);
    for (int i = 0; i < spec.size(); i++)
        idx[spec[i]] = i;
    
    norm(s1);
    norm(s2);
    norm(f);
    for (int i = 0; i < K; i++) {
        norm(u[i]);
        norm(v[i]);
    }
    
    memset(graph, INF, sizeof graph);
    for (int i = 0; i < spec.size(); i++)
        dijkstra(spec[i]);
        
    precalc();
    
    for (int i = 0; i < K; i++)
        graph[v[i]][u[i]] = min(graph[v[i]][u[i]], (ll)l[i]);
        
    while (process());
    
    int who = sgn(sol);
    puts(msg[who]);
    if (who == 2) return;
    for (int i = 0; i < K; i++)
        printf("%d ", in[i] ? l[i] : r[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}