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
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> pr(n+1);
        for(int i = 0; i < n; ++i)
            pr[i+1] = pr[i]+a[i];
        int ans = pr[k+1];
        for(int i = 1; i < k; ++i){
            int ans1;
            if(i+z*2 <= k){
                ans1 = pr[i+(k-(i+z*2))+1];
                ans1 = ans1+a[i-1]*z+a[i]*z;
            }else{
                int k1 = k-i;
                ans1 = pr[i+1]+a[i-1]*((k1+1)/2)+a[i]*(k1/2);
            }
            ans = max(ans, ans1);
        }
        cout << ans << '\n';
    }
}