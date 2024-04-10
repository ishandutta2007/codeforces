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

int n, q, seg[xn << 2][3][3];
string S;

void build(int id, int l, int r){
	if (r - l == 1){
		int c = S[l - 1] - 'a';
		seg[id][c][c] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	for (int l = 0; l < 3; ++ l)
		for (int r = l; r < 3; ++ r)
			seg[id][l][r] = inf;
	for (int l = 0; l < 3; ++ l)
		for (int md = l; md < 3; ++ md)
			for (int r = md; r < 3; ++ r)
				seg[id][l][r] = min(seg[id][l][r], seg[lc][l][md] + seg[rc][md][r]);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		for (int l = 0; l < 3; ++ l)
			for (int r = l; r < 3; ++ r)
				seg[id][l][r] = 0;
		seg[id][val][val] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	for (int l = 0; l < 3; ++ l)
		for (int r = l; r < 3; ++ r)
			seg[id][l][r] = inf;
	for (int l = 0; l < 3; ++ l)
		for (int md = l; md < 3; ++ md)
			for (int r = md; r < 3; ++ r)
				seg[id][l][r] = min(seg[id][l][r], seg[lc][l][md] + seg[rc][md][r]);
}

int main(){
	fast_io;

	cin >> n >> q >> S;
	build(1, 1, n + 1);
	while (q --){
		int x;
		char c;
		cin >> x >> c;
		modify(1, 1, n + 1, x, c - 'a');
		cout << seg[1][0][2] << endl;
	}

	return 0;
}