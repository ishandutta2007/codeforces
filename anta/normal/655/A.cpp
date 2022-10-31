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

void canon(string a[2]) {
	if(a[1][1] == 'X')
		swap(a[0][1], a[1][1]);
	if(a[0][1] == 'X')
		swap(a[0][0], a[0][1]);
	if(a[1][0] == 'X')
		swap(a[0][0], a[1][0]);
}

int main() {
	string a[4];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		canon(a);
		canon(a + 2);
		bool ans = false;
		rep(rot, 4) {
			ans |= a[0] == a[2] && a[1] == a[3];
			swap(a[0][0], a[0][1]);
			swap(a[0][1], a[1][1]);
			swap(a[1][1], a[1][0]);
			swap(a[1][0], a[0][0]);
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}