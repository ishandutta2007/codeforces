#include<bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		vector<int> s1, s2;
		while (u) s1.push_back(u & -u), u -= u & -u;
		while (v) s2.push_back(v & -v), v -= v & -v;
		if (s1.size() < s2.size()) {
			puts("NO");
			continue;
		}
		int flag = 1;
		while (s1.size() && flag) {
			if (s2.empty()) {
				flag = 0, puts("NO");
				continue;
			}
			int u0 = *(s1.end()-1), v0 = *(s2.end()-1);
			if (u0 > v0) {
				flag = 0, puts("NO");
				continue;
			}
			if (u0 == v0 || s1.size() == s2.size()) s1.pop_back(), s2.pop_back();
			else s2.pop_back(), s2.push_back(v0>>1), s2.push_back(v0>>1);
		}
		if (flag) puts("YES");
	}
}