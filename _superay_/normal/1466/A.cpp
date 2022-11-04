#include <bits/stdc++.h>
using namespace std;
int n, a[55];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		set<int> st;
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) st.insert(a[j] - a[i]);
		printf("%d\n", (int)st.size());
	}
	return 0;
}