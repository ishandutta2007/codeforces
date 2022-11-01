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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, seg[xn << 2], ptr, ans[xn];
bool lazy[xn << 2];
stack <int> st;

void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] = 0;
	if (r - l > 1){
		lazy[id << 1] = true;
		lazy[id << 1 |  1] = true;
	}
	lazy[id] = false;
}
void modify(int id, int l, int r, int pos, int val){
	shift(id, l, r);
	if (r - l == 1){
		seg[id] += val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos, val);
	else
		modify(id << 1 | 1, mid, r, pos, val);
	shift(id << 1, l, mid);
	shift(id << 1 | 1, mid, r);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = true;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr);
	update(id << 1 | 1, mid, r, ql, qr);
	seg[id] = seg[id << 1] + seg[id << 1| 1];
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(id << 1, l, mid, ql, qr) + get(id << 1 | 1, mid, r, ql, qr);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n + n; ++ i){
		char c;
		int x;
		cin >> c;
		if (c == '+'){
			modify(1, 0, n, 0, 1);
			st.push(++ ptr);
		}
		else{
			cin >> x;
			int y = get(1, 0, n, 0, x);
			if (!y) kill("NO");
			update(1, 0, n, 0, x);
			if (x < n)
				modify(1, 0, n, x, y - 1);
			ans[st.top()] = x;
			st.pop();
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}