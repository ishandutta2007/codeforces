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

int T, n;
int memo[102][1001];
vector<vi> tasks;
int rec(int depth, int nodes) {
	int &r = memo[depth][nodes];
	if(r != -1) return r;
	if(depth == T+1 || nodes == 0)
		return r = 0;
	r = 0;
	int m = min(nodes, (int)tasks[depth].size()), sum = 0;
	rer(i, 0, m) {
		amax(r, sum + rec(depth+1, min(n, (nodes - i) * 2)));
		if(i < m) sum += tasks[depth][i];
	}
	return r;
}

int main() {
	scanf("%d%d", &n, &T);
	tasks.assign(T+1, vi());
	rep(i, n) {
		int t, q;
		scanf("%d%d", &t, &q);
		tasks[T - t].push_back(q);
	}
	rer(i, 0, T)
		sort(all(tasks[i]), greater<int>());
	mset(memo, -1);
	int ans = rec(0, 1);
	printf("%d\n", ans);
	return 0;
}