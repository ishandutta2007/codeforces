#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int m1 = 1e9+1, m2 = 1e9+1;
        for(int i = 0; i < n; ++i)
            cin >> a[i], m1 = min(m1, a[i]);
        for(int i = 0; i < n; ++i)
            cin >> b[i], m2 = min(m2, b[i]);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int r1 = a[i]-m1, r2 = b[i]-m2;
            ans += max(r1, r2);
        }
        cout << ans << '\n';
    }
    return 0;
}