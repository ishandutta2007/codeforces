#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
struct c{
    int r, g, b;
    c(){
        r = g = b = 0;
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<c> dp(n+1);
    for(int i = 0; i < n; ++i){
        dp[i+1].r = min(dp[i].g, dp[i].b)+1;
        dp[i+1].g = min(dp[i].r, dp[i].b)+1;
        dp[i+1].b = min(dp[i].r, dp[i].g)+1;
        if(s[i] == 'R')
            dp[i+1].r--;
        else if(s[i] == 'G')
            dp[i+1].g--;
        else
            dp[i+1].b--;
    }
    cout << min(dp[n].r, min(dp[n].g, dp[n].b)) << '\n';
    char c;
    if(dp[n].r <= dp[n].g && dp[n].r <= dp[n].b)
        c = 'R';
    else if(dp[n].g <= dp[n].b)
        c = 'G';
    else
        c = 'B';
    string ans = "";
    for(int i = n; i > 0; --i){
        ans += c;
        if(c == 'R'){
            if(dp[i-1].g <= dp[i-1].b)
                c = 'G';
            else
                c = 'B';
        }else if(c == 'G'){
            if(dp[i-1].r <= dp[i-1].b)
                c = 'R';
            else
                c = 'B';
        }else{
            if(dp[i-1].r <= dp[i-1].g)
                c = 'R';
            else
                c = 'G';
        }
    }
    reverse(all(ans));
    cout << ans;
    return 0;
}