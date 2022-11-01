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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, cnt[10], tf;
string S, ans;
bool flag;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> S;
		n = SZ(S), S = '.' + S;
		if (n % 2){
			for (int i = 0; i < n - 1; ++ i)
				cout << 9;
			cout << endl;
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++ i)
			++ cnt[S[i] - '0'];
		tf = 0;
		for (int i = 0; i < 10; ++ i)
			tf += cnt[i] % 2;
		flag = false;
		for (int i = n; i >= 1; -- i){
			tf -= cnt[S[i] - '0'] % 2;
			-- cnt[S[i] - '0'];
			tf += cnt[S[i] - '0'] % 2;
			for (int j = S[i] - '0' - 1; j >= 0; -- j){
				if (i == 1 && !j)
					continue;
				tf -= cnt[j] % 2;
				++ cnt[j];
				tf += cnt[j] % 2;
				if (n - i < tf || flag){
					tf -= cnt[j] % 2;
					-- cnt[j];
					tf += cnt[j] % 2;
					continue;
				}
				flag = true;
				for (int k = 1; k < i; ++ k)
					cout << S[k];
				cout << j;
				for (int k = 0; k < n - i - tf; ++ k)
					cout << 9;
				for (int k = 9; k >= 0; -- k)
					if (cnt[k] % 2)
						cout << k;
				cout << endl;
			}
		}
		if (flag)
			continue;
		for (int i = 0; i < n - 2; ++ i)
			cout << 9;
		cout << endl;
	}

	return 0;
}