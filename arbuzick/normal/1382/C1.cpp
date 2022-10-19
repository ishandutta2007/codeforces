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
        string a, b;
        cin >> a >> b;
        int k = 0;
        for(int i = 0; i < n; ++i)
            if(a[i] != b[i])
                k += 3;
        cout << k << '\n';
        for(int i = 0; i < n; ++i)
            if(a[i] != b[i])
                cout << i+1 << ' ' << 1 << ' ' << i+1 << ' ';
        cout << '\n';
    }
}