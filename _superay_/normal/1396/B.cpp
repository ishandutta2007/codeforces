#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		multiset<int> st;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), st.insert(a[i]);
		int tmp = 0, c = 0;
		while (true) {
			if (!st.size()) break;
			int x = *st.rbegin();
			st.erase(--st.end());
			if (tmp) st.insert(tmp);
			tmp = x - 1;
			c ^= 1;
		}
		if (!c) puts("HL");
		else puts("T");
	}
	return 0;
}