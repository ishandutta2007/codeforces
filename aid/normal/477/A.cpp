#include <iostream>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int p = ((((long long)(a + 1) * a / 2) % MOD) * b + a) % MOD;
    int ans = 0;
    for(int i = 1; i < b; i++)
        ans = (ans + (long long)i * p) % MOD;
    cout << ans << '\n';
    return 0;
}