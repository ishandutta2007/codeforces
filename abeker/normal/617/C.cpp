#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;

int N;
int x1, y1, x2, y2;
int x[MAXN], y[MAXN];

void load() {
    scanf("%d%d%d%d%d", &N, &x1, &y1, &x2, &y2);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

ll dist(int a, int b, int c, int d) {
    return (ll)(a - c) * (a - c) + (ll)(b - d) * (b - d);
}

ll solve() {
    ll sol = (ll)1e18;
    for (int i = 0; i <= N; i++) {
        ll tmp = 0, maks = 0;
        if (i < N) tmp = dist(x1, y1, x[i], y[i]);
        for (int j = 0; j < N; j++) 
            if (dist(x1, y1, x[j], y[j]) > tmp)
                maks = max(maks, dist(x2, y2, x[j], y[j]));
        sol = min(sol, tmp + maks); 
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}