#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		char S[400001];
		scanf("%s", S);
		vector<pair<char, int>> ord;
		for (int i = 0; i < n; ++ i)
			ord.emplace_back(S[i], i);
		nth_element(ord.begin(), ord.begin() + k, ord.end());
		string ans(n, 0);
		for (int i = k; i < n; ++ i)
			ans[ord[i].second] = ord[i].first;
		ans.erase(remove(ans.begin(), ans.end(), 0), ans.end());
		puts(ans.c_str());
	}
}