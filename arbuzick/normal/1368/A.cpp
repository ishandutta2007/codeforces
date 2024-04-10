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
        int a, b, n;
        cin >> a >> b >> n;
        if(a > b)
            swap(a, b);
        int ans = 0;
        while(b <= n){
            ans++;
            a += b;
            swap(a, b);
        }
        cout << ans << '\n';
    }
    return 0;
}