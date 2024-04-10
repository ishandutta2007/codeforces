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
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        vector<int> b(n+1);
        for(int i = 0; i < n; ++i){
            if(s[i] == '0')
                b[i+1] = b[i]+1;
            else
                b[i+1] = b[i]-1;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(ans == -1)
                break;
            if(b[n] == 0 && b[i] == x)
                ans = -1;
            else if(b[n] != 0 && (x-b[i])%b[n] == 0 && (x-b[i])/b[n] >= 0)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}