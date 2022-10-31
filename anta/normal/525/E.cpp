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
	int N, K; long long S;
	cin >> N >> K >> S;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	vector<long long> facts(N);
	rep(i, N) {
		int c = a[i];
		long long p = 1;
		if(c > 18) {
			p = 10000000000000001;
		}else {
			rer(j, 1, c)
				p *= j;
		}
		facts[i] = p;
	}
	int n1 = N / 2, n2 = N - n1;
	vector<vector<long long> > halfs(K+1);
	rep(i, 1 << n1) for(int j = i; ; (-- j) &= i) {
		long long sum = 0; int p = 0;
		rep(k, n1) if(i >> k & 1) {
			if(j >> k & 1) {
				sum += facts[k];
				++ p;
			}else {
				sum += a[k];
			}
		}
		if(sum <= S && p <= K) {
			rer(k, 0, K - p)
				halfs[k].push_back(sum);
		}

		if(j == 0) break;
	}
	rer(k, 0, K)
		sort(all(halfs[k]));
	long long ans = 0;
	rep(i, 1 << n2) for(int j = i; ; (-- j) &= i) {
		long long sum = 0; int p = 0;
		rep(k, n2) if(i >> k & 1) {
			if(j >> k & 1) {
				sum += facts[n1+k];
				++ p;
			}else {
				sum += a[n1+k];
			}
		}
		if(sum <= S && p <= K) {
			const vector<long long> &v = halfs[p];
			pair<vector<long long>::const_iterator,vector<long long>::const_iterator> p = equal_range(all(v), S - sum);
			ans += p.second - p.first;
		}

		if(j == 0) break;
	}
	cout << ans << endl;
	return 0;
}