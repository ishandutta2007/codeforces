#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX = 11;
const int LOG = 65;

ll dp[MAX][LOG][1 << MAX];

void init() {
	for (int i = 2; i < MAX; i++) {
		dp[i][0][0] = 1;
		for (int j = 1; j < LOG; j++)
			for (int k = 0; k < 1 << i; k++)
				for (int l = 0; l < i; l++)
					dp[i][j][k] += dp[i][j - 1][k ^ 1 << l];
	}
}

ll calc(int base, ll x) {
	if (!x)
		return 0;
		
	vector <int> d;
	for (; x; x /= base)
		d.push_back(x % base);
	reverse(d.begin(), d.end());
	
	int mask = 0;
	ll res = 0;
	int len = d.size();
	for (int i = 0; i < len - 1; i++)
		for (int j = 1; j < base; j++)
			res += dp[base][len - i - 2][1 << j];
			
	for (int i = 0; i < len; i++) {
		for (int j = !i; j < d[i]; j++) 
			res += dp[base][len - i - 1][mask ^ 1 << j];
		mask ^= 1 << d[i];
	}
	
	if (!mask)
		res++;
	
	return res;
}

int main() {
	init();
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int b;
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", calc(b, r) - calc(b, l - 1));
	}
	return 0;
}