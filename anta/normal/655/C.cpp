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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		string s;
		cin >> s;
		vi sum(n + 1);
		rep(i, n)
			sum[i + 1] = sum[i] + (s[i] == '0');
		int l = 0, u = n;
		while(u - l > 0) {
			int mid = (l + u) / 2;
			bool ok = false;
			rep(i, n) if(s[i] == '0') {
				int num = 0;
				num += sum[i] - sum[max(0, i - mid)];
				num += sum[min(n, i + 1 + mid)] - sum[i + 1];
				ok |= num >= k;
			}
			if(ok)
				u = mid;
			else
				l = mid + 1;
		}
		printf("%d\n", u);
	}
	return 0;
}