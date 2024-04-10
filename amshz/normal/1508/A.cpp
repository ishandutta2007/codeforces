// khodaya khodet komak kon
// Maybe on the Moon
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, cnt[2][3], pt1, pt2;
string S[3], ans;

void solve(string x, string y, int f){
	ans = "", pt1 = pt2 = 0;
	while (pt1 < n + n || pt2 < n + n){
		if (pt2 == n + n)
			ans += x[pt1 ++];
		else if (pt1 == n + n)
			ans += y[pt2 ++];
		else if (x[pt1] == y[pt2])
			ans += x[pt1 ++], ++ pt2;
		else if (x[pt1] - '0' != f)
			ans += x[pt1 ++];
		else
			ans += y[pt2 ++];
	}
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < 3; ++ i){
			cin >> S[i];
			cnt[0][i] = cnt[1][i] = 0;
			for (char c : S[i])
				++ cnt[c - '0'][i];
		}
		for (int i = 0; i < 2; ++ i)
			for (int j = 0; j < 3; ++ j)
				for (int k = j + 1; k < 3; ++ k)
					if (cnt[i][j] >= n && cnt[i][k] >= n)
						solve(S[j], S[k], i);
		cout << ans << endl;
	}

	return 0;
}