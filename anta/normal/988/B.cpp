#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<string> words(n);
		for (int i = 0; i < n; ++ i) {
			char buf[101];
			scanf("%s", buf);
			words[i] = buf;
		}
		sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
		bool ans = true;
		for (int i = 0; i < n - 1; ++ i)
			ans &= words[i + 1].find(words[i]) != string::npos;
		puts(ans ? "YES" : "NO");
		if (ans) {
			for (int i = 0; i < n; ++ i)
				puts(words[i].c_str());
		}
	}
}