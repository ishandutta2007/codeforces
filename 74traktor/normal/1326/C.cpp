#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn];
int mod =  998244353;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0, sum = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n - k + 1; i <= n; ++i) {
        ans += i;
    }
    int lst = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= n - k + 1) {
            if (lst != -1) sum = sum * (i - lst) % mod;
            lst = i;
        }
    }
    cout << ans << " " << sum << '\n';
    return 0;
}