#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
ll dp[N][3];
main(){
    FAST;
    string s;
    cin >> s;
    dp[0][0] = dp[0][2] = (s[0] == 'a' ? 1 : 0);
    dp[0][1] = (s[0] == 'b' ? 1 : 0);
    for(ll i =1;i<(ll)s.length();i++){
    	dp[i][0] = dp[i-1][0] + (s[i] == 'a' ? 1 : 0);
    	if(s[i] == 'b') dp[i][1] = max(dp[i-1][1], dp[i-1][0])+1;
    	else dp[i][1] = dp[i-1][1];
    	if(s[i] == 'a') dp[i][2] = max(dp[i-1][1], dp[i-1][2])+1;
    	else dp[i][2] = dp[i-1][2];
    }
    cout << max(dp[s.length()-1][0], max(dp[s.length()-1][1], dp[s.length()-1][2]));
}