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

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int qq, n, a[xn], b[xn], m, ptr, sum;
vector <int> ans;
vector <pii> ANS;
bool flag;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		if (n % 2){
			cout << - 1 << endl;
			continue;
		}
		m = n;
		ans.clear();
		ANS.clear();
		sum = 0;
		flag = false;
		while (m){
			int ind = 1;
			for (int i = m; 1 < i; -- i)
				if (a[i] == a[1])
					ind = i;
			if (ind == 1){
				flag = true;
				break;
			}
			for (int i = 2; i < ind; ++ i)
				ANS.push_back({sum + ind + i - 2, a[i]});
			ans.push_back(2 * (ind - 1));
			sum += 2 * (ind - 1);
			ptr = 0;
			for (int i = ind - 1; 2 <= i; -- i)
				b[++ ptr] = a[i];
			for (int i = ind + 1; i <= m; ++ i)
				b[++ ptr] = a[i];
			m = 0;
			for (int i = 1; i <= ptr; ++ i)
				a[++ m] = b[i];
		}
		if (flag){
			cout << - 1 << endl;
			continue;
		}
		cout << SZ(ANS) << endl;
		for (pii x : ANS)
			cout << x.A << sep << x.B << endl;
		cout << SZ(ans) << endl;
		for (int x : ans)
			cout << x << sep;
		cout << endl;
	}

	return 0;
}