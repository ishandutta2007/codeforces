#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

const int MAXN = 400005;
const ll INF = 1e18;

int N;
ll C;
ll s[MAXN];
deque <ll> Q;
ll dp[MAXN];

void load() {
	scanf("%d%lld", &N, &C);
	for (int i = 1; i < 2 * N; i++) {
		scanf("%lld", s + i);
		s[i] += s[i - 1];
	}
}

void remove(ll val) {
	if (!Q.empty() && val == Q.front())
		Q.pop_front();
}

void add(ll val) {
	while (!Q.empty() && val > Q.back())
		Q.pop_back();
	Q.push_back(val);
}

ll query() {
	return Q.empty() ? -INF : Q.front();
}

ll solve() {
	add(0);
	int ptr = 0;
	for (int i = 2; i <= 2 * N; i += 2) {
		for (; ptr < i && s[i - 1] - s[ptr] > C; ptr += 2) 
			remove(dp[ptr] - s[ptr]);
		if (ptr) 
			dp[i] = max(dp[i], dp[ptr - 2] + C);
		dp[i] = max(dp[i], query() + s[i - 1]);
		add(dp[i] - s[i]);
	}
	
	return dp[2 * N];
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}