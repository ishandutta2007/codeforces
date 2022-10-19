#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> a;
        int l = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1')
                l++;
            else{
                if(l > 0)
                    a.pb(l);
                l = 0;
            }
        }
        if(l > 0)
            a.pb(l);
        sort(all(a));
        int ans = 0;
        if(a.size() == 0){
            cout << 0 << '\n';
            continue;
        }
        for(int i = a.size()-1; i >= 0; --i){
            if((a.size()-i)%2 == 1)
                ans += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}