#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
 
int N, Q;
int a[MAXN], cnt[MAXN];
map <pii, int> res;
ll ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", a + i);
		ans += a[i];
	}
	
	scanf("%d", &Q);
	while (Q--) {
		int s, t, u;
		scanf("%d%d%d", &s, &t, &u);
		int &ref = res[{s, t}];
		if (ref) {
			if (cnt[ref] <= a[ref])
				ans++;
			cnt[ref]--;
		}
		if (u) {
			if (cnt[u] < a[u])
				ans--;
			cnt[u]++;
		}
		ref = u;
		printf("%lld\n", ans);
	}
	
	return 0;
}