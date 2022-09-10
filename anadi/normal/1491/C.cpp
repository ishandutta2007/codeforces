#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int n;
int in[N];
int rep[N];

int Find(int a) {
	if(a == rep[a])
		return a;
	return rep[a] = Find(rep[a]);
}

void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		rep[i] = (in[i] == 1 and i < n) ? i + 1 : i;
	}
	
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == n) {
			ans += in[i] - 1;
			break;
		}

		if(in[i] > n - i) {
			ans += in[i] - (n - i);
			in[i] = n - i;
		}
		
		while(in[i] > 1) {
			ans++;
			int cur = i;
			while(cur <= n) {
				cur = Find(cur);
				int len = in[cur];
				in[cur] = max(in[cur] - 1, 1);
				
				if(len == 2 and cur < n)
					rep[cur] = cur + 1;
				cur += len;
			}
		}
	}
	
	printf("%lld\n", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}