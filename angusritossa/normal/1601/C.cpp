#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define MAXN 1000010
int a[MAXN], b[MAXN];
int tmp[MAXN][2];
vector<int> at[MAXN];
void solve(int mn, int mx, int ansmn, int ansmx) {
	if (mn > mx) return;
	int val = (mn+mx)/2;
	int greater = 0;
	for (int i = ansmn; i <= ansmx; i++) {
		tmp[i][0] = greater;
		greater += (a[i] > b[val]);
	}

	greater = 0;
	pair<int, int> best = { 1e9, 0 };
	for (int i = ansmx; i >= ansmn; i--) {
		greater += (a[i] < b[val]);
		tmp[i][1] = greater;
		best = min(best, { tmp[i][0] + tmp[i][1], i});
	}

	at[best.second].push_back(b[val]);

	solve(mn, val-1, ansmn, best.second);
	solve(val+1, mx, best.second, ansmx);
}

typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;

long long count_inversions(vector<int> &v) {
	reverse(v.begin(), v.end());
	ordered_set s;
	long long ans = 0;
	int i = 0;
	for (int a : v) {
		i++;
		ans += s.order_of_key(make_pair(a, -1));
		s.insert({a, i});
	}
	return ans;
}
int t, n, m;
int main() {
	scanf("%d", &t);
	for (int ccc = 0; ccc < t; ccc++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		a[n] = 1e9;
		for (int i = 0; i < m; i++) scanf("%d", &b[i]);

		sort(b, b+m);
		solve(0, m-1, 0, n);

		vector<int> v;
		for (int i = 0; i <= n; i++) {
			sort(at[i].begin(), at[i].end());
			for (auto c : at[i]) v.push_back(c);
			if (i != n) v.push_back(a[i]);
		}

		//for (auto a : v) printf("%d ", a);
		//printf("\n");


		printf("%lld\n", count_inversions(v));


		for (int i = 0; i <= n; i++) at[i].clear();
	}
}