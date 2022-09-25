#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

string s[MX];
vector<int> pos[MX];
int a[MX], len[MX];
char S[MX + 1], ans[2 * MX + 1];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, k; i < n; i++) {
		ignore = scanf(" %s %d", S, &k);
		s[i] = S;
		while (k--) {
			int x;
			ignore = scanf("%d", &x);
			pos[i].push_back(x - 1);
		}
		
		a[i] = i;
		len[i] = s[i].length();
	}
	
	sort(a, a + n, [&](int a, int b) -> bool { return len[a] > len[b]; });
	
	set<int> f;
	for (int i = 0; i <= 2 * MX; i++) f.insert(i);
	
	int ansLen = 0;
	for (int i = 0; i < n; i++) {
		int j = a[i];
		
		for (int x : pos[j]) {
			auto it = f.lower_bound(x);
			if (it == f.end()) continue;
			for (int k = *it - x; k < len[j] && ans[x + k] == 0; k++) {
				ans[x + k] = s[j][k];
				ansLen = max(ansLen, x + k + 1);
				f.erase(x + k);
			}
		}
	}
	
	for (int i = 0; i < ansLen; i++) if (ans[i] == 0) ans[i] = 'a';
	
	printf("%s\n", ans);
	
	return 0;
}