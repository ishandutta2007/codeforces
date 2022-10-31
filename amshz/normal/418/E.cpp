// khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
 
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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 500;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, q, a[xn], last[xn], ans[xn];
int c[xn], cnt[xn], ptr, fen[xn];
pip b[xn];
unordered_map <int, int> mp;
vector <int> query[xn], compress;
 
void modify(int pos, int x){ for (; pos < xn; pos += pos & -pos) fen[pos] += x;}
int get(int pos){
	int sum = 0;
	for (; pos > 0; pos -= pos & -pos) sum += fen[pos];
	return sum;
}
void add(int x, int y){
	modify(cnt[x] + 1, - 1);
	cnt[x] += y;
	modify(cnt[x] + 1, 1);
}
void solve(int l){
	for (int i = 1; i <= n; ++ i){
		add(a[i], 1);
		for (int ind : query[i]){
			for (int j = l; j < ind; ++ j){
				if (b[j].A == 2 || b[j].B.B > i)
					continue;
				last[j] = a[b[j].B.B];
				add(last[j], - 1);
				a[b[j].B.B] = b[j].B.A;
				add(b[j].B.A, 1);
			}
			if (b[ind].B.A == 1)
				ans[ind] = c[a[i]];
			else if (b[ind].B.A % 2 == 0)
				ans[ind] = cnt[a[i]];
			else
				ans[ind] = ptr - get(cnt[a[i]]);
			for (int j = ind - 1; j >= l; -- j){
				if (b[j].A == 2 || b[j].B.B > i)
					continue;
				add(a[b[j].B.B], - 1);
				a[b[j].B.B] = last[j];
				add(last[j], 1);
			}
		}
		query[i].clear();
	}
	for (int i = 1; i <= n; ++ i)
		add(a[i], - 1);
	for (int i = l; i < min(q + 1, l + sq); ++ i)
		if (b[i].A == 1)
			a[b[i].B.B] = b[i].B.A;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], compress.push_back(a[i]);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		cin >> b[i].A >> b[i].B.A >> b[i].B.B;
		if (b[i].A == 1)
			compress.push_back(b[i].B.A);
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		if (i && compress[i] == compress[i - 1])
			continue;
		mp[compress[i]] = ++ ptr;
		c[ptr] = compress[i];
	}
	for (int i = 1; i <= n; ++ i)
		a[i] = mp[a[i]];
	for (int i = 1; i <= q; ++ i)
		if (b[i].A == 1)
			b[i].B.A = mp[b[i].B.A];
	modify(1, ptr);
	for (int i = 1; i <= q; ++ i){
		if (b[i].A == 2)
			query[b[i].B.B].push_back(i);
		if (i % sq == 0)	
			solve(i - sq + 1);
	}
	if (q % sq)
		solve(q - q % sq + 1);
	for (int i = 1; i <= q; ++ i)
		if (b[i].A == 2)
			cout << ans[i] << endl;
	
	return 0;
}