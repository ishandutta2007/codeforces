# include <bits/stdc++.h>
 
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const ll base = 4e3 + 10;
 
int n, Rank[25][xn], pw, P[xn], mn = inf, ptr;
int a[xn], L[xn], R[xn], ans[xn], part[xn];
stack <int> st;
string s[3];
 
bool cmp(int i, int j){
	if (Rank[pw - 1][i] != Rank[pw - 1][j])
		return Rank[pw - 1][i] < Rank[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return Rank[pw - 1][(1 << (pw - 1)) + i] < Rank[pw - 1][(1 << (pw - 1)) + j];
}
void build(string S){
	for (int i = 1; i <= n; ++ i)
		Rank[0][i] = S[i - 1], P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + n + 1, cmp);
		Rank[pw][P[1]] = 1;
		for (int i = 2; i <= n; ++ i)
			Rank[pw][P[i]] = Rank[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (Rank[i][x] != Rank[i][y] || max(x, y) + (1 << i) > n + 1)
			continue;
		x += 1 << i;
		y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void solve(string S, int add){
	n = SZ(S);
	build(S);
	for (int i = 1; i < n; ++ i)
		a[i] = LCP(P[i], P[i + 1]);
	while (SZ(st))
		st.pop();
	for (int i = 1; i < n; ++ i){
		while (SZ(st) && a[st.top()] >= a[i])
			st.pop();
		L[i] = 0;
		if (SZ(st))
			L[i] = st.top();
		st.push(i);
	}
	while (SZ(st))
		st.pop();
	for (int i = n - 1; i >= 1; -- i){
		while (SZ(st) && a[st.top()] > a[i])
			st.pop();
		R[i] = n;
		if (SZ(st))
			R[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i < n; ++ i){
		int x = i - L[i] - 1, y = R[i] - i - 1;
		if (add == 1)
			ans[a[i]] = (ll(ans[a[i]]) + ll(part[y + x + 1]) - ll(part[y]) - ll(part[x]) + ll(mod) + ll(mod)) % mod;
		else
			ans[a[i]] = (ll(ans[a[i]]) - ll(part[y + x + 1]) + ll(part[y]) + ll(part[x]) + ll(mod)) % mod;
	}
}
 
int main(){
    InTheNameOfGod;
    
    for (int i = 1; i < xn; ++ i)
    	part[i] = (ll(i) * ll(i - 1) / 2LL % mod + part[i - 1]) % mod;
	for (int i = 0; i < 3; ++ i)
		cin >> s[i], mn = min(mn, SZ(s[i]));
	//solve(s[1] + char(1) + s[2], 1);
	//solve(s[1] + char(1) + s[0], - 1);
	
	for (int i = 0; i < 3; ++ i)
		for (int j = i + 1; j < 3; ++ j)
			solve(s[i] + char(1) + s[j], - 1);
	for (int i = 0; i < 3; ++ i)
		solve(s[i], 1);
	solve(s[0] + char(1) + s[1] + char(2) + s[2], 1);
	for (int i = xn - 2; i >= 0; -- i)
		ans[i] = (ans[i] + ans[i + 1]) % mod;
	
	for (int i = 1; i <= mn; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
    return 0;
}