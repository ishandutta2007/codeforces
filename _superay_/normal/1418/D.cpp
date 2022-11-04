#include <bits/stdc++.h>
using namespace std;
int n, q;
multiset<int> st, df;
inline void Add(int x) {
	multiset<int>::iterator it = st.insert(x), itl, itr;
	bool l = 0, r = 0;
	if (it != st.begin()) { l = 1; itl = it; itl--; }
	if (it != --st.end()) { r = 1; itr = it; itr++; }
	if (l && r) {
		df.erase(df.find(*itr - *itl));
	}
	if (l) {
		df.insert(x - *itl);
	}
	if (r) {
		df.insert(*itr - x);
	}
}
inline void Sub(int x) {
	multiset<int>::iterator it = st.find(x), itl, itr;
	bool l = 0, r = 0;
	if (it != st.begin()) { l = 1; itl = it; itl--; }
	if (it != --st.end()) { r = 1; itr = it; itr++; }
	if (l) {
		df.erase(df.find(x - *itl));
	}
	if (r) {
		df.erase(df.find(*itr - x));
	}
	if (l && r) {
		df.insert(*itr - *itl);
	}
	st.erase(it);
}
inline int An() {
	if (st.size() <= 2) return 0;
	else return *st.rbegin() - *st.begin() - *df.rbegin();
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		Add(x);
	}
	printf("%d\n", An());
	while (q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (!t) Sub(x);
		else Add(x);
		printf("%d\n", An());
	}
	return 0;
}