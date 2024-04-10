#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const int mod = 1e9 + 7, N = 1 << 10;
lli dp[N];
vector <int> input;

int main () {
    int n;
    cin >> n;
    input.resize(n);
    fop (i,0,n) cin >> input[i], input[i]--;
    lli ans = 0;
    fop (i,0,n) {
        if (input[i] == i) dp[i] = 2;
        else {
            dp[i] = 2;
            fop (_,input[i],i) dp[i] = (dp[i] + dp[_]) % mod;
        }
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << '\n';
}