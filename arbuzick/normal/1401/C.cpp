#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
        int m = 1000000000;
        for(int i = 0; i < n; ++i)
            cin >> a[i], m = min(m, a[i]);
        vector<int> b = a;
        sort(all(b));
        bool ans = 1;
        for(int i = 0; i < n; ++i)
            if(a[i] != b[i] && a[i]%m != 0)
                ans = 0;
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}