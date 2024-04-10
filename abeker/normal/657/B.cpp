#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200100;
const ll INF = (ll)1e18;

int N, K;
ll a[MAXN], b[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i <= N; i++)
        scanf("%I64d", a + i);
}

int solve() {
    memcpy(b, a, sizeof b);
    int pos = N + 30;
    for (int i = 0; i < N + 30; i++) {
        if (a[i] % 2) {
            pos = i;
            break;
        }
        a[i + 1] += a[i] / 2;
    }
    
    ll val = 0;
    for (int i = N + 30; i >= pos; i--) {
        val = 2 * val + a[i];
        if (abs(val) > INF) return 0;
    }
    
    int sol = 0;
    for (int i = pos; i >= 0; i--) {
        if (abs(val) > INF) break;
        ll coef = b[i] - val;
        if (abs(coef) <= K && i <= N && (i < N || coef)) sol++;
        val *= 2;
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}