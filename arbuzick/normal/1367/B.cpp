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
        int n;
        cin >> n;
        vector<int> a(n);
        int a1 = 0, a2 = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(i%2 == 0 && a[i]%2 == 1)
                a1++;
            if(i%2 == 1 && a[i]%2 == 0)
                a2++;
        }
        if(a1 != a2)
            cout << -1 << '\n';
        else
            cout << a1 << '\n';
    }
    return 0;
}