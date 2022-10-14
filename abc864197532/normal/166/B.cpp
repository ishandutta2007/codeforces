#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 30, logN = 17, K = 90002;

struct Pt {
	lli x, y;
	int d;
	Pt (lli _x = 0, lli _y = 0) : x(_x), y(_y) {}
	Pt operator + (const Pt &other) {
		return Pt(x + other.x, y + other.y);
	}
	Pt operator - (const Pt &other) {
		return Pt(x - other.x, y - other.y);
	}
	Pt operator * (const int &k) {
		return Pt(x * k, y * k);
	}
	lli operator * (const Pt &other) { // dot
		return x * other.x + y * other.y;
	}
	lli operator ^ (const Pt &other) { // cross
		return x * other.y - y * other.x;
	}
};

int ori (Pt o, Pt a, Pt b) {
	lli k = (o - a) ^ (o - b);
	return (k < 0 ? -1 : (k > 0 ? 1 : 0));
}

bool banana (Pt a, Pt b, Pt c, Pt d) { // check segment ab and cd
	if (ori(a, b, c) == 0 and (c - a) * (c - b) <= 0) return true;
	if (ori(a, b, d) == 0 and (d - a) * (d - b) <= 0) return true;
	if (ori(c, d, a) == 0 and (a - c) * (a - d) <= 0) return true;
	if (ori(c, d, b) == 0 and (b - c) * (b - d) <= 0) return true;
	if (ori(a, b, c) * ori(a, b, d) == -1 and ori(c, d, a) * ori(c, d, b) == -1) return true;
	return false;
}

vector <Pt> get_down_convex_hull (vector <Pt> &point) {
	int n = point.size();
	sort(all(point), [](Pt a, Pt b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	auto check = [&](Pt a, Pt b, Pt c) {
		return ((a - b) ^ (a - c)) < 0;
	};
	vector <Pt> ans;
	for (int i = 0; i < n; ++i) {
		while (ans.size() >= 2 and check(ans[ans.size() - 2], ans.back(), point[i])) {
			ans.pop_back();
		}
		ans.pb(point[i]);
	}
	return ans;
}

vector <Pt> get_up_convex_hull (vector <Pt> &point) {
	int n = point.size();
	sort(all(point), [](Pt a, Pt b) {
		if (a.x == b.x) return a.y > b.y;
		return a.x > b.x;
	});
	auto check = [&](Pt a, Pt b, Pt c) {
		return ((b - a) ^ (c - a)) < 0;
	};
	vector <Pt> ans;
	for (int i = 0; i < n; ++i) {
		while (ans.size() >= 2 and check(ans[ans.size() - 2], ans.back(), point[i])) {
			ans.pop_back();
		}
		ans.pb(point[i]);
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    cin >> n;
    vector <Pt> v;
    fop (i,0,n) {
        cin >> x >> y;
        v.pb(Pt(x, y));
        v.back().d = 0;
    }
    cin >> m;
    fop (i,0,m) {
        cin >> x >> y;
        v.pb(Pt(x, y));
        v.back().d = 1;
    }
    vector <Pt> u = get_up_convex_hull(v), d = get_down_convex_hull(v);
    bool is = true;
    for (Pt &p : u) is &= p.d == 0;
    for (Pt &p : d) is &= p.d == 0;
    cout << (is ? "YES\n" : "NO\n");
}