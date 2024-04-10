#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
int dist[MAXN];
bool bio[MAXN];
int dp[MAXN], dad[MAXN];
int a[MAXN], b[MAXN], c[MAXN];  
vector < pii > E[MAXN];
vector <int> V[MAXN];
queue <int> Q;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
        E[a[i]].push_back(pii(b[i], c[i]));
        E[b[i]].push_back(pii(a[i], c[i]));
        V[a[i]].push_back(i);
        V[b[i]].push_back(i);
    }
}

void add(int x, int d) {
    if (dist[x] != -1) return;
    dist[x] = d + 1;
    Q.push(x);
}

int rec(int x) {
    int &ref = dp[x];
    if (ref != -1) return ref;
    for (int i = 0; i < E[x].size(); i++) { 
        if (dist[x] < dist[E[x][i].first]+ 1) continue;
        int tmp = rec(E[x][i].first) + E[x][i].second;
        if (tmp < ref) continue;
        dad[x] = i;
        ref = tmp;
    }
    return ref;
}

void solve() {
    memset(dist, -1, sizeof dist);
    add(1, -1);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++) 
            add(E[x][i].first, dist[x]);
    }

    memset(dp, -1, sizeof dp);
    dp[1] = 0;
    rec(N);
    vector <int> sol;
    for (int x = N; x > 1; x = E[x][dad[x]].first) {
        if (!E[x][dad[x]].second) sol.push_back(V[x][dad[x]]);
        bio[V[x][dad[x]]] = true;
    }
    
    for (int i = 0; i < M; i++)
        if (!bio[i] && c[i]) sol.push_back(i);
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d %d\n", a[sol[i]], b[sol[i]], c[sol[i]] ^ 1);
}

int main() {
    load();
    solve();
    return 0;
}