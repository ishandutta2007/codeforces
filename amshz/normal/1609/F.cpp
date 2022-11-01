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

const int xn = 1e6 + 10;
const int xm = 60;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], cmx[2][xm], cmn[2][xm], ptr[2];
ll b[xn], ans, ps[xn];
pll MN[2], MX[2];

void build(int id, int l, int r){
	if (r - l == 1){
		++ ans;
		return;
	}
	int mid = l + r >> 1;
	ptr[0] = ptr[1] = mid - 1;
	memset(cmx, 0, sizeof cmx);
	memset(cmn, 0, sizeof cmn);
	pll mn = {INF, 0}, mx = {- INF, 0};
	ps[mid - 1] = 0;
	for (int i = mid; i < r; ++ i){
		ps[i] = ps[i - 1];
		if (b[i] < mn.A)
			mn = {b[i], a[i]};
		if (mx.A < b[i])
			mx = {b[i], a[i]};
		if (mn.B == mx.B)
			++ ps[i];
	}
	mn = {INF, 0}, mx = {- INF, 0};
	MN[0] = MN[1] = {INF, 0};
	MX[0] = MX[1] = {- INF, 0};
	for (int i = mid - 1; l <= i; -- i){
		if (b[i] < mn.A)
			mn = {b[i], a[i]};
		if (mx.A < b[i])
			mx = {b[i], a[i]};
		while (ptr[0] + 1 < r && mn.A <= b[ptr[0] + 1]){
			++ ptr[0];
			if (b[ptr[0]] < MN[0].A)
				MN[0] = {b[ptr[0]], a[ptr[0]]};
			if (MX[0].A < b[ptr[0]])
				MX[0] = {b[ptr[0]], a[ptr[0]]};
			++ cmx[0][MX[0].B];
			++ cmn[0][MN[0].B];
		}
		while (ptr[1] + 1 < r && b[ptr[1] + 1] <= mx.A){
			++ ptr[1];
			if (b[ptr[1]] < MN[1].A)
				MN[1] = {b[ptr[1]], a[ptr[1]]};
			if (MX[1].A < b[ptr[1]])
				MX[1] = {b[ptr[1]], a[ptr[1]]};
			++ cmx[1][MX[1].B];
			++ cmn[1][MN[1].B];
		}
		if (mn.B == mx.B)
			ans += min(ptr[0], ptr[1]) - mid + 1;
		if (ptr[0] < ptr[1])
			ans += cmn[1][mx.B] - cmn[0][mx.B];
		else
			ans += cmx[0][mn.B] - cmx[1][mn.B];
		ans += ps[r - 1] - ps[max(ptr[0], ptr[1])];
	}
	build(lc, l, mid);
	build(rc, mid, r);
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> b[i];
		for (int bit = 0; bit < 60; ++ bit)
			if ((b[i] & (1ll << bit)))
				++ a[i];
	}
	build(1, 1, n + 1);
	cout << ans << endl;

	return 0;
}