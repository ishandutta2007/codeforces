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

int qq, n, a[xn], b[xn], ps[xn], mx, ind, pt1, pt2;
string S;
bool flag;

bool check(int l, int r){
	int sum = 0;
	for (int i = 1; i <= n + n; ++ i)
		b[i] = a[i];
	reverse(b + l, b + r + 1);
	for (int i = 1; i <= n + n; ++ i){
		sum += b[i];
		if (sum < 0)
			return false;
	}
	return true;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> S;
		mx = ind = 0;
		flag = true;
		for (int i = 1; i <= n + n; ++ i){
			if (S[i - 1] == '(')
				a[i] = 1;
			else
				a[i] = - 1;
			ps[i] = ps[i - 1] + a[i];
			if (mx < ps[i])
				ind = i, mx = ps[i];
			flag &= (0 <= ps[i]);
		}
		if (flag){
			cout << 0 << endl;
			continue;
		}
		pt1 = 0;
		pt2 = n + n;
		while (0 <= ps[pt1 + 1])
			++ pt1;
		while (0 <= ps[pt2 - 1])
			-- pt2;
		int MX = 0, id;
		for (int i = 0; i <= pt1; ++ i)
			MX = max(MX, ps[i]);
		for (int i = 0; i <= pt1; ++ i)
			if (ps[i] == MX)
				id = i;
		pt1 = id;
		MX = 0, id;
		for (int i = pt2; i <= n + n; ++ i)
			MX = max(MX, ps[i]);
		for (int i = pt2; i <= n + n; ++ i)
			if (ps[i] == MX)
				id = i;
		pt2 = id;
		if (check(pt1 + 1, pt2)){
			cout << 1 << endl;
			cout << pt1 + 1 << sep << pt2 << endl;
			continue;
		}
		cout << 2 << endl;
		cout << 1 << sep << ind << endl;
		cout << ind + 1 << sep << n + n << endl;
	}

	return 0;
}