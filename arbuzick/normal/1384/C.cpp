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
        string a, b;
        cin >> a >> b;
        vector<vector<bool>> c(26, vector<bool>(26));
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] > b[i])
                ans = -1;
            c[a[i]-'a'][b[i]-'a'] = 1;
        }
        if(ans == -1){
            cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < 26; ++i){
            int m = -1;
            for(int j = i+1; j < 26; ++j)
                if(c[i][j] && m == -1)
                    m = j;
            if(m == -1)
                continue;
            ans++;
            for(int j = i+1; j < 26; ++j)
                c[m][j] = c[m][j]||c[i][j];
        }
        cout << ans << '\n';
    }
    return 0;
}