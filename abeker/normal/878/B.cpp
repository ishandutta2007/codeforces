#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, K, M;
int a[MAXN];
deque <pii> d;

void load() {
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

ll solve() {
	for (int i = 0; i < N; i++) {
		if (d.empty() || a[i] != d.back().first)
			d.push_back({a[i], 0});
		d[(int)d.size() - 1].second++;
		d[(int)d.size() - 1].second %= K;
		if (!d.back().second)
			d.pop_back();
	}
	
	int len = 0;
	for (auto it : d)
		len += it.second;
		
	ll tot = (ll)M * len;
	int sum = 0;
	while (!d.empty()) {
		if (d.size() == 1) {
			int rest = (ll)M * d[0].second % K;
			if (rest)
				return rest + sum;
			return 0;
		}
		pii a = d.front();
		pii b = d.back();
		if (a.first != b.first)
			return tot;
		int tmp = a.second + b.second;
		tot -= (ll)(M - 1) * (tmp - tmp % K);
		if (tmp % K)
			return tot;
		d.pop_front();
		d.pop_back();
		sum += tmp;
	}
	
	return tot;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}