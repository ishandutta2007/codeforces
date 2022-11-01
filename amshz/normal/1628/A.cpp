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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], cnt[xn], res, last[xn], ptr;
vector <int> vec, ans;

void add(int x){
	++ cnt[x];
	vec.push_back(x);
	while (cnt[res])
		++ res;
}
void check(){
	ans.push_back(res);
	res = 0;
	for (int x : vec)
		-- cnt[x];
	vec.clear();
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		fill(last, last + n + 5, 0);
		fill(cnt, cnt + n + 5, 0);
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], last[a[i]] = i;
		ptr = res = 0;
		vec.clear(), ans.clear();
		while (ptr < n){
			add(a[++ ptr]);
			if (last[res] <= ptr)
				check();
		}
		cout << SZ(ans) << endl;
		for (int x : ans)
			cout << x << sep;
		cout << endl;
	}

	return 0;
}