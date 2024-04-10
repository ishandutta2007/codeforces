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
	char *s = new char[200001], *t = new char[200001];
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	vector<int> cnt1(128, 0), cnt2(128, 0);
	rep(i, n) ++ cnt1[s[i]];
	rep(i, m) ++ cnt2[t[i]];
	int yey = 0, whoops = 0;
	rep(a, 128) {
		int t = min(cnt1[a], cnt2[a]);
		cnt1[a] -= t, cnt2[a] -= t;
		yey += t;
	}
	rep(a, 128) if(islower(a) || isupper(a)) {
		int b = islower(a) ? toupper(a) : tolower(a);
		int t = min(cnt1[a], cnt2[b]);
		cnt1[a] -= t, cnt2[b] -= t;
		whoops += t;
	}
	printf("%d %d\n", yey, whoops);
	return 0;
}