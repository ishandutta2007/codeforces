#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

vector<bool> isprime;
vector<int> primes;
void sieve(int n) {
	if ((int)isprime.size() >= n + 1) return;
	isprime.assign(n + 1, true);
	isprime[0] = isprime[1] = false;
	int sqrtn = (int)(sqrt(n * 1.) + .5);
	for (int i = 2; i <= sqrtn; i ++) if (isprime[i]) {
		for (int j = i * i; j <= n; j += i)
			isprime[j] = false;
	}
	primes.clear();
	for (int i = 2; i <= n; i ++) if (isprime[i])
		primes.push_back(i);
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		sieve(n + 1);
		vi ans;
		if (n <= 2) {
			rep(i, n)
				ans.push_back(1);
		} else {
			rer(i, 2, n + 1)
				ans.push_back(isprime[i] ? 1 : 2);
		}
		printf("%d\n", *max_element(ans.begin(), ans.end()));
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}