#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1e9 + 7;

map <pii, int> cnt;
map <pii, string> any;

inline void advance(pii &p, char c) {
	p = {((ll)BASE1 * p.first + c) % MOD, BASE2 * p.second + c};
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		char s[10];
		scanf("%s", s);
		int len = strlen(s);
		set <pii> all;
		for (int i = 0; i < len; i++) {
			pii hsh = {0, 0};
			for (int j = i; j < len; j++) {
				advance(hsh, s[j]);
				all.insert(hsh);
			}
		}
		for (auto it : all) {
			cnt[it]++;
			any[it] = s;
		}
	}
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		char s[10];
		scanf("%s", s);
		pii hsh = {0, 0};
		int len = strlen(s);
		for (int i = 0; i < len; i++)
			advance(hsh, s[i]);
		printf("%d %s\n", cnt[hsh], cnt[hsh] ? any[hsh].c_str() : "-");
	}
	
	return 0;
}