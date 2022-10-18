#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn], pref[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    int L = 1, R = 1;
    set < int > Q = {0};
    while (L <= n) {
        while (R <= n) {
            if (Q.find(pref[R]) != Q.end()) break;
            Q.insert(pref[R++]);
        }
        ans += (R - L);
        Q.erase(pref[L - 1]);
        ++L;
    }
    cout << ans << '\n';
    return 0;
}