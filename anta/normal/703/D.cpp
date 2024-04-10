#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, T()); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i + 1) v[i] ^= x;
	}
	T sum(int i) const {	//[0, i)
		T r = T();
		for(-- i; i >= 0; i = (i & (i + 1)) - 1) r ^= v[i];
		return r;
	}
};

#define all(o) (o).begin(), (o).end()
template<typename T, typename V>
void twoDimensionalSumQuery(vector<pair<pair<T, T>, V> > points, vector<pair<pair<T, T>, int> > queries, vector<V> &ans) {
	int n = points.size(), m = queries.size();
	vector<T> positions;
	rep(i, n) positions.push_back(points[i].first.second);
	sort(all(positions));
	positions.erase(unique(all(positions)), positions.end());
	int p = positions.size();
	FenwickTree t; t.init(p);
	sort(all(points)); sort(all(queries));
	int left = 0;
	rep(i, m) {
		T x = queries[i].first.first;
		while(left < n && points[left].first.first < x) {
			int j = lower_bound(all(positions), points[left].first.second) - positions.begin();
			t.add(j, points[left].second);
			left ++;
		}
		int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
		ans[queries[i].second] ^= t.sum(y);
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> sum(n + 1);
		rep(i, n)
			sum[i + 1] = sum[i] ^ a[i];
		vector<int> prev(n);
		{
			map<int,int> last;
			rep(i, n) {
				int &p = last[a[i]];
				prev[i] = p - 1;
				p = i + 1;
			}
		}
		vector<pair<pii, int>> points(n);
		rep(i, n)
			points[i] = { {i, prev[i]}, a[i] };
		int m;
		scanf("%d", &m);
		vector<pair<pii, int>> queries(m * 2);
		vi ans(m);
		rep(i, m) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l;
			ans[i] = sum[r] ^ sum[l];
			queries[i * 2 + 0] = { { r, l }, i };
			queries[i * 2 + 1] = { { l, l }, i };
		}
		twoDimensionalSumQuery(points, queries, ans);
		for(int i = 0; i < m; ++ i)
			printf("%d\n", ans[i]);
	}
	return 0;
}