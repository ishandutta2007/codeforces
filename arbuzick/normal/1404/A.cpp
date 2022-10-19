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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<vector<bool>> used(k, vector<bool>(2));
        for(int i = 0; i < n; ++i)
            if(s[i] != '?')
                used[i%k][s[i]-'0'] = 1;
        bool ans = 1;
        for(int i = 0; i < k; ++i)
            if(used[i][0] && used[i][1])
                ans = 0;
        vector<int> s1(2);
        for(int i = 0; i < k; ++i)
            s1[0] += used[i][0], s1[1] += used[i][1];
        if(s1[0] > k/2 || s1[1] > k/2)
            ans = 0;
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}