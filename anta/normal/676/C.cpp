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

template<typename T>
vector<pair<T, int> > runLength(const T a[], int n) {
	vector<pair<T, int> > r;
	if(n <= 0) return r;
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(i == n || (i != 0 && a[i] != a[i - 1])) {
			r.push_back(make_pair(a[i - 1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		string s;
		cin >> s;
		int ans = 0;
		rep(rev, 2) {
			rep(ab, 2) {
				auto runs = runLength(s.c_str(), n);
				int remk = k, len = 0, j = 0;
				rep(i, runs.size()) {
					for(; remk >= 0 && j != runs.size(); ++ j) {
						len += runs[j].second;
						if(runs[j].first != 'a') {
							remk -= runs[j].second;
						}
					}
					int t = len + min(0, remk);
					amax(ans, t);

					if(runs[i].first != 'a') {
						remk += runs[i].second;
					}
					len -= runs[i].second;
				}


				rep(i, n) s[i] = s[i] == 'a' ? 'b' : 'a';
			}
			reverse(all(s));
		}
		printf("%d\n", ans);
	}
	return 0;
}