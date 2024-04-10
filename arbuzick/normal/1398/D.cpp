#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int dp[201][201][201];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> r1(r), g1(g), b1(b);
    for(int i = 0; i < r; ++i)
        cin >> r1[i];
    for(int i = 0; i < g; ++i)
        cin >> g1[i];
    for(int i = 0; i < b; ++i)
        cin >> b1[i];
    sort(rll(r1));
    sort(rll(g1));
    sort(rll(b1));
    for(int i1 = 0; i1 <= r; ++i1){
        for(int i2 = 0; i2 <= g; ++i2){
            for(int i3 = 0; i3 <= b; ++i3){
                if(i1 == 0 && i2 == 0 && i3 == 0)
                    continue;
                if(i1 > 0)
                    dp[i1][i2][i3] = dp[i1-1][i2][i3];
                if(i2 > 0)
                    dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1][i2-1][i3]);
                if(i3 > 0)
                    dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1][i2][i3-1]);
                if(i1 > 0 && i2 > 0)
                    dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1-1][i2-1][i3]+r1[i1-1]*g1[i2-1]);
                if(i1 > 0 && i3 > 0)
                    dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1-1][i2][i3-1]+r1[i1-1]*b1[i3-1]);
                if(i2 > 0 && i3 > 0)
                    dp[i1][i2][i3] = max(dp[i1][i2][i3], dp[i1][i2-1][i3-1]+g1[i2-1]*b1[i3-1]);
            }
        }
    }
    cout << dp[r][g][b];
    return 0;
}