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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a -= b;
        if(a <= 0){
            cout << b << '\n';
            continue;
        }
        if(d >= c)
            cout << -1 << '\n';
        else
            cout << b+((a-1)/(c-d)+1)*c << '\n';
    }
    return 0;
}