#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005];
int pref[100005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    double ans = 0;
    for (int kol = 1; kol <= n; ++kol){
        if (n - kol > m) continue;
        int sum = pref[n] - pref[n - kol] + min(m - (n - kol), k * kol);
        ans = max(ans, sum / (double)kol);
    }
    cout << fixed << setprecision(7) << ans << '\n';
    return 0;
}