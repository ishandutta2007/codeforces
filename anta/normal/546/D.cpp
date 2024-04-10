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

vector<bool> isprime;
vector<int> primes;
void sieve(int n){
	if((int)isprime.size() >= n+1) return;
	isprime.assign(n+1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
		for(int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for(int i = 2; i <= n; i ++) if(isprime[i])
		primes.push_back(i);
}

int main() {
	int T;
	scanf("%d", &T);
	const int X = 5000000;
	sieve(X);
	vector<int> cnt(X+1, 0);
	each(pi, primes) {
		int p = *pi;
		int t = p;
		while(1) {
			for(int i = t; i <= X; i += t)
				++ cnt[i];
			if((ll)t * p > X) break;
			t *= p;
		}
	}
	vector<ll> factcnt(X+1, 0);
	for(int i = 1; i <= X; ++ i)
		factcnt[i] = factcnt[i-1] + cnt[i];
	rep(ii, T) {
		int a, b;
		scanf("%d%d", &a, &b);
		ll ans = factcnt[a] - factcnt[b];
		printf("%I64d\n", ans);
	}
	return 0;
}