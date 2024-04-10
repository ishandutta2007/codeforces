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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	const int D = 100;
	vi ns(D+1);
	vector<vpii> graphs(D+1);
	rer(d, 1, 100) {
		rer(n, 1, 200) {
			vpii a(n);
			rep(i, n) a[i] = mp(i == 0 ? d - 1 : d, i);
			reverse(all(a));
			bool ok = true;
			ok &= ((d - 1) + d * (n-1)) % 2 == 0;
			rer(k, 1, n) {
				int t = 0, u = k * (k-1);
				rep(i, k) t += a[i].first;
				reu(i, k, n) u += min(a[i].first, k);
				ok &= t <= u;
			}
			if(ok) {
//				cerr << d << ": " << n << endl;
				vpii edges;
				rep(k, n) {
					sort(all(a)); reverse(all(a));
					rep(l, a[0].first) {
//						cerr << a[0].second + 1 << ", " << a[l+1].second << endl;
						if(l+1 >= n || a[l+1].first == 0) {
							cerr << "err " << k << ", " << a[0].first << ", " << l+1 << endl;
						}
						edges.push_back(mp(a[0].second, a[l+1].second));
						-- a[l+1].first;
					}
					a[0].first = 0;
				}
				ns[d] = n;
				graphs[d] = edges;
				break;
			}
		}
	}
	int d;
	while(cin >> d) {
		vpii es = graphs[d];
		int n = ns[d] * 2;
		if(n == 0) {
			puts("NO");
			continue;
		}
		vpii ans;
		each(i, es) {
			ans.push_back(*i);
			ans.push_back(mp(i->first + ns[d], i->second + ns[d]));
		}
		ans.push_back(mp(0, ns[d]));
		cout << "YES" << endl;
		cout << n << " " << ans.size() << endl;
		each(i, ans)
			printf("%d %d\n", i->first + 1, i->second + 1);
	}
	return 0;
}