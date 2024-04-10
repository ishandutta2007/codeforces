//khodaya khodet komak kon
# include <bits/stdc++.h>

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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, a[xn], ptr, dp[xn], fen[xn];
ll ps[xn];
vector <pll> cprs;

void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] = max(fen[pos], val);
}
int gefen(int pos){
	int res = - inf;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res = max(res, fen[pos]);
	return res;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		cprs.clear();
		cprs.push_back({0, 0});
		ps[0] = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
			cprs.push_back({ps[i], i});
		}
		sort(all(cprs));
		ptr = 0;
		for (int i = 0; i < SZ(cprs); ++ i){
			if (i && cprs[i].A != cprs[i - 1].A)
				ptr ++;
			ps[cprs[i].B] = ptr;
		}
		fill(fen, fen + ptr + 10, - inf);
		for (int i = 1; i <= n; ++ i){
			dp[i] = dp[i - 1];
			if (a[i] < 0)
				-- dp[i];
			else if (0 < a[i])
				++ dp[i];
			dp[i] = max(dp[i], gefen(ps[i] - 1) + i);
			mofen(ps[i - 1], dp[i - 1] - (i - 1));
		}
		cout << dp[n] << endl;
	}

	return 0;
}