#include<bits/stdc++.h>

using namespace std;

#define int long long
int p[250005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    p[0] = 1, p[1] = 1;
    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] * i % m;
    for (int i = 1; i <= n; ++i) {
        int cnt = (n - i + 1) * (n - i + 1) % m;
        ans = (ans + cnt * p[n - i] % m * p[i]) % m;
    }
    cout << ans % m;
    return 0;
}