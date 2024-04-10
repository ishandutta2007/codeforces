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
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, lcp[xn], L[xn], R[xn], rnk[xm][xn], pw, P[xn];
ll ans;
string S;
stack <int> sk;

bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= n; ++ i)
		rnk[0][i] = S[i - 1], P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + n + 1, cmp);
		rnk[pw][P[1]] = 1;
		for (int i = 2; i <= n; ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (rnk[i][x] != rnk[i][y] || max(x, y) + (1 << i) - 1 > n)
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> S;
		n = SZ(S);
		buildSA();
		for (int i = 1; i < n; ++ i)
			lcp[i] = LCP(P[i], P[i + 1]);
		ans = 0;
		while (SZ(sk))
			sk.pop();
		for (int i = 1; i < n; ++ i){
			while (SZ(sk) && lcp[sk.top()] >= lcp[i])
				sk.pop();
			L[i] = 0;
			if (SZ(sk))
				L[i] = sk.top();
			sk.push(i);
		}
		while (SZ(sk))
			sk.pop();
		for (int i = n - 1; i >= 1; -- i){
			while (SZ(sk) && lcp[sk.top()] > lcp[i])
				sk.pop();
			R[i] = n;
			if (SZ(sk))
				R[i] = sk.top();
			sk.push(i);
		}
		for (int i = 1; i < n; ++ i)
			ans += ll(i - L[i]) * ll(R[i] - i) * ll(lcp[i]);
		ans = ans + ans + ll(n) * ll(n + 1) / 2;
		cout << ans << endl;
	}
	
	return 0;
}