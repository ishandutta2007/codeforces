/*input
5
1 1 1
1 3 -1
1 5 1
1 7 -1 
3 1 100 8

*/

#include <iostream>
#include <cassert>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
const int INF = 1e9 + 8;
const int MAXN = 100007;

using Query = tuple<int, int, int, int>;
int Q;
vector<Query> queries;
vector<int> vec;

struct Node
{
	int l, r, p0;
	int64_t v0, v1, mn, en;
	bool lf;

	Node(int _l = -1, int _r = -1, int _p0 = -1, int64_t _v0 = 0, int64_t _v1 = 0, int64_t _mn = 0, int64_t _en = 0, bool _lf = true):
		l(_l), r(_r), p0(_p0), v0(_v0), v1(_v1), mn(_mn), en(_en), lf(_lf) {}

	void set_event(int64_t x)
	{
		assert(lf);
// 		deb << "set " << l << ' ' << r << ": " << x << " " << mn << endl;
		p0 = l, v0 = v1 = x, mn = min(0ll, en = x * (r - l));
	}

	void rem_event()
	{
		assert(lf);
// 		deb << "rem " << l << ' ' << r << endl;
		p0 = -1, v0 = v1 = 0, mn = en = 0;
	}

	int64_t get_mn(int64_t v)
	{
		return min(0ll, (~p0 ? v * (p0 - l) + mn : v * (r - l)));
	}

	int64_t get_en(int64_t v)
	{
		return (~p0 ? v * (p0 - l) + en : v * (r - l));
	}

	friend Node operator+ (Node x, Node y)
	{
		assert(x.r == y.l);
		return Node(
			x.l,
			y.r,
			(~x.p0 ? x.p0 : y.p0),
			(~x.p0 ? x.v0 : y.v0),
			(~y.p0 ? y.v1 : x.v1),
			min(x.mn, x.en + y.get_mn(x.v1)),
			x.en + y.get_en(x.v1),
			false
		);
	}
} it[MAXN << 2];


void set_event(int t, int s, int rt = 1)
{
	auto &nd = it[rt];
	if (nd.lf) return nd.set_event(s);

	int m = it[rt << 1].r;
	if (t < m) set_event(t, s, rt << 1);
	else set_event(t, s, rt << 1 | 1);
	it[rt] = it[rt << 1] + it[rt << 1 | 1];
}

void rem_event(int t, int rt = 1)
{
	auto &nd = it[rt];
	if (nd.lf) return nd.rem_event();

	int m = it[rt << 1].r;
	if (t < m) rem_event(t, rt << 1);
	else rem_event(t, rt << 1 | 1);
	it[rt] = it[rt << 1] + it[rt << 1 | 1];
}

bool trav(int l, int r, int64_t &x, int64_t &v, int rt, long double &ans)
{
	auto &nd = it[rt];
// 	deb << l << ' ' << r << ": " << rt << ' ' << nd.l << ' ' << nd.r << ' ' << x << ' ' << v << ": " << nd.get_mn(v) << ", " << nd.p0 << endl;

	if (r <= nd.l || nd.r <= l) return 0;
	if (l <= nd.l && nd.r <= r && x + nd.get_mn(v) > 0) return x += nd.get_en(v), v = (~nd.p0 ? nd.v1 : v), 0;
	if (nd.lf) {
		if (nd.l < l) return 0;
		v = (~nd.p0 ? nd.v0 : v);
// 		deb << "T " << x + (min(r, nd.r) - nd.l) * v << endl;
		if (x + (min(r, nd.r) - nd.l) * v <= 0) return ans = (long double) (nd.l * v - x) / v, 1;
		return x += (min(r, nd.r) - nd.l) * v, 0;
	}

	if (trav(l, r, x, v, rt << 1, ans)) return 1;
	if (trav(l, r, x, v, rt << 1 | 1, ans)) return 1;
	return 0;
}

long double get(int l, int r, int64_t x)
{
	if (x == 0) return l;
	int64_t v = 0;
	long double ans;
	if (trav(l, r, x, v, 1, ans)) return ans;
// 	deb << "get " << l << ' ' << r << ": " << x << ' ' << v << endl;
	return -1;
}

void build(int rt = 1, int lo = 0, int hi = (int) vec.size() - 2) 
{
	if (lo == hi) {
		it[rt] = Node(vec[lo], vec[lo + 1]);
		return;
	}

	int mid = (lo + hi) >> 1;
	build(rt << 1, lo, mid);
	build(rt << 1 | 1, mid + 1, hi);
	it[rt] = it[rt << 1] + it[rt << 1 | 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Q;
	queries.resize(Q);
	vec.reserve(Q + 2);

	for (auto &q : queries) {
		int k, t, s, l, r, v;
		cin >> k;
		if (k == 1) {
			cin >> t >> s;
			vec.push_back(t);
			q = make_tuple(k, t, s, 0);
		} else if (k == 2) {
			cin >> t;
			q = make_tuple(k, t, 0, 0);
		} else {
			cin >> l >> r >> v;
			q = make_tuple(k, l, r, v);
		}
	}

	for (int i = 0; i <= 10; ++i) vec.push_back(i);
	vec.push_back(INF);
	vec.push_back(INF + 1);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	build();
	cout << fixed << setprecision(10);
	for (auto &q : queries) {
		if (get<0>(q) == 1) {
			set_event(get<1>(q), get<2>(q));
		} else if (get<0>(q) == 2) {
			rem_event(get<1>(q));
		} else {
			long double ans = get(get<1>(q), get<2>(q), get<3>(q));
			if (ans < 0) cout << -1 << '\n';
			else cout << ans << '\n';
		}
	}
}