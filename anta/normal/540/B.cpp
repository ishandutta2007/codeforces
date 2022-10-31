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
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	vi a(k), b(n-k);
	rep(i, k) cin >> a[i];
	int sum = accumulate(all(a), 0);
	int num = 0;
	rep(i, k) num += a[i] >= y;
	int t = max(0, min(n - k, (n + 1) / 2 - num));
	rep(i, t)
		b[i] = y;
	reu(i, t, n - k)
		b[i] = 1;
	bool ok = true;
	vi v = a; v.insert(v.end(), all(b));
	sort(all(v));
	ok &= v[n / 2] >= y;
	ok &= accumulate(all(v), 0) <= x;
	if(!ok) {
		puts("-1");
	}else {
		rep(i, n-k) {
			if(i != 0) cout << " ";
			cout << b[i];
		}
		cout << endl;
	}
	return 0;
}