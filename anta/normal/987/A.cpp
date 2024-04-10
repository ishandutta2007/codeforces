#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<pair<string, string>> pairs = {
		{"Power", "purple"},
		{"Time", "green"},
		{"Space", "blue"},
		{"Soul", "orange"},
		{"Reality", "red"},
		{"Mind", "yellow"}
		};
		set<string> s;
		for (int i = 0; i < n; ++ i) {
			char buf[101];
			scanf("%s", buf);
			s.insert(buf);
		}
		vector<string> ans;
		for (auto p : pairs) if (!s.count(p.second))
			ans.push_back(p.first);
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++ i)
			printf("%s\n", ans[i].c_str());
	}
}