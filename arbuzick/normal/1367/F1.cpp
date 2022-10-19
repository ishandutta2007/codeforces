#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
        vector<int> b = a;
        sort(all(b));
        b.resize(unique(all(b))-b.begin());
        for(int i = 0; i < n; ++i)
            a[i] = lower_bound(all(b), a[i])-b.begin()+1;
        vector<int> m(n+1, -1);
        vector<int> pr1(n, -1), pr2(n, -1);
        for(int i = 0; i < n; ++i){
            pr1[i] = m[a[i]];
            pr2[i] = m[a[i]-1];
            m[a[i]] = i;
        }
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i){
            if(pr1[i] != -1)
                dp[i] = dp[pr1[i]]+1;
            if(pr2[i] != -1)
                dp[i] = max(dp[i], dp[pr2[i]]+1);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        cout << n-ans << '\n';
    }
    return 0;
}