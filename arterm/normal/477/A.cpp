#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define mod 1000000007ll

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    long long a, b;

    cin >> a >> b;

    long long suma = a * (a + 1) / 2;
    long long sumb = b * (b - 1) / 2;

    suma %= mod;
    sumb %= mod;

    long long ans = sumb * suma;
    ans %= mod;
    ans = (ans * b) % mod;
    ans = (ans + a * sumb) % mod;

    cout << ans << "\n";

    return 0;
}