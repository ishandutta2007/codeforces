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
        vector<int> used(26);
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); ++j)
                used[s[j]-'a']++;
        }
        bool ans = 1;
        for(int i = 0; i < 26; ++i)
            ans = ans&(used[i]%n == 0);
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}