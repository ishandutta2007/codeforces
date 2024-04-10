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

int n, a[xn], dp[2][xn], ptr, seg[xn << 2], ans;
vector <int> cprs;
unordered_map <int, int> mp;

void modify(int id, int l, int r, int pos, int val){
	seg[id] = max(seg[id], val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], a[i] -= i, cprs.push_back(a[i]);
	sort(all(cprs));
	for (int i = 0; i < SZ(cprs); ++ i){
		if (i && cprs[i] == cprs[i - 1])
			continue;
		mp[cprs[i]] = ptr ++;
	}
	for (int i = 1; i <= n; ++ i){
		dp[0][i] = get(1, 0, ptr, 0, mp[a[i]] + 1) + 1;
		modify(1, 0, ptr, mp[a[i]], dp[0][i]);
		ans = max(ans, min(n, dp[0][i] + 1));
	}
	memset(seg, 0, sizeof seg);
	for (int i = n; i >= 1; -- i){
		dp[1][i] = get(1, 0, ptr, mp[a[i]], ptr) + 1;
		modify(1, 0, ptr, mp[a[i]], dp[1][i]);
	}
	mp.clear();
	for (int i = n - 1; i >= 1; -- i){
		int ind = mp[a[i] - 1];
		if (ind)
			ans = max(ans, dp[0][i] + 1 + dp[1][ind]);
		mp[a[i + 1]] = i + 1;
	}
	cout << n - ans << endl;

	return 0;
}