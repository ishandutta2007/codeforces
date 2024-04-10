#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int N, B, K, X;
const int MOD = (ll)1e9 + 7;

vector<int> multiply (vector<int> p, vector<int> q, int m) {
	vector<int> ret(X);
	for(int i = 0; i < X; i++) for(int j = 0; j < X; j++) {
		int t = (i + j * m) % X;
		ret[t] = ((ll)ret[t] + (ll)p[i] * q[j]) % MOD;
	}
	return ret;
};

int main() {
	scanf("%d%d%d%d", &N, &B, &K, &X);

	vector<int> cnt(X);
	for(int i = 0; i < N; i++) {
		int a; scanf("%d", &a);
		cnt[a % X]++;
	}

	vector<int> cur = cnt;
	vector<int> ans;
	ll m = 1;
	ll b = 10;
	for(int k = 0; k < 30; k++) {
		if((B >> k) & 1) {
			if(ans.empty()) ans = cur;
			else ans = multiply(ans, cur, m);
			m = (m * b) % X;
		}
		cur = multiply(cur, cur, b);
		b = (b * b) % X;
	}

	printf("%d\n", ans[K]);
    return 0;
}