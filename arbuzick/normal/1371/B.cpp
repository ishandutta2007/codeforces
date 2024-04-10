#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        int ans;
        if(r >= n)
            ans = 1;
        else
            ans = 0;
        ans = ans+(1+min(n-1, r))*min(n-1, r)/2;
        cout << ans << "\n";
    }
    return 0;
}