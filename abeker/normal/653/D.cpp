#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAXN = 55;
const int MAXM = 505;
const ll INF = (ll)1e18;

int N, M, X;
int a[MAXM], b[MAXM], c[MAXM];
ll edge[MAXN][MAXN];
bool bio[MAXN];
ll flow;

void load() {
    scanf("%d%d%d", &N, &M, &X);
    for (int i = 0; i < M; i++)
        scanf("%d%d%d", a + i, b + i, c + i);
}

ll dfs(int x, ll cap) {
    if (cap <= 0) return 0;
    bio[x] = true;
    if (x == N) {
        flow += cap;
        return cap;
    }
    for (int i = 1; i <= N; i++) {
        if (bio[i]) continue;
        ll tmp = dfs(i, min(cap, edge[x][i]));
        if (tmp > 0) {
            edge[x][i] -= tmp;
            edge[i][x] += tmp;
            return tmp;
        }
    }
    return 0;
}

bool check(double val) {
    memset(edge, 0, sizeof edge);
    for (int i = 0; i < M; i++)
        edge[a[i]][b[i]] = (ll)floor(c[i] / val);
    
    flow = 0;
    while (1) {
        memset(bio, false, sizeof bio);
        if (!dfs(1, INF)) break;
    }
    
    return flow >= X;
}

double solve() {
    double lo = 0, hi = 1e7;    
    for (int it = 0; it < 60; it++) {
        double mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    return lo * X;
}

int main() {
    load();
    printf("%.10lf\n", solve());
    return 0;
}