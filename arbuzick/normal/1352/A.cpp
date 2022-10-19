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
        vector<int> ans;
        int k = 1;
        while(n > 0){
            if(n%10 == 0){
                n /= 10;
                k *= 10;
                continue;
            }
            ans.pb(n%10*k);
            n /= 10;
            k *= 10;
        }
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}