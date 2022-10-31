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

vector<int> mobiusMu;
void calcMobiusMu() {
	int n = (int)isprime.size() - 1;
	mobiusMu.assign(n+1, 1);
	for(int i = 2; i <= n; i ++) if(isprime[i]) {
		if((ll)i * i <= n) {
			for(int j = i * i; j <= n; j += i * i)
				mobiusMu[j] = 0;
		}
		for(int j = i; j <= n; j += i)
			mobiusMu[j] *= -1;
	}
}

template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}

int main() {
	const int X = 500000;
	sieve(X);
	calcMobiusMu();
	
	vector<vi> divisors(X+1);
	rer(i, 1, X) for(int j = i; j <= X; j += i)
		divisors[j].push_back(i);

	int n, q;
	while(1) {
		scanf("%d%d", &n, &q);
//		n=rand()%10+1,q=rand()%20+1;
		vector<int> a(n);
		rep(i, n) {
			scanf("%d", &a[i]);
//			a[i]=83160;
//			a[i]=rand()%X+1;
		}

		vector<bool> present(n, false);
		int cnt = 0;
		vector<int> cnts(X+1, 0), divcnt(X+1, 0);
		ll pairs = 0;
		rep(ii, q) {
			int xi;
			scanf("%d", &xi), -- xi;
//			xi=rand()%n;
			int x = a[xi];
			if(!present[xi]) {
				present[xi] = true;
				++ cnt, ++ cnts[x];

				each(di, divisors[x]) {
					int d = *di;
					pairs += divcnt[d] * mobiusMu[d];
					++ divcnt[d];
				}
			}else {
				each(di, divisors[x]) {
					int d = *di;
					-- divcnt[d];
					pairs -= divcnt[d] * mobiusMu[d];
				}

				present[xi] = false;
				-- cnt, -- cnts[x];
			}
			/*
			ll naivepairs = 0;
			rep(i, n) if(present[i])
			rep(j, i) if(present[j])
			if(gcd(a[i], a[j]) == 1)
				naivepairs += 1;

			if(naivepairs != pairs)
				cerr << naivepairs << " != " << pairs << endl;
			*/
			printf("%I64d\n", pairs);
		}
		break;
	}
	return 0;
}