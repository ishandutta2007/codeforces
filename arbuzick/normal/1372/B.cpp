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
        int ans = n-1;
        for(int i = 2; i*i <= n; ++i)
            if(n%i == 0)
                ans = min(ans, n/i*(i-1));
        cout << n-ans << ' ' << ans << '\n';
    }
    return 0;
}