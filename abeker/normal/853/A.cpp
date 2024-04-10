#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 300005;

int N, K;
pii p[MAXN];
set <int> S;
int sol[MAXN];

bool cmp(const pii &lhs, const pii &rhs) {
	if (lhs.first != rhs.first)
		return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i + 1;
	}
	
	sort(p, p + N, cmp);

	for (int i = 0; i < N; i++)
		S.insert(i + 1);
	
	ll sum = 0;	
	for (int i = 0; i < N; i++) {
		auto it = S.lower_bound(p[i].second - K);
		sol[p[i].second] = K + *it;
		S.erase(it);	
		sum += (ll)p[i].first * (sol[p[i].second] - p[i].second);	
	}
	
	printf("%lld\n", sum);
	for (int i = 1; i <= N; i++)
		printf("%d ", sol[i]);
	puts("");
	
	return 0;
}