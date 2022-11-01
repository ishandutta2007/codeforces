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
typedef pair <ll,  ll >                                  pii;
typedef pair <pii, ll >                                  ppi;
typedef pair <ll , pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll MOD = 998244353;
const int TM = 30;
const int BASE = 257;

ll n, num[xn], v[xn], p[xn], inv = power(100, MOD - 2, MOD), ans, flag, sum;
ppp seg[xn << 2];
bool mark[xn][4];
vector <ppp> vec;

void PRINT(ppp x){cout << x.A.A << sep << x.A.B << " , " << x.B.A << sep << x.B.B << endl;}
bool CMP(ppp x, ppp y){
	if (ld(ld(x.A.A) / ld(x.A.B)) != ld(ld(y.A.A) / ld(y.A.B))) return (ld(ld(x.A.A) / ld(x.A.B)) < ld(ld(y.A.A) / ld(y.A.B)));
	return x.B.A < y.B.A;
}
ppp merge(ppp x, ppp y, pii f, int ind, int g = 0){
	if (x.A.A == -1) return y;
	if (y.A.A == -1) return x;
	ppp z = {{0, 0}, {0, 0}};
	flag = (ind == f.A);
	if (mark[ind][0] == g || (f.B == 0 && g == 2)) z.A.A = (z.A.A + x.A.A * y.A.A) % MOD;
	if (mark[ind][1] == g || (f.B == 1 && g == 2)) z.A.A = (z.A.A + x.A.A * y.B.A) % MOD;
	if (mark[ind][2] == g || (f.B == 2 && g == 2)) z.A.A = (z.A.A + x.A.B * y.A.A) % MOD;
	if (mark[ind][3] == g || (f.B == 3 && g == 2)) z.A.A = (z.A.A + x.A.B * y.B.A) % MOD;
	if (mark[ind][0] == g || (f.B == 0 && g == 2)) z.A.B = (z.A.B + x.A.A * y.A.B) % MOD;
	if (mark[ind][1] == g || (f.B == 1 && g == 2)) z.A.B = (z.A.B + x.A.A * y.B.B) % MOD;
	if (mark[ind][2] == g || (f.B == 2 && g == 2)) z.A.B = (z.A.B + x.A.B * y.A.B) % MOD;
	if (mark[ind][3] == g || (f.B == 3 && g == 2)) z.A.B = (z.A.B + x.A.B * y.B.B) % MOD;
	if (mark[ind][0] == g || (f.B == 0 && g == 2)) z.B.A = (z.B.A + x.B.A * y.A.A) % MOD;
	if (mark[ind][1] == g || (f.B == 1 && g == 2)) z.B.A = (z.B.A + x.B.A * y.B.A) % MOD;
	if (mark[ind][2] == g || (f.B == 2 && g == 2)) z.B.A = (z.B.A + x.B.B * y.A.A) % MOD;
	if (mark[ind][3] == g || (f.B == 3 && g == 2)) z.B.A = (z.B.A + x.B.B * y.B.A) % MOD;
	if (mark[ind][0] == g || (f.B == 0 && g == 2)) z.B.B = (z.B.B + x.B.A * y.A.B) % MOD;
	if (mark[ind][1] == g || (f.B == 1 && g == 2)) z.B.B = (z.B.B + x.B.A * y.B.B) % MOD;
	if (mark[ind][2] == g || (f.B == 2 && g == 2)) z.B.B = (z.B.B + x.B.B * y.A.B) % MOD;
	if (mark[ind][3] == g || (f.B == 3 && g == 2)) z.B.B = (z.B.B + x.B.B * y.B.B) % MOD;
	return z;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].A.A = inv * (100 - p[l]) % MOD;
		seg[id].B.B = inv * p[l] % MOD;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], {-1, -1}, mid - 1);
}
void update(int id, int l, int r, int pos, int f){
	int mid = l + r >> 1;
	if (pos < mid - 1) update(id << 1, l, mid, pos, f);
	if (pos > mid - 1) update(id << 1 | 1, mid, r, pos, f);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1], {pos, f}, mid - 1);
}
ppp get(int id, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return seg[id];
	if (qr <= l || r <= ql) return {{-1, -1}, {-1, -1}};
	int mid = l + r >> 1;
	return merge(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr), {-1, -1}, mid - 1);
}

int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> num[i] >> v[i] >> p[i];
    for (int i = 0; i < n - 1; ++ i){
    	ll x = num[i + 1] - num[i];
    	ll y = v[i] + v[i + 1];
    	vec.push_back({{x, y}, {i, 2}});
    	if (v[i] > v[i + 1]){
    		y = v[i] - v[i + 1];
    		vec.push_back({{x, y}, {i, 3}});
		}
		if (v[i] < v[i + 1]){
			y = v[i + 1] - v[i];
			vec.push_back({{x, y}, {i, 0}});
		}
	}
	build(1, 0, n);
	sort(all(vec), CMP);
	for (ppp b : vec){
		ll Time = b.A.A * power(b.A.B, MOD - 2, MOD) % MOD;
		ppp x = get(1, 0, n, 0, b.B.A + 1);
		ppp y = get(1, 0, n, b.B.A + 1, n);
		ppp z = merge(x, y, {b.B.A, b.B.B}, b.B.A, 2);
		sum = 0;
		sum = (sum + z.A.A) % MOD;
		sum = (sum + z.A.B) % MOD;
		sum = (sum + z.B.A) % MOD;
		sum = (sum + z.B.B) % MOD;
		ans = (ans + sum * Time % MOD) % MOD;
		mark[b.B.A][b.B.B] = true;
		update(1, 0, n, b.B.A, b.B.B);
	}
	cout << ans << endl;
    
    return 0;
}