#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<string> strs(n);
		vector<int> a(n);
		rep(i, n) {
			char buf[100001];
			scanf("%s%d", buf, &a[i]);
			strs[i] = buf;
		}
		map<string, vi> palins;
		map<string, array<vi,2>> pairs;
		rep(i, n) {
			string s = strs[i], t = string(strs[i].rbegin(), strs[i].rend());
			if (s == t)
				palins[s].push_back(a[i]);
			else
				pairs[min(s, t)][s < t ? 0 : 1].push_back(a[i]);
		}
		int ans = 0;
		int middle = 0;
		for (auto &&p : palins) {
			vi &v = p.second;
			sort(v.rbegin(), v.rend());
			rep(i, v.size() / 2) {
				int x = v[i * 2], y = v[i * 2 + 1];
				if (x + y > 0) {
					ans += x + y;
					amax(middle, x - (x + y));
				}
				else {
					amax(middle, x);
					break;
				}
			}
			if (v.size() % 2 == 1)
				amax(middle, v.back());
		}
		ans += middle;
		for (auto &&p : pairs) {
			vi &v = p.second[0], &w = p.second[1];
			sort(v.rbegin(), v.rend());
			sort(w.rbegin(), w.rend());
			rep(i, min(v.size(), w.size())) {
				if (v[i] + w[i] <= 0) break;
				ans += v[i] + w[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}