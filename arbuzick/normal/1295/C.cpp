#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        vector<bool> used1(26), used2(26);
        for(int i = 0; i < s.size(); ++i)
            used1[s[i]-'a'] = 1;
        for(int i = 0; i < t.size(); ++i)
            used2[t[i]-'a'] = 1;
        bool f = 0;
        for(int i = 0; i < 26; ++i)
            if(used2[i] && !used1[i])
                f = 1;
        if(f){
            cout << -1 << '\n';
            continue;
        }
        int ans = 1;
        vector<set<int>> used3(26);
        for(int i = 0; i < s.size(); ++i)
            used3[s[i]-'a'].insert(i);
        int ind = -1;
        for(int i = 0; i < t.size(); ++i){
            auto it = used3[t[i]-'a'].upper_bound(ind);
            if(it == used3[t[i]-'a'].end()){
                ans++;
                it = used3[t[i]-'a'].upper_bound(-1);
                ind = *it;
            }else
                ind = *it;
        }
        cout << ans << '\n';
    }
    return 0;
}