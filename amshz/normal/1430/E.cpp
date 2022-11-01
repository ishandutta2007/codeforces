# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll n, ans, a[xn], b[xn], seg[2][xn << 2];
string s;
vector <int> adj[xn];

void modify(int id, int l, int r, int pos, int ind){
	if (r - l == 1){
		++ seg[ind][id];
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, ind);
	else modify(id << 1 | 1, mid, r, pos, ind);
	seg[ind][id] = seg[ind][id << 1] + seg[ind][id << 1 | 1];
}
int get(int id, int l, int r, int ql, int qr, int ind){
	if (qr <= l || r <= ql) return 0;
	if (ql <= l && r <= qr) return seg[ind][id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr, ind) + get(id << 1 | 1, mid, r, ql, qr, ind);
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> s;
	s = '.' + s;
	for (int i = 1; i <= n; ++ i)
		adj[s[i] - 'a'].push_back(i);
	for (int i = 0; i < 26; ++ i){
		int m = adj[i].size();
		for (int j = 0; j < m; ++ j)
			a[adj[i][j]] = adj[i][m - j - 1];
	}
	for (int i = 1; i <= n; ++ i)
		ans += abs(n - i + 1 - a[i]), b[a[i]] = n - i + 1;
	for (int i = 1; i <= n; ++ i){
		bool f = (b[i] > i);
		ans += get(1, 1, n + 1, b[i] + 1, n + 1, f);
		ans -= get(1, 1, n + 1, b[i] + 1, n + 1, !f);
		modify(1, 1, n + 1, b[i], f);
	}
	cout << ans << endl;
 
    return 0;
}