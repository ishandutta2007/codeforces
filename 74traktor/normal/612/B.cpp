#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 200005;
int pos[maxn];
int a[maxn];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pos[a[i]] = i;
    for (int i = 2; i <= n; ++i) ans += abs(pos[i] - pos[i - 1]);
    cout << ans << '\n';
    return 0;
}