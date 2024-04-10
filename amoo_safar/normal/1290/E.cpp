#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 15e4 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;



const int N = 15e4 + 5;
//const int N = 2e5 + 5;
int n, a[N];

struct Segment {
	struct Node {
		long long sum, lz;
		int mx1, mx2, ted, k, lz_mx;
		Node(): sum(0), lz(0), mx1(-1), mx2(-1), ted(0), k(0), lz_mx(0) {};

		void add(int x) {
			if (!k)
				return;
			sum += 1LL * k * x;
			lz += x, mx1 += x;
			if (mx2 >= 0)
				mx2 += x;
		}
		void change(int x) {
			if (!k)
				return;
			sum += 1LL * x * ted;
			lz_mx += x, mx1 += x;
		}
		friend Node merge(Node a, Node b) {
			if (b.k && a.mx1 < b.mx1)
				swap(a, b);
			if (a.mx1 == b.mx1) {
				a.ted += b.ted;
				a.mx2 = max(a.mx2, b.mx2);
			}
			else
				a.mx2 = max(a.mx2, b.mx1);
			a.lz = a.lz_mx = 0;
			a.sum += b.sum;
			a.k += b.k;
			return a;
		}
	} seg[N << 2];

	void shift(int id) {
		for (auto p: {id << 1, id << 1 | 1}) {
			seg[p].add(seg[id].lz);
			if (seg[p].mx1 + seg[id].lz_mx == seg[id].mx1)
				seg[p].change(seg[id].lz_mx);
		}
		seg[id].lz = seg[id].lz_mx = 0;
	}
	void change(int p, int x, int id = 1, int st = 0, int en = n) {
		if (en - st == 1) {
			seg[id].mx1 = seg[id].sum = x;
			seg[id].ted = seg[id].k = 1;
			return;
		}
		shift(id);
		int mid = st + en >> 1;
		if (p < mid)
			change(p, x, id << 1, st, mid);
		else
			change(p, x, id << 1 | 1, mid, en);
		seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
	}
	void update(int l, int r, int x, int id = 1, int st = 0, int en = n) {
		if (r <= st || en <= l || seg[id].mx1 <= x)
			return;
		if (l <= st && en <= r && seg[id].mx2 < x)
			return seg[id].change(x - seg[id].mx1);
		shift(id);
		int mid = st + en >> 1;
		update(l, r, x, id << 1, st, mid);
		update(l, r, x, id << 1 | 1, mid, en);
		seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
	}
	void add(int l, int r, int x, int id = 1, int st = 0, int en = n) {
		if (r <= st || en <= l)
			return;
		if (l <= st && en <= r)
			return seg[id].add(x);
		shift(id);
		int mid = st + en >> 1;
		add(l, r, x, id << 1, st, mid);
		add(l, r, x, id << 1 | 1, mid, en);
		seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
	}
	long long get(int l, int r, int id = 1, int st = 0, int en = n) {
		if (r <= st || en <= l || !seg[id].sum)
			return 0;
		if (l <= st && en <= r)
			return seg[id].sum;
		shift(id);
		int mid = st + en >> 1;
		return get(l, r, id << 1, st, mid) + get(l, r, id << 1 | 1, mid, en);
	}
};

Segment seg, seg2;

void build(int id = 1, int st = 0, int en = n) {
	//seg.build();
	return ;
}

void update_min(int l, int r, int x, int id = 1, int st = 0, int en = n) {
	seg.update(l, r, x);
}

long long get(int l, int r, int id = 1, int st = 0, int en = n) {
	return seg.get(l, r);
}

void Change(int id, int x){
	seg.change(id, x);
}


ll ind[Maxn], ans[Maxn];

ll fen[Maxn];
void add(int idx){
	idx ++;
	for(; idx < Maxn; idx += (idx & (-idx)))
		fen[idx] ++;
}
int get(int idx){
	idx ++;
	int res = 0;
	for(; idx; idx -= (idx & (-idx)))
		res += fen[idx];
	return res;
}
ll C2(ll x){
	return x * (x - 1) / 2;
}
void Add(int l, int r, int d){
	seg.add(l, r, d);
	//for(int i = l; i < r; i++){
	//	Change(i, get(i, i + 1) + d);
	//}
}


int to[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	//fill(a, a + N, n + 10);
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		ind[v] = i;
	}
	build();
	//reset();
	
	for(int i = 1; i <= n; i++){
		//cerr << i << '\n';
		add(ind[i]);
		update_min(0, ind[i], get(ind[i]) - 1);
		Change(ind[i], i);
		Add(ind[i], n, 1);
		update_min(0, n, i);
		ans[i] += get(0, n);
		ans[i] += -C2(i);
	}
	memset(to, 0, sizeof to);
	memset(fen, 0, sizeof fen);
	//cerr << "D\n";
	//swap(seg, seg2);
	seg = seg2;
	for(int i = 1; i <= n; i++) ind[i] = n - 1 - ind[i]; 
	
	build();
	//reset();
	
	for(int i = 1; i <= n; i++){
		//cerr << i << '\n';
		add(ind[i]);
		update_min(0, ind[i], get(ind[i]) - 1);
		Change(ind[i], i);
		Add(ind[i], n, 1);
		update_min(0, n, i);
		ans[i] += get(0, n);
		ans[i] += -C2(i);
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] - i << '\n';
	return 0;
}