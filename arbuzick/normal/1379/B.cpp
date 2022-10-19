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
        int l, r, m;
        cin >> l >> r >> m;
        for(int a = l; a <= r; ++a){
            int k1 = m%a, k2 = a-m%a;
            if(m < a)
                k1 = r-l+1;
            if(k1 <= r-l){
                cout << a << ' ' << l+k1 << ' ' << l << '\n';
                break;
            }
            if(k2 <= r-l){
                cout << a << ' ' << l << ' ' << l+k2 << '\n';
                break;
            }
        }
    }
    return 0;
}