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
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> ans(n);
        ans[n-1] = 1;
        for(int i = n-2; i >= 0; --i){
            if(a[i] == 1)
                ans[i] = 3-ans[i+1];
            else
                ans[i] = 1;
        }
        if(ans[0] == 1)
            cout << "First\n";
        else
            cout << "Second\n";
    }
}