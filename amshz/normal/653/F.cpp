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
 
const int xn = 1e6 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e6;
const ll base = 4e3 + 10;

int n, Rank[25][xn], pw, P[xn], part[xn];
vector <int> vec[xn];
ll ans;
string S;

bool cmp(int i, int j){
	if (Rank[pw - 1][i] != Rank[pw - 1][j])
		return Rank[pw - 1][i] < Rank[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return Rank[pw - 1][(1 << (pw - 1)) + i] < Rank[pw - 1][(1 << (pw - 1)) + j];
}
void build(){
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
		x += 1 << i;
		y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
int check(int l, int r, bool f = false){
	int res = 0;
	int lb = - 1, rb = SZ(vec[n + part[l - 1] - 1]);
	while (rb - lb > 1){
		int mid = lb + rb >> 1;
		if (vec[n + part[l - 1] - 1][mid] >= l)
			rb = mid;
		else
			lb = mid;
	}
	if (rb < SZ(vec[n + part[l - 1] - 1]))
		r = min(r, vec[n + part[l - 1] - 1][rb]);
	lb = - 1, rb = SZ(vec[n + part[l - 1]]);
	while (rb - lb > 1){
		int mid = lb + rb >> 1;
		if (vec[n + part[l - 1]][mid] >= r)
			rb = mid;
		else
			lb = mid;
	}
	res += rb;
	lb = - 1, rb = SZ(vec[n + part[l - 1]]);
	while (rb - lb > 1){
		int mid = lb + rb >> 1;
		if (vec[n + part[l - 1]][mid] >= l)
			rb = mid;
		else
			lb = mid;
	}
	res -= rb;
	return res;
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> S;
	build();
	for (int i = 1; i <= n; ++ i){
		part[i] = part[i - 1];
		if (S[i - 1] == '(')
			++ part[i];
		else
			-- part[i];
		vec[part[i] + n].push_back(i);
	}
	for (int i = 1; i <= n; ++ i)
		ans += check(i, n + 1, 1);
	for (int i = 1; i < n; ++ i)
		ans -= check(P[i], P[i] + LCP(P[i], P[i + 1]));
	cout << ans << endl;
	
    return 0;
}