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

const int xn = 1.5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, s, k, A[xn], dp[xn][xn], ps[xn], L[xn], pd[xn][xn];
pii a[xn], b[xn];
vector <int> cprs;
deque <int> dq;

int get(int x, int y){
	return dp[x][y] - ps[b[y].B];
}
bool check(int x){
	for (int i = 1; i <= n; ++ i)
		ps[i] = ps[i - 1] + (A[i] <= x), dp[0][i] = - inf;
	for (int j = 1; j <= m; ++ j){
		dq.clear(), dp[j][0] = pd[j][0] = - inf;
		for (int i = 1; i <= s; ++ i){
			dp[j][i] = pd[j - 1][L[i]] + ps[b[i].B] - ps[b[i].A - 1];
			while (SZ(dq) && b[dq.front()].B < b[i].A)
				dq.pop_front();
			if (SZ(dq))
				dp[j][i] = max(dp[j][i], get(j - 1, dq.front()) + ps[b[i].B]);
			while (SZ(dq) && get(j - 1, dq.front()) <= get(j - 1, i))
				dq.pop_back();
			dq.push_back(i);
			if (k <= dp[j][i])
				return true;
			pd[j][i] = max(pd[j][i - 1], dp[j][i]);
		}
	}
	return false;
}

int main(){
	fast_io;

	cin >> n >> s >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> A[i], cprs.push_back(A[i]);
	sort(all(cprs));
	for (int i = 1; i <= s; ++ i)
		cin >> a[i].B >> a[i].A;
	int mn = inf, ss = s;
	sort(a + 1, a + s + 1), s = 0;
	for (int i = ss; i >= 1; -- i){
		swap(a[i].A, a[i].B);
		mn = min(mn, a[i].A);
		if (a[i].A <= mn)
			b[++ s] = a[i];
	}
	reverse(b + 1, b + s + 1);
	for (int i = 1; i <= s; ++ i)
		for (int j = 1; j <= i; ++ j)
			if (b[j].B < b[i].A)
				L[i] = j;
	int lb = - 1, rb = n;
	while (1 < rb - lb){
		int mid = lb + rb >> 1;
		if (check(cprs[mid]))
			rb = mid;
		else
			lb = mid;
	}
	if (rb < n)
		cout << cprs[rb] << endl;
	else
		cout << - 1 << endl;

	return 0;
}