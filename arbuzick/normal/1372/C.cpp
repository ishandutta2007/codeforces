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
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        bool f = 1;
        for(int i = 0; i < n; ++i)
            f = f&(i+1 == a[i]);
        if(f){
            cout << 0 << '\n';
            continue;
        }
        int f1 = n, f2 = -1;
        for(int i = 0; i < n; ++i)
            if(a[i] != i+1)
                f1 = min(i, f1), f2 = max(f2, i);
        for(int i = f1+1; i < f2; ++i)
            if(a[i] == i+1)
                f = 1;
        if(f)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }
    return 0;
}