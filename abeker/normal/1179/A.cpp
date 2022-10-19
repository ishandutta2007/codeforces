#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;	

int N, Q;
deque <int> a;
pii ans[MAXN];

void out(pii p) {
	printf("%d %d\n", p.first, p.second);
}

int main() {
	scanf("%d%d", &N, &Q);
	a.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
		
	int mx = *max_element(a.begin(), a.end());
	int ptr = 0;
	for (; a.front() != mx; ptr++) {
		ans[ptr] = {a[0], a[1]};
		int x = a[0];
		int y = a[1];
		a.pop_front();
		a.pop_front();
		a.push_front(max(x, y));
		a.push_back(min(x, y));
	}
	
	while (Q--) {
		ll m;
		scanf("%lld", &m);
		m--;
		if (m < ptr)
			out(ans[m]);
		else {
			m -= ptr;
			out({mx, a[m % (N - 1) + 1]});
		}
	}
	
	return 0;
}