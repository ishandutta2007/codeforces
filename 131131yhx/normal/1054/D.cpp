#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long

using namespace std;

int n, k, X[200010], S[200010];

map <int, int> hsh;

signed main() {
    scanf("%lld%lld", &n, &k);
    int tot = (1 << k) - 1;
    for(int i = 1; i <= n; i++) scanf("%lld", &X[i]), S[i] = S[i - 1] ^ X[i];
    for(int i = 0; i <= n; i++) hsh[min(S[i], tot - S[i])]++;
    int ans = n * (n + 1) / 2;
    for(map <int, int>::iterator it = hsh.begin(); it != hsh.end(); it++) {
        int v = it -> second;
        ans -= (v / 2) * (v / 2 - 1) / 2 + (v - v / 2) * (v - v / 2 - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}