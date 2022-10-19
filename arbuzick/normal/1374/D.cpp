#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> b;
        for(int i = 0; i < n; ++i)
            if(a[i]%k != 0)
                b.pb(k - a[i]%k);
        sort(b.begin(), b.end());
        int ans = 0;
        int l = 0;
        for(int i = 0; i < b.size(); ++i){
            if (i == 0||b[i-1] == b[i])
                l++;
            else{
                ans = max(ans, k*(l-1)+b[i-1]);
                l = 1;
            }
        }
        if (b.size() != 0){
            ans = max(ans, k*(l-1)+b.back());
            ans += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}