#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
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
        string s;
        cin >> s;
        set<char> s1;
        for(int i = 0; i < n; ++i)
            s1.insert(s[i]);
        if(s1.size() == 1){
            cout << (n-1)/3+1 << '\n';
            continue;
        }
        string a = "";
        int ind = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] != s[(i-1+n)%n])
                ind = i;
        for(int i = ind; i < n; ++i)
            a += s[i];
        for(int i = 0; i < ind; ++i)
            a += s[i];
        s = a;
        vector<int> l;
        int k = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0 || s[i] != s[i-1]){
                if(k > 0)
                    l.pb(k);
                k = 0;
            }
            k++;
        }
        l.pb(k);
        int ans = 0;
        for(int i = 0; i < l.size(); ++i)
            ans += l[i]/3;
        cout << ans << '\n';
    }
    return 0;
}