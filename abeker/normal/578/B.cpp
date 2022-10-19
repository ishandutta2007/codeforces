#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, K, X;
int a[MAXN];
int pref[MAXN], suff[MAXN];

void load() {
    scanf("%d%d%d", &N, &K, &X);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

ll solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] | a[i];    
    for (int i = N; i; i--)
        suff[i] = suff[i + 1] | a[i];
    
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        ll tmp = (ll)a[i];
        for (int j = 0; j < K; j++)
            tmp *= (ll)X;
        sol = max(sol, (ll)pref[i - 1] | (ll)suff[i + 1] | tmp);
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}