#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

char s[MX + 1];

void solve(int l, int r) {
	if (l >= r) return;
	
	if (r - l < 4) {
		printf("%c", s[l]);
	}
	else {
		int cnt[3];
		fill(cnt, cnt + 3, 0);
		cnt[s[l]     - 'a']++;
		cnt[s[l + 1] - 'a']++;
		cnt[s[r - 1] - 'a']++;
		cnt[s[r - 2] - 'a']++;
		
		int x = 0;
		while (cnt[x] < 2) x++;
		
		printf("%c", 'a' + x);
		solve(l + 2, r - 2);
		printf("%c", 'a' + x);
	}
}

int main() {
	ignore = scanf("%s", s);
	int n = strlen(s);
	solve(0, n);
	printf("\n");
	
	return 0;
}