#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	string s, t;
	while(cin >> s >> t) {
		int hn = s.size();
		s = s + "$" + string(s.rbegin(), s.rend());
		int n = s.size(), m = t.size();
		vector<vector<short> > lcp(n + 1, vector<short>(m + 1));
		for(int i = n - 1; i >= 0; -- i)
			for(int j = m - 1; j >= 0; -- j)
				lcp[i][j] = s[i] == t[j] ? lcp[i + 1][j + 1] + 1 : 0;
		vpii ans;
		int pos = 0;
		while(pos < m) {
			pii a(0, INF);
			rep(i, n)
				amax(a, mp((int)lcp[i][pos], i));
			if(a.first == 0) {
				ans.clear();
				break;
			}
			int i = a.second;
			if(i < hn)
				ans.emplace_back(i + 1, i + a.first);
			else {
				int k = hn - (i - (hn + 1) + a.first);
				ans.emplace_back(k + a.first, k + 1);
			}
			pos += a.first;
		}
		if(ans.empty()) {
			puts("-1");
		} else {
			printf("%d\n", (int)ans.size());
			for(int i = 0; i < (int)ans.size(); ++ i) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
	}
	return 0;
}