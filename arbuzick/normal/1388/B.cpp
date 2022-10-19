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
        vector<int> ans(n);
        int k = (n-1)/4+1;
        for(int i = 0; i < k; ++i)
            ans[n-i-1] = 8;
        for(int i = k; i < n; ++i)
            ans[n-i-1] = 9;
        for(int i = 0; i < n; ++i)
            cout << ans[i];
        cout << '\n';
    }
    return 0;
}