#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
void solve(){
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.size();
    vector<int> ans(n, 1);
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            if(i-x >= 0)
                ans[i-x] = 0;
            if(i+x < n)
                ans[i+x] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if((i-x < 0 || ans[i-x] == 0) && (i+x >= n || ans[i+x] == 0)){
                cout << -1 << '\n';
                return;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i];
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}