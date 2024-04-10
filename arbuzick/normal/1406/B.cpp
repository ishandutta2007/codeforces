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
        vector<int> a, b;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            if(x > 0)
                a.pb(x);
            if(x < 0)
                b.pb(x);
        }
        sort(rall(a));
        sort(all(b));
        if(a.size()+b.size() < 5){
            cout << 0 << '\n';
            continue;
        }
        if(a.size()+b.size() == 5){
            int ans = 1;
            for(int i = 0; i < a.size(); ++i)
                ans *= a[i];
            for(int i = 0; i < b.size(); ++i)
                ans *= b[i];
            if(a.size()+b.size() < n)
                ans = max(ans, 0LL);
            cout << ans << '\n';
            continue;
        }
        if(a.size() == 0){
            reverse(all(b));
            int ans = 1;
            for(int i = 0; i < 5; ++i)
                ans *= b[i];
            if(b.size() < n)
                ans = 0;
            cout << ans << '\n';
            continue;
        }
        int ans = 0;
        for(int i = max(0LL, 5-(int)b.size()); i <= min(5LL, (int)a.size()); ++i){
            int ans1 = 1;
            for(int j = 0; j < i; ++j)
                ans1 *= a[j];
            for(int j = 0; j < 5-i; ++j)
                ans1 *= b[j];
            ans = max(ans, ans1);
        }
        cout << ans << '\n';
    }
    return 0;
}