#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int>PQ;
long long s;
long long res;
int n;
struct point {
	int a, b;
	bool operator <(const point &p)const {
		return a < p.a;
	}
}w[201000];
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &w[i].a);
	for (i = 1; i <= n; i++) scanf("%d", &w[i].b);
	sort(w + 1, w + n + 1);
	int cur = 0;
	for (i = 1; i <= n; i++) {
		while (cur < w[i].a && !PQ.empty()) {
			s -= PQ.top();
			res += s;
			PQ.pop();
			cur++;
		}
		cur = w[i].a;
		s += w[i].b;
		PQ.push(w[i].b);
	}
	while (!PQ.empty()) {
		s -= PQ.top();
		res += s;
		PQ.pop();
	}
	printf("%lld\n", res);
}