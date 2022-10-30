#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

inline int signum1(ll x) { return x >= 0 ? 1 : -1; }

int main() {
	int n; int k; int x;
	while(~scanf("%d%d%d", &n, &k, &x)) {
		vector<long long> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%lld", &a[i]);
		priority_queue<pair<ll, int>> pq;
		int sign = 1;
		rep(i, n) {
			sign *= signum1(a[i]);
			pq.push(make_pair(-abs(a[i]), i));
		}
		while(k > 0) {
			int i = pq.top().second;
			pq.pop();
			int s = sign * signum1(a[i]);
			if(s == 1)
				a[i] -= x;
			else
				a[i] += x;
			sign = s * signum1(a[i]);
			-- k;
			pq.push(make_pair(-abs(a[i]), i));
		}
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%lld", a[i]);
		}
		puts("");
	}
	return 0;
}