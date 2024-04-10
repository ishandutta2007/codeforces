#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back

int T;
int A[2000020];

int main() {
	scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			int x; scanf("%d", &x);
			A[x]++;
		}
		vector <int> w;
		for(int i=1;i<=n;i++) if(A[i]) w.pb(A[i]);
		sort(w.begin(), w.end());
		ll ans = 1e18;
		for(int s=1;s<=w[0]+1;s++) {
			int can = 1;
			ll sum = 0;
			for(int x : w) {
				if(s == 1) sum += x;
				else {
					int rv = x / (s - 1);
					int lv = (x + s - 1) / s;
					if(lv > rv) can = 0;
					else sum += lv;
				}
			}
			if(can) ans = min(ans, sum);
		}
		printf("%lld\n", ans);

		for(int i=1;i<=n;i++) A[i] = 0;
	}
	return 0;
}