#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];
multiset <int> all;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", a + i);
		all.insert(a[i]);
	}
	
	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		all.erase(all.find(a[i]));
		ans = min(ans, *all.rbegin() - *all.begin());
		all.insert(a[i]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}