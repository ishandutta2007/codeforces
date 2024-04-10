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

const int xn = 3e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], p[xn], qq;
bool flag;
vector <int> ans;

void upd(int r){
	for (int i = 0; i < r / 2; ++ i){
		swap(a[1 + i], a[r - i]);
		p[a[1 + i]] = 1 + i;
		p[a[r - i]] = r - i;
	}
	ans.push_back(r);
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, flag = false;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], p[a[i]] = i, flag |= (a[i] % 2 != i % 2);
		if (flag){
			cout << - 1 << endl;
			continue;
		}
		ans.clear();
		for (int i = n; 3 <= i; i -= 2){
			upd(p[i]);
			upd(p[i - 1] - 1);
			upd(p[i - 1] + 1);
			upd(3);
			upd(i);
		}
		for (int i = 1; i <= n; ++ i)
			if (a[i] != i)
				kill("FUCK");
		cout << SZ(ans) << endl;
		for (int x : ans)
			cout << x << sep;
		cout << endl;
	}

	return 0;
}