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
        int n, m;
        cin >> n >> m;
        if(n == 1)
            cout << 0 << '\n';
        else if(n == 2)
            cout << m << '\n';
        else
            cout << m*2 << '\n';
    }
    return 0;
}