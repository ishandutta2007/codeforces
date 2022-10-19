#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, Q;
char s[MAXN];
int occ[MAXN][30];

int main() {
	scanf("%s%d", s + 1, &Q);
	
	N = strlen(s + 1);
	for (int i = 1; i <= N; i++) {
		memcpy(occ[i], occ[i - 1], sizeof occ[i]);
		occ[i][s[i] - 'a']++; 
	}
	
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int cnt = 0;
		for (int i = 0; i < 26; i++)
			cnt += occ[r][i] > occ[l - 1][i];
		puts(l != r && cnt <= 2 && s[l] == s[r] ? "No" : "Yes");
	}
	
	return 0;
}