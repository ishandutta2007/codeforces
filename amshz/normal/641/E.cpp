# include <bits/stdc++.h>
 
///*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//*/
 
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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 800;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, q, seg[xn << 2], t[xn], a[xn], num[xn], ptr, ans[xn], last, Time[xn << 2];
vector <int> compress;
vector <ppi> Q[xn];
unordered_map <int, int> mp;

void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] = val;
		Time[id] = last;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid) modify(id << 1, l, mid, pos, val);
	else modify(id << 1 | 1, mid, r, pos, val);
	seg[id] = 0;
	if (Time[id << 1] == last) seg[id] += seg[id << 1];
	if (Time[id << 1 | 1] == last) seg[id] += seg[id << 1 | 1];
	Time[id] = last;
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || ql == qr) return 0;
	if (ql <= l && r <= qr){
		if (Time[id] == last) return seg[id];
		return 0;
	}
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}
void solve(int x){
	last = x;
	for (ppi qu : Q[x]){
		if (qu.A.A == 1) modify(1, 0, n, qu.A.B, 1);
		else if (qu.A.A == 2) modify(1, 0, n, qu.A.B, - 1);
		else ans[qu.B] = get(1, 0, n, 0, qu.A.B);
	}
}

int main(){
    InTheNameOfGod;
    
    cin >> q;
    for (int i = 0; i < q; ++ i){
    	cin >> a[i] >> t[i] >> num[i];
    	compress.push_back(t[i]);
	}
	Sort(compress);
	for (int i = 0; i < SZ(compress); ++ i){
		if (i && compress[i] == compress[i - 1]) continue;
		mp[compress[i]] = n ++;
	}
	for (int i = 0; i < q; ++ i) t[i] = mp[t[i]];
	mp.clear();
	compress.clear();
	for (int i = 0; i < q; ++ i) compress.push_back(num[i]);
	Sort(compress);
	for (int i = 0; i < SZ(compress); ++ i){
		if (i && compress[i] == compress[i - 1]) continue;
		mp[compress[i]] = ptr ++;
	}
	for (int i = 0; i < q; ++ i) num[i] = mp[num[i]];
	for (int i = 0; i < q; ++ i) Q[num[i]].push_back({{a[i], t[i]}, i});
	for (int i = 0; i < ptr; ++ i) solve(i);
	for (int i = 0; i < q; ++ i) if (a[i] == 3) cout << ans[i] << endl;
    
    return 0;
}