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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nxt0(n+1), nxt1(n+1);
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '?')
            nxt0[i] = nxt0[i+1]+1, nxt1[i] = nxt1[i+1]+1;
        else if(s[i] == '0')
            nxt0[i] = nxt0[i+1]+1, nxt1[i] = 0;
        else
            nxt0[i] = 0, nxt1[i] = nxt1[i+1]+1;
    }
    vector<vector<int>> n0(n+1), n1(n+1);
    for(int i = 0; i < n; ++i){
        if(i == 0 || s[i-1] == '1')
            for(int j = 0; j <= nxt0[i]; ++j)
                n0[j].pb(i);
        if(i == 0 || s[i-1] == '0')
            for(int j = 0; j <= nxt1[i]; ++j)
                n1[j].pb(i);
    }
    for(int i = 1; i <= n; ++i)
        n0[i].pb(n), n1[i].pb(n);
    vector<int> ans(n+1);
    for(int i = 1; i <= n; ++i){
        int j = 0;
        while(j < n){
            if(nxt1[j] >= i || nxt0[j] >= i){
                ans[i]++;
                j += i;
                continue;
            }
            int a = n1[i][lower_bound(n1[i].begin(), n1[i].end(), j)-n1[i].begin()];
            int b = n0[i][lower_bound(n0[i].begin(), n0[i].end(), j)-n0[i].begin()];
            j = min(a, b);
        }
        cout << ans[i] << ' ';
    }
    return 0;
}