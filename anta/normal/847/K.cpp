#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

template<typename T> struct GetID {
	map<T, int> ids;
	vector<T> values;
	void clear() { ids.clear(); }
	int size() const { return values.size(); }
	int get(const T &x) {
		typename map<T, int>::iterator it = ids.find(x);
		if (it != ids.end()) return it->second;
		int newID = values.size();
		values.push_back(x);
		ids.insert(make_pair(x, newID));
		return newID;
	}
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int a; int b; int k; int f;
		scanf("%d%d%d%d", &a, &b, &k, &f);
		GetID<string> id;
		vector<pair<int, int>> route(n);
		rep(i, n) {
			char buf[101];
			scanf("%s", buf);
			int x = id.get(buf);
			scanf("%s", buf);
			int y = id.get(buf);
			route[i] = { x, y };

		}
		int X = id.size();
		vector<int> save(X * X, 0);
		int ans = 0;
		rep(i, n) {
			int price = i > 0 && route[i].first == route[i - 1].second ? b : a;
			ans += price;
			auto p = minmax(route[i].first, route[i].second);
			save[p.first * X + p.second] += price;
		}
		sort(save.rbegin(), save.rend());
		rep(i, min(k, X * X)) {
			int t = save[i];
			if (t <= f) break;
			ans -= t - f;
		}
		printf("%d\n", ans);
	}
	return 0;
}