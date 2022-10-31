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
	//\sum_{d=0}^{m-1} (n-d)(m-d)
	// = m (m+1) (3n-m+1) / 6
	//m (m+1) (3n-m+1) / 6 = x
	//n = (m^3-m+6x)/(3m(m+1))
	ll x;
	while(cin >> x) {
		vector<pair<ll, ll> > ans;
		for(int m = 1;; ++ m) {
			unsigned long long num = 1ULL * m * m * m - m + 6ULL * x;
			unsigned long long den = 3ULL * m * (m + 1);
			unsigned long long n = num / den;
//			cerr << m << ": " << n << endl;
			if(n < m) break;
			if(n * den == num) {
				ans.push_back(mp(n, m));
				if(m != n)
					ans.push_back(mp(m, n));
			}
		}
		sort(all(ans));
		cout << ans.size() << endl;
		each(i, ans)
			cout << i->first << " " << i->second << endl;
	}
	return 0;
}