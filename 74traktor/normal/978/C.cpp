#include <bits/stdc++.h>

using namespace std;

#define int long long

long long a[200005];
long long pref[200005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, mid;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    for (int i = 0; i < m; ++i){
        cin >> x;
        int l = 0, r = n;
        while (r - l > 1){
            mid = (l + r) / 2;
            if (pref[mid] < x)
                l = mid;
            else
                r = mid;
        }
        cout << l + 1 << " " << x - pref[l] << endl;
    }
    return 0;
}