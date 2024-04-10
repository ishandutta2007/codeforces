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
	//0,1,2,3-3m,4-3m,5-3m,6-3m...
	int n;
	scanf("%d", &n);
	vector<vi> students(n);
	rep(i, n) {
		int a;
		scanf("%d", &a);
		students[a].push_back(i);
	}
	vi ans;
	int j = 0;
	rep(i, n) {
		while(students[j].empty() && j >= 3)
			j -= 3;
		if(students[j].empty()) {
			puts("Impossible");
			return 0;
		}
		ans.push_back(students[j].back());
		students[j].pop_back();
		++ j;
	}
	puts("Possible");
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
	return 0;
}