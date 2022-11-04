#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector <ll> V[233333];

ll Mx[233333];

int main() {
    int n;
    ll sm = 0, mx = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        ll k, xx = 0;
        scanf("%lld", &k);
        V[i].resize(k);
        for(int j = 0; j < k; j++) scanf("%lld", &V[i][j]), xx = max(xx, V[i][j]);
        Mx[i] = xx;
        mx = max(mx, xx);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += V[i].size() * (mx - Mx[i]);
    printf("%lld\n", ans);
    return 0;
}