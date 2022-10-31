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

template<typename T>T gcd_positive(T x, T y) { return y == 0 ? x : gcd_positive(y,x%y); }
template<typename T>T gcd(T x, T y) { return gcd_positive(abs(x), abs(y)); }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vi> w(n, vi(m));
	rep(i, n) rep(j, m)
		scanf("%d", &w[i][j]);
	vector<int> b = w[0];
	ll g = 0;
	rep(i, n) {
		vector<ll> t(m);
		rep(j, m)
			t[j] = w[i][j] - b[j];
			//a[i] + b[j] = w[i][j] + c k
			//a[i] = (w[i][j] - b[j]) + c k
		rep(j, m) rep(l, j)
			g = gcd(g, t[j] - t[l]);
	}
	ll k = g == 0 ? (ll)1e18 : g;
	vector<ll> a(n);
	rep(i, n)
		a[i] = ((w[i][0] - b[0]) % k + k) % k;
	bool ok = true;
	rep(i, n) rep(j, m) {
		ll t = (a[i] + b[j]) % k;
		if(w[i][j] % k != t) cerr << "err" << endl;
		ok &= w[i][j] == t;
	}
	if(!ok) {
		puts("NO");
	}else {
		puts("YES");
		cout << k << endl;
		rep(i, n) cout << a[i] << " ";
		cout << endl;
		rep(i, m) cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}