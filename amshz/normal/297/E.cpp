//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize ("O2")
# pragma GCC optimize ("unroll-loops")

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

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
const int sq = 300;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
const int SIG = 26;

int n, fen[xn];
pii b[xn];
ppi a[xn];
ll ans, res;

void mofen(int pos){
	for (pos += 5; pos < xn; pos += pos & - pos)
		++ fen[pos];
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res += fen[pos];
	return res;
}

int main(){
	InTheNameOfGod;

	cin >> n;
	ans = 1ll * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i].A.A >> a[i].A.B;
		a[i].B = i;
		if (a[i].A.B < a[i].A.A)
			swap(a[i].A.A, a[i].A.B);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		b[a[i].B].A += gefen(a[i].A.A - 1) + gefen(n + n) - gefen(a[i].A.B);
		mofen(a[i].A.B);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n; i >= 1; -- i){
		b[a[i].B].B += gefen(a[i].A.B - 1);
		mofen(a[i].A.B);
	}
	memset(fen, 0, sizeof fen);
	for (int i = 1; i <= n; ++ i)
		swap(a[i].A.A, a[i].A.B);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		swap(a[i].A.A, a[i].A.B);
	for (int i = n; i >= 1; -- i){
		b[a[i].B].A += gefen(n + n) - gefen(a[i].A.B);
		mofen(a[i].A.A);
	}
	for (int i = 1; i <= n; ++ i){
		ans -= 1ll * b[i].A * b[i].B;
		res += 1ll * (b[i].A + b[i].B) * (n - b[i].A - b[i].B - 1); 
	}
	ans -= res / 2;
	cout << ans << endl;

	return 0;
}