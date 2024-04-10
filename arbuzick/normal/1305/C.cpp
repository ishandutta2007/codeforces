#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n > m){
        cout << 0;
        return 0;
    }
    int ans = 1;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
            ans *= abs(a[i]-a[j]), ans %= m;
    cout << ans;
    return 0;
}