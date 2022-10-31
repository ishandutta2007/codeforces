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
	//sum[i+k] - sum[i] < sum[i+k+1] - sum[i+1]
	//sum[i+k+1] - sum[i+k] > sum[i+1] - sum[i]
	//a[i] < a[i+k]
	//disjoint paths
	//?segment
	int n, k;
	scanf("%d%d", &n, &k);
	const int Q = -INF;
	vector<vi> paths(k);
	char buf[20];
	rep(i, n) {
		scanf("%s", buf);
		if(*buf == '?') {
			paths[i % k].push_back(Q);
		}else {
			int a;
			sscanf(buf, "%d", &a);
			paths[i % k].push_back(a);
		}
	}
	assert(-INF + 100100 < -(int)1e9);
	vector<int> ans(n);
	rep(i, k) {
		const vi &v = paths[i];
		int cursegj = 0;
		rep(j, v.size()+1) {
			int a = j == v.size() ? INF : v[j];
			if(a == Q) {

			}else {
				int b = cursegj == 0 ? -INF : v[cursegj-1];
				int len = j - cursegj;
				if(b + len >= a) {
					puts("Incorrect sequence");
					return 0;
				}
				if(cursegj != j) {
					//b + 1 <= t <= a - len
					//minimize. sum_{i=0}^{len-1} |t+i|
					//median of [-len+1..0]
					int median = -(len / 2);
					int t;
					if(median < b + 1) {
						t = b + 1;
					}else if(a - len < median) {
						t = a - len;
					}else {
						t = median;
					}
					assert(b < t && t + len - 1 < a);
					rep(p, len)
						ans[(cursegj + p) * k + i] = t + p;
				}
				if(j != v.size()) {
					ans[j * k + i] = a;
					cursegj = j + 1;
				}
			}
		}
	}
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}