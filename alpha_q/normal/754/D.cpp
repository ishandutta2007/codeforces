#include <bits/stdc++.h> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, greater <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int N = 3e5 + 10;
const int INF = 2e9 + 10;

struct interval {
	int l, r, id;
	bool operator < (const interval &i) const {
		return l < i.l;
	}
};

int n, k;
interval x[N];
OrderedSet OS;
vector <interval> v;
vector <int> ans;

bool cmp (interval a, interval b) {
	return a.r > b.r;
}

int tim = 0;

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &x[i].l, &x[i].r);
		x[i].id = i;
	}
	if (k == 1) {
		int res = 0, id;
		for (int i = 1; i <= n; ++i) {
			if (x[i].r - x[i].l + 1 > res) {
				res = x[i].r - x[i].l + 1;
				id = i;
			}
		}
		printf("%d\n%d\n", res, id);
		return 0;
	}
	sort(x + 1, x + n + 1);
	// for (int i = 1; i <= n; ++i) {
	// 	cout << x[i].l << " " << x[i].r << endl;
	// }
	int lmax = x[k].l, rmin = INF;
	int last = k;
	for (int i = 1; i <= k; ++i) {
		rmin = min(rmin, x[i].r);
		OS.insert(make_pair(x[i].r, ++tim));
	}
	int res = max(0, rmin - lmax + 1);
	for (int j = k + 1; j <= n; ++j) {
		lmax = x[j].l;
		rmin = min(x[j].r, (*OS.find_by_order(k - 2)).first);
		OS.insert(make_pair(x[j].r, ++tim));
		// cout << lmax << " " << rmin << endl;
		int now = max(0, rmin - lmax + 1);
		if (now > res) {
			res = now;
			last = j;
		}
	}
	// cout << last << endl;
	printf("%d\n", res);
	for (int i = 1; i < last; ++i) {
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < k - 1; ++i) {
		ans.push_back(v[i].id);
	}
	ans.push_back(x[last].id);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < k; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}