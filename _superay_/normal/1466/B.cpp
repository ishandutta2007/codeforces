#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		set<int> st;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (st.count(a[i])) a[i]++;
			st.insert(a[i]);
		}
		printf("%d\n", (int)st.size());
	}
	return 0;
}