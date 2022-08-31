#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int T;
int N, M, K;
int A[40];
char buf[200020];
int d1[200020];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &N, &M, &K);
		memset(A, 0, sizeof A);
		scanf("%s", buf+1);
		for(int i=1;i<=K;i++) {
			int c = buf[i] - 'A' + 1;
			A[c]++;
		}
		ll ans = 1e18;
		for(int i=1;i<=26;i++) {
			rep(j, K + 2) d1[j] = 0;
			d1[0] = 1;
			for(int j=1;j<=26;j++) if(j != i) {
				for(int k=K;k>=A[j];k--) {
					d1[k] |= d1[k-A[j]];
				}
			}
			int x = A[i];
			for(int ni=N;ni+x>=N && ni>=0;ni--) if(d1[ni]) {
				ll t2 = x - (N - ni) - (K - M - N);
				if(t2 <= 0) ans = 0;
				else ans = min(ans, (ll)(N - ni) * t2);
			}
			for(int mi=M;mi+x>=M && mi>=0;mi--) if(d1[mi]) {
				ll t2 = x - (M - mi) - (K - M - N);
				if(t2 <= 0) ans = 0;
				else ans = min(ans, (ll) (M - mi) * t2);
			}
		}

		printf("%lld\n", ans);
	}
}