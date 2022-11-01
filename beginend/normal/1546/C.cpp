#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<int> a, b;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if (i & 1) a.push_back(x);
			else b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> c;
		for (int i = 0; i < a.size(); i++) {
			c.push_back(a[i]);
			if (i < b.size()) c.push_back(b[i]);
		}
		bool flag = 0;
		for (int i = 0; i < n - 1; i++)
			if (c[i] > c[i + 1]) {
				flag = 1;
				puts("NO");
				break;
			}
		if (!flag) puts("YES");
	}
	return 0;
}