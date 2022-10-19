#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N;
int l[MAXN], r[MAXN];
multiset <int> L, R;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", l + i, r + i);
		L.insert(l[i]);
		R.insert(r[i]);
	}
	
	int ans = 0;	
	for (int i = 0; i < N; i++) {
		L.erase(L.find(l[i]));
		R.erase(R.find(r[i]));
		ans = max(ans, *R.begin() - *L.rbegin());
		L.insert(l[i]);
		R.insert(r[i]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}