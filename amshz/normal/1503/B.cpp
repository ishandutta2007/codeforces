// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
# define A                                               first
# define B                                               second
//# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 100 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, cnt[3], qq;
queue <pii> q[2];

void solve(int id, int c){
	pii x = q[id].front();
	q[id].pop();
	cout << c + 1 << sep << x.A << sep << x.B << endl;
	-- cnt[id];
}

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			++ cnt[(i + j) % 2], q[(i + j) % 2].push({i, j});
	qq = n * n;
	while (qq --){
		int c;
		cin >> c;
		-- c;
		if (c == 2){
			if (cnt[0])
				solve(0, 0);
			else
				solve(1, 1);
		}
		else if (c == 1){
			if (cnt[0])
				solve(0, 0);
			else
				solve(1, 2);
		}
		else{
			if (cnt[1])
				solve(1, 1);
			else
				solve(0, 2);
		}
	}
			
	return 0;
}