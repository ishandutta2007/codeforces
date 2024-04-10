#include <algorithm>
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

typedef long long ll;

const int MAXN = 150005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct mono {
	deque <ll> D;
	void init() {
		D.clear();
	}
	void insert(ll x) {
		while (!D.empty() && x < D.back())
			D.pop_back();
		D.push_back(x); 
	}
	void remove(ll x) {
		if (!D.empty() && D.front() == x) D.pop_front();
	}
	ll get() const {
		return D.empty() ? INF : D.front();
	}
};

int N, M, D;
ll dp[MAXN], curr[MAXN];
mono Q;

void load() {
	scanf("%d%d%d", &N, &M, &D);
}

ll solve() {
	ll sol = 0;
	int prev = 1;
	
	while (M--) { 
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t); a--;
		int diff = min((ll)(t - prev) * D, (ll)N); 
		for (int i = 0; i < diff; i++) 
			Q.insert(dp[i]);
		for (int i = 0; i < N; i++) {
			if (i + diff < N) Q.insert(dp[i + diff]);
			curr[i] = (ll)abs(a - i) + Q.get();
			if (i >= diff) Q.remove(dp[i - diff]);
		}
		for (int i = 0; i < N; i++) 
			dp[i] = curr[i];
		prev = t;
		sol += (ll)b;
		Q.init();
	}
	
	return sol - *min_element(dp, dp + N);
}

int main() {
	load();
	cout << solve() << endl;
	return 0;
}