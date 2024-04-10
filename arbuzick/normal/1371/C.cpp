#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        int k = min(a, b);
        if(k < m)
            cout << "NO\n";
        else if(a+b < n+m)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}