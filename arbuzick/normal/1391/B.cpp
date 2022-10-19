#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for(int j = 0; j < m; ++j)
            if(a[n-1][j] == 'D')
                ans++;
        for(int i = 0; i < n; ++i)
            if(a[i][m-1] == 'R')
                ans++;
        cout << ans << '\n';
    }
    return 0;
}