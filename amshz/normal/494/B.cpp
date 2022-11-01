# include <bits/stdc++.h>
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ld, ld>                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md = 1e9 + 7;
const int TM = 2;
const int Base = 257;


int n, f[xn], last[xn];
bool flag[xn];
ll dp[xn], part[xn];
string s, t;

void kmp(string ss){
    for(int i = 1 ; i < SZ(ss); i ++){
        int j = f[i - 1];
        while (j && ss[i] != ss[j])
            j = f[j - 1];
        j += (ss[i] == ss[j]) , f[i] = j;
    }
}

int main(){
    InTheNameOfGod;
    
    cin >> s >> t;
    n = SZ(s);
    s = '.' + s;
    kmp(t + s);
    for (int i = SZ(t) + 1; i <= SZ(t) + n; ++ i)
    	if (f[i] == SZ(t))
    		flag[i - SZ(t) - SZ(t)] = true;
    dp[0] = part[0] = 1;
    last[0] = -1;
    if (flag[0]) last[0] = 0;
    for (int i = 1; i <= n; ++ i){
    	dp[i] = dp[i - 1];
    	last[i] = last[i - 1];
    	if (flag[i])	last[i] = i;
    	if (i >= SZ(t) && last[i - SZ(t)] != -1)
    		dp[i] = (dp[i] + part[last[i - SZ(t)]]) % Md;
    	part[i] = (part[i - 1] + dp[i]) % Md;
	}
    cout << (dp[n] - 1 + Md) % Md << endl;
    
    return 0;
}