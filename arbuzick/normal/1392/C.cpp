#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
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
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0 || a[i] >= a[i-1])
                continue;
            else
                ans += a[i-1]-a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}