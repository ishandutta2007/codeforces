// khodaya khodet komak kon
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

ll power(ll a, ll b, ll md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}

const int xn = 3e5 + 10;
const int xm = 60;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, q, a[xn], fen[xm][xn];
map <int, ll> mp;
mt19937 rd(time(0));

ll get_rnd(int x){
	if (mp[x])
		return mp[x];
	ll y = rd() % mod;
	y = power(y, 42, mod);
	y *= y;
	return mp[x] = y;
}
void mofen(int id, int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[id][pos] += val;
}
int gefen(int id, int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res += fen[id][pos];
	return res;
}

int main(){
	fast_io;
	srand(time(NULL));

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		ll x = get_rnd(a[i]);
		for (int bit = 0; bit < xm; ++ bit)
			if ((x & (1ll << bit)))
				mofen(bit, i, 1);
	}
	while (q --){
		int t, l, r, k, ind, x;
		cin >> t;
		if (t == 1){
			cin >> ind >> x;
			ll y = get_rnd(a[ind]);
			for (int bit = 0; bit < xm; ++ bit)
				if ((y & (1ll << bit)))
					mofen(bit, ind, - 1);
			a[ind] = x;
			y = get_rnd(a[ind]);
			for (int bit = 0; bit < xm; ++ bit)
				if ((y & (1ll << bit)))
					mofen(bit, ind, 1);
		}
		else{
			cin >> l >> r >> k;
			bool flag = true;
			for (int bit = 0; bit < xm; ++ bit)
				flag &= (gefen(bit, r) % k == gefen(bit, l - 1) % k);
			if (flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}