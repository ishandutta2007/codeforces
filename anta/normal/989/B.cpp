#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int p;
	while (~scanf("%d%d", &n, &p)) {
		char S[2001];
		scanf("%s", S);
		bool ans = false;
		for (int s = 0; s < p; ++ s) {
			vector<int> ids[3];
			for (int i = s; i < n; i += p) {
				char c = S[i];
				ids[c == '.' ? 2 : c - '0'].push_back(i);
			}
			int x = (int)(ids[0].size() + ids[1].size() + ids[2].size());
			if (x <= 1) continue;
			int k = !ids[0].empty() ? 0 : 1;
			if (!ids[1 - k].empty()) {
				ans = true;
			} else if (ids[k].empty()) {
				assert((int)ids[2].size() >= 2);
				S[ids[2][0]] = '0';
				S[ids[2][1]] = '1';
				ans = true;
			} else if (!ids[2].empty()) {
				S[ids[2][0]] = '0' + (1 - k);
				ans = true;
			}
		}
		if (!ans) {
			puts("No");
		} else {
			for (int i = 0; i < n; ++ i) if (S[i] == '.')
				S[i] = '0';
			puts(S);
		}
	}
}