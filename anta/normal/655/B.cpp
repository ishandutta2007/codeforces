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

struct FenwickTree {
	typedef int T;
	vector<T> v;
	FenwickTree(int n) : v(n, 0) {}
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};

long long inversionNumber(int x[], int n) {
	int *c = new int[n];
	memcpy(c, x, sizeof(*x) * n);
	sort(c, c + n);
	int m = unique(c, c + n) - c;
	FenwickTree ft(m);
	long long res = 0;
	for(int i = n - 1; i >= 0; i --) {
		int idx = lower_bound(c, c + m, x[i]) - c;
		res += ft.sum(idx);
		ft.add(idx, 1);
	}
	delete[] c;
	return res;
}

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vi a(n);
		rep(i, n) a[i] = i;
		rep(j, min(k, n / 2)) {
			swap(a[j], a[n-1-j]);
		}
		ll ans = inversionNumber(&a[0], n);
		printf("%lld\n", ans);
	}
	return 0;
}