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

struct node{
	int ted, sz, pre, suff, ans, cnt;
};

int n, Rank[xm][xn], pw, lcp[xn], P[xn];
int L[xn], R[xn], part[xn];
stack <int> st;
ll ans;
string S, T;
node seg[xn << 2];

bool cmp(int i, int j){
	if (Rank[pw - 1][i] != Rank[pw - 1][j])
		return Rank[pw - 1][i] < Rank[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return Rank[pw - 1][(1 << (pw - 1)) + i] < Rank[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
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
		if (Rank[i][x] != Rank[i][y])
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> S >> T;
	reverse(all(S));
	reverse(all(T));
	buildSA();
	for (int i = 1; i < n; ++ i)
		lcp[i] = LCP(P[i], P[i + 1]);
	for (int i = 1; i <= n; ++ i)
		part[i] = part[i - 1] + (T[P[i] - 1] == '0');
	while (SZ(st))
		st.pop();
	for (int i = 1; i < n; ++ i){
		while (SZ(st) && lcp[st.top()] >= lcp[i])
			st.pop();
		L[i] = 0;
		if (SZ(st))
			L[i] = st.top();
		st.push(i);
	}
	while (SZ(st))
		st.pop();
	for (int i = n - 1; i >= 1; -- i){
		while (SZ(st) && lcp[st.top()] > lcp[i])
			st.pop();
		R[i] = n;
		if (SZ(st))
			R[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i < n; ++ i)
		ans = max(ans, ll(lcp[i]) * ll(part[R[i]] - part[L[i]]));
	for (int i = 0; i < n; ++ i)
		if (T[i] == '0')
			ans = max(ans, ll(n - i));
	cout << ans << endl;
			
	return 0;
}