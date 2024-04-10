#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b;
    for(int i = 0; i < n; i += 2)
        b.pb(a[i]);
    for(int i = 1; i < n; i += 2)
        b.pb(a[i]);
    for(int i = 0; i < n; i += 2)
        b.pb(a[i]);
    int s = 0;
    for(int i = 0; i < (n+1)/2; ++i)
        s += b[i];
    int ans = s;
    for(int i = (n+1)/2; i < b.size(); ++i){
        s -= b[i-(n+1)/2];
        s += b[i];
        ans = max(ans, s);
    }
    cout << ans;
    return 0;
}