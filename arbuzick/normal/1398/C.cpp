#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
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
        string s;
        cin >> s;
        vector<int> a(2*n*9+1, 0);
        a[0+n*9]++;
        int k = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            k += s[i]-'0';
            ans += a[k-i-1+9*n];
            a[k-i-1+9*n]++;
        }
        cout << ans << '\n';
    }
    return 0;
}