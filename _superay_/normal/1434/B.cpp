#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, ty[N], b[N];
vector<int> v1, v2;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		char ch;
		scanf(" %c", &ch);
		if (ch == '+') {
			ty[i] = 1;
			v1.push_back(i);
		} else {
			ty[i] = 2;
			scanf("%d", &b[i]);
			v2.push_back(i);
		}
	}
	set<int> st;
	for (int i = 2 * n; i >= 1; i--) {
		if (ty[i] == 1) {
			if (st.empty()) {
				puts("NO");
				return 0;
			}
			b[i] = *st.begin();
			st.erase(st.begin());
		} else {
			st.insert(b[i]);
		}
	}
	st.clear();
	for (int i = 1; i <= 2 * n; i++) {
		if (ty[i] == 1) {
			st.insert(b[i]);
		} else {
			if (st.empty() || *st.begin() != b[i]) {
				puts("NO");
				return 0;
			}
			st.erase(st.begin());
		}
	}
	puts("YES");
	for (int i = 1; i <= 2 * n; i++) if (ty[i] == 1) printf("%d ", b[i]);
	return 0;
}