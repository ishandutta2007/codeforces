#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
	int n;
	string t;
	cin >> n;
	cin >> t;
 
	vector<int> edge(26, -1);
	vector<int> redge(26, -1);
	auto get_path_end = [&](int c) {
		int len = 0;
		int cur = c;
		while (edge[cur] != -1)
			len++, cur = edge[cur];
		return make_pair(cur, len);
	};
	vector<int> vec;
	for (auto c : t)
		vec.push_back(c - 'a');
	for (int i = 0; i < n; i++) {
		if (edge[vec[i]] == -1) {
			for (int c = 0; c < 26; c++)
				if (redge[c] == -1) {
					auto [clast, len] = get_path_end(c);
					if (clast != vec[i] || len == 25) {
						edge[vec[i]] = c;
						redge[c] = vec[i];
						break;
					}
				}
		}
		vec[i] = edge[vec[i]];
	}
 
	for (int i = 0; i < n; i++)
		t[i] = vec[i] + 'a';
 
	cout << t << '\n';
}
 
int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();
 
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}