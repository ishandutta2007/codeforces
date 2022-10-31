#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Mod = 1000000007;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int ans = 0;
    for (int i = 1; i < B; ++i) {
        int cnt = A;
        ans = (ans + 1LL * i * cnt % Mod + 1LL * cnt * (cnt + 1) / 2 % Mod * B % Mod * i % Mod) % Mod;
    }

    cout << ans << '\n';
}