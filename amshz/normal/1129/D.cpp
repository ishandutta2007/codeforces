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
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, a[xn], c[xn], lazy[xn], dp[xn];
int last[xn], f[xn], part[sq][xn];
bool mark[sq];

void update(int l, int r, int val){
	for (int i = l; i < r;){
		int id = i / sq;
		if (i % sq == 0 && i + sq <= r){
			lazy[id] += val;
			i += sq;
		}
		else{
			if (mark[id]){
				if (val == 1)
					part[id][c[i]] = (ll(part[id][c[i]]) - ll(dp[i]) + ll(mod)) % mod;
				else
					part[id][c[i] - 1] = (ll(part[id][c[i] - 1]) + ll(dp[i])) % mod;
			}
			c[i] += val;
			++ i;
		}
	}
}
int get(int l, int r){
	int ans = 0;
	for (int i = l; i < r;){
		int id = i / sq;
		if (i % sq == 0 && i + sq <= r){
			if (lazy[id] <= k)
				ans = (ll(ans) + ll(part[id][k - lazy[id]])) % mod;
			i += sq;
		}
		else{
			if (c[i] + lazy[id] <= k)
				ans = (ll(ans) + ll(dp[i])) % mod;
			++ i;
		}
	}
	return ans;
}
void build(int id){
	mark[id] = true;
	for (int i = id * sq; i < id * sq + sq; ++ i)
		part[id][c[i]] = (ll(part[id][c[i]]) + ll(dp[i])) % mod;
	for (int i = 1; i <= n; ++ i)
		part[id][i] = (ll(part[id][i]) + ll(part[id][i - 1])) % mod;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		last[i] = f[a[i]];
		f[a[i]] = i;
		update(last[last[i]], last[i], - 1);
		update(last[i], i, 1);
		dp[i] = get(0, i);
		if (i % sq == sq - 1)
			build(i / sq);
	}
	cout << dp[n] << endl;
	
	return 0;
}