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
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if((a1 == a2 && b1+b2 == a1) || (a1 == b2 && b1+a2 == a1)|| (b1 == a2 && a1+b2 == b1) || (b1 == b2 && a1+a2 == b1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}