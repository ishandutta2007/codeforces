#include<bits/stdc++.h>

using namespace std;

#define inf (ll)1e15
#define ll long long
#define all(x) x.begin(), x.end()
#define x first
#define y second

typedef pair<int, int> Point;

const int mod = (int) 1e9 + 7;
const int mod2 = 998244353;


int main(){

    cin.tie(0);
    cin.sync_with_stdio(0);

    #ifdef Cyborg101
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;

    int n = s.size();

    int dp[3][n + 1];
    memset(dp, 0xff, sizeof dp);

    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    for(int i = 0; i < n; ++i){
    	dp[0][i + 1] = dp[0][i] + (s[i] == 'a'); //max. count of (a)
    	dp[1][i + 1] = max(dp[0][i],  dp[1][i]) + (s[i] == 'b'); //max. count of (a) or (ab) or (b)
    	dp[2][i + 1] = max(dp[1][i], dp[2][i]) + (s[i] == 'a'); //max. count of (a) or (ab) or (b) or (ba) or (aba)
    }

    cout << max({dp[0][n], dp[1][n], dp[2][n]}) << endl;

    return 0;
}