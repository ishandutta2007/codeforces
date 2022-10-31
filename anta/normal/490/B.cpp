#define _CRT_SECURE_NO_WARNINGS
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
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n;
	scanf("%d", &n);
	const int X = 1000001;
	vector<int> nxt(X, -1), prv(X, -1);
	vi v;
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		nxt[a] = b;
		prv[b] = a;
		v.push_back(a);
	}
	vi ans1, ans2;
	for(int x = nxt[0]; x > 0; x = nxt[x])
		ans2.push_back(x);
	int head = -1;
	each(i, v)
		if(prv[*i] == -1)
			head = *i;
	for(int x = head; x > 0; x = nxt[x])
		ans1.push_back(x);
	vi ans;
	rep(i, n / 2) {
		ans.pb(ans1[i]);
		ans.pb(ans2[i]);
	}
	if(n % 2 != 0)
		ans.push_back(ans1.back());
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}