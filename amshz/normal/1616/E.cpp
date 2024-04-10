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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, pt[26], fen[xn];
ll ans, res;
string S, T;
vector <int> vec[26];

void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] += val;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res += fen[pos];
	return res;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> S >> T;
		S = '.' + S;
		T = '.' + T;
		ans = INF, res = 0;
		for (int i = 0; i < 26; ++ i)
			vec[i].clear();
		for (int i = 1; i <= n; ++ i)
			vec[S[i] - 'a'].push_back(i);
		fill(pt, pt + 26, 0);
		for (int i = 1; i <= n; ++ i){
			for (int c = 0; c < T[i] - 'a'; ++ c)
				if (pt[c] < SZ(vec[c]))
					ans = min(ans, res + vec[c][pt[c]] - 1 - gefen(vec[c][pt[c]]));
			int c = T[i] - 'a';
			if (pt[c] == SZ(vec[c]))
				break;
			res += vec[c][pt[c]] - 1 - gefen(vec[c][pt[c]]);
			mofen(vec[c][pt[c] ++], 1);
		}
		fill(pt, pt + 26, 0);
		for (int i = 1; i <= n; ++ i){
			int c = T[i] - 'a';
			if (pt[c] == SZ(vec[c]))
				break;
			mofen(vec[c][pt[c] ++], - 1);
		}
		if (ans == INF)
			ans = - 1;
		cout << ans << endl;
	}

	return 0;
}