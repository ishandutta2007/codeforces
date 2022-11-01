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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e10 + 10;
const int mod = 998244353;
const int base = 257;

ll n, k, d, a[xn], lazy[xn << 2];
ll seg[xn << 2], b[xn];
pii ans, last[xn];
stack <int> st1, st2;
unordered_map <ll, int> mp;

bool cmp(pii i, pii j){
	if (i.B - i.A != j.B - j.A)
		return i.B - i.A > j.B - j.A;
	return (i.A < j.A) | (!j.A);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = min(seg[lc], seg[rc]);
}
int get(int id, int l, int r){
	if (r - l == 1)
		return l;
	int mid = l + r >> 1;
	shift(lc, l, mid), shift(rc, mid, r);
	if (seg[lc] <= k)
		return get(lc, l, mid);
	return get(rc, mid, r);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k >> d;
	if (!d){
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			last[i].A = i;
			if (i - 1 && a[i] == a[i - 1])
				last[i].A = last[i - 1].A;
			if (cmp({last[i].A, i}, ans))
				ans = {last[i].A, i};
		}
		cout << ans.A << sep << ans.B << endl;
		return 0;
	}
	st1.push(0), st2.push(0);
	for (int i = 1; i <= n; ++ i){
		cin >> a[i], a[i] += inf;
		last[i].A = i, b[i] = a[i] % d, a[i] /= d;
		if (i - 1 && b[i] == b[i - 1])
			last[i].A = last[i - 1].A;
		last[i].B = mp[a[i]] + 1;
		mp[a[i]] = i;
		ll x, ind;
		while (st1.top() && a[st1.top()] > a[i]){
			ind = st1.top(), x = a[ind] - a[i], st1.pop();
			update(1, 1, n + 1, st1.top() + 1, ind + 1, x);
		}
		st1.push(i);
		while (st2.top() && a[st2.top()] < a[i]){
			ind = st2.top(), x = a[i] - a[ind], st2.pop();
			update(1, 1, n + 1, st2.top() + 1, ind + 1, x);
		}
		st2.push(i);
		update(1, 1, n + 1, 1, last[i].A, xn);
		update(1, 1, n + 1, 1, last[i].B, xn);
		ind = get(1, 1, n + 1);
		if (cmp({ind, i}, ans)) ans = {ind, i};
		update(1, 1, n + 1, 1, i + 1, - 1);
	}
	cout << ans.A << sep << ans.B << endl;
			
	return 0;
}