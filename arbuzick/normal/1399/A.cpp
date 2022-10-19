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
        sort(a.begin(), a.end());
        int m = 0;
        for(int i = 1; i < n; ++i)
            m = max(m, a[i]-a[i-1]);
        if(m > 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}