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
        string s;
        cin >> s;
        int n = s.size();
        int ans = n;
        for(int j = 0; j < 10; ++j){
            int k = 0;
            for(int i = 0; i < n; ++i)
                if(s[i]-'0' == j)
                    k++;
            ans = min(ans, n-k);
        }
        for(int j1 = 0; j1 < 10; ++j1){
            for(int j2 = 0; j2 < 10; ++j2){
                int k = 0;
                for(int i = 0; i < n; ++i){
                    if(s[i]-'0' == j1 && k%2 == 0)
                        k++;
                    else if(s[i]-'0' == j2 && k%2 == 1)
                        k++;
                }
                ans = min(ans, n-k/2*2);
            }
        }
        cout << ans << '\n';
    }
}