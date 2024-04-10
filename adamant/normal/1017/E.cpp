#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

point cmul(point a, point b) {
    return conj(a) * b;
}
ftype dot(point a, point b) {
    return cmul(a, b).x();
}
ftype cross(point a, point b) {
    return cmul(a, b).y();
}

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

bool rot(point a, point b) {
	return cross(a, b) < 0;
}

vector<point> convex(vector<point> r) {
	int n = r.size();
	sort(all(r), [&](point a, point b) {
		return make_pair(a.x(), a.y()) < make_pair(b.x(), b.y());
	});
	for(int i = 1; i < n; i++) {
		r[i] -= r[0];
	}
	sort(begin(r) + 1, end(r), [&](point a, point b) {
		int gg = cross(a, b);
		if(gg == 0) {
			return norm(a) < norm(b);
		} else {
			return gg < 0;
		}
	});
	vector<point> ans = {{0, 0}};
	for(int i = 1; i < n; i++) {
		while(ans.size() >= 3 && rot(r[i] - ans[ans.size() - 1], ans[ans.size() - 1] - ans[ans.size() - 2])) {
			ans.pop_back();
		}
		ans.push_back(r[i]);
	}
	return ans;
}

vector<point> clr(vector<point> hull) {
	int n = hull.size();
	vector<point> nw;
	bool one_line = true;
	for(int i = 0; i < n; i++) {
		point A = hull[i];
		point B = hull[(i + 1) % n];
		point C = hull[(i + 2) % n];
		if(cross(B - A, C - B) != 0) {
			nw.push_back(B);
			one_line = false;
		}
	}
	if(one_line == true) {
        	return {hull[0], hull.back()};
	} else {
	    return nw;
	}
}

vector<point> read_points(int n) {
	vector<point> lol(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		lol[i] = {x, y};
	}
	return lol;
}

vector<point> shifts(vector<point> hull) {
	int n = hull.size();
	vector<point> res;
	for(int i = 0; i < n; i++) {
		point A = hull[i];
		point B = hull[(i + 1) % n];
		point C = hull[(i + 2) % n];
		res.push_back(cmul(B - A, C - B));
	}
	return res;
}

const int inf = 1e18;

vector<int> check_cycle(vector<point> a, vector<point> b) {
	int as = a.size(), bs = b.size();
	a.push_back({inf, inf});
	for(int i = 0; i < 2 * b.size(); i++) {
		a.push_back(b[i % b.size()]);
	}
	int n = a.size();
	vector<int> p(n);
	p[0] = 0;
	vector<int> ans;
	for(int i = 1; i < n; i++) {
		p[i] = p[i - 1];
		while(p[i] && a[i] != a[p[i]]) {
			p[i] = p[p[i] - 1];
		}
		if(a[i] == a[p[i]]) {
			p[i]++;
		}
		if(i > as && p[i] == bs) {
			ans.push_back(i - as - bs);
		}
	}
	return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    auto A = read_points(n);
    auto B = read_points(m);
    A = clr(convex(A));
    B = clr(convex(B));
    auto poses = check_cycle(shifts(A), shifts(B));
    for(auto it: poses) {
		point aa = A[0];
		point bb = A[1];
		point cc = B[it];
		point dd = B[(it + 1) % B.size()];
		int nra = norm(bb - aa), nrb = norm(dd - cc);
		if(nra == nrb) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}