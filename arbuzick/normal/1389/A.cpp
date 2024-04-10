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
        int l, r;
        cin >> l >> r;
        if(r < l*2)
            cout << -1 << ' ' << -1 << '\n';
        else
            cout << l << ' ' << l*2 << '\n';
    }
}