#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];
bool bio[30];

int main() {
	scanf("%d%s", &N, s);
	
	bool ok = false;
	for (int i = 0; i < N; i++) {
		if (bio[s[i] - 'a']) {
			ok = true;
			break;
		}
		bio[s[i] - 'a'] = true;
	}
	
	puts(ok || N == 1 ? "Yes" : "No");
	
	return 0;
}