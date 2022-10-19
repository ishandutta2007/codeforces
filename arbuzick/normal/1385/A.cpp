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
        vector<int> a(3);
        for(int i = 0; i < 3; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        if(a[2] != a[1])
            cout << "NO\n";
        else
            cout << "YES\n" << a[0] << ' ' << a[2] << ' ' << 1 << '\n';
    }
    return 0;
}