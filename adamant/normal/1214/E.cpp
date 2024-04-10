#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int d[n];
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int a, int b){return d[a] > d[b];});
	deque<int> st(n, 0);
	for(int i = 0; i < n; i++) {
		st[i] = {2 * p[i] + 1};
	}
	for(int i = 1; i < n; i++) {
		cout << st[i - 1] << ' ' << st[i] << "\n";
	}
	for(int i = 0; i < n; i++) {
		if(st[0] != 2 * p[i] + 1) {
			st.push_front(2 * p[i - 1] + 1);
			st.push_front(2 * p[i] + 1);
		}
		while((int)st.size() > d[p[i]]) {
			st.pop_back();
		}
		cout << st.back() << ' ' << 2 * p[i] + 2 << "\n";
		st.push_back(2 * p[i] + 2);
		st.pop_front();
	}
    return 0;
}