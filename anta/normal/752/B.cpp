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
	string s, t;
	while (cin >> s >> t) {
		vi perm(128);
		rep(i, 128) perm[i] = i;
		rep(i, s.size()) if (s[i] != t[i]) {
			perm[s[i]] = t[i];
			perm[t[i]] = s[i];
		}
		vpii ans;
		rep(i, 128) if (i < perm[i])
			ans.emplace_back(i, perm[i]);
		vector<int> cnt(128);
		rep(i, 128) perm[i] = i;
		for (auto p : ans) {
			++cnt[p.first];
			++cnt[p.second];
			swap(perm[p.first], perm[p.second]);
		}
		string u;
		rep(i, s.size())
			u += perm[s[i]];
		bool ok = u == t;
		rep(i, 128) ok &= cnt[i] <= 1;
		if (!ok) {
			puts("-1");
		}
		else {
			printf("%d\n", (int)ans.size());
			rep(i, ans.size())
				printf("%c %c\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}