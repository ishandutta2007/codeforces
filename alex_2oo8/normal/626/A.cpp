#include<bits/stdc++.h>

using namespace std;

char s[300];

int main() {
	int n;
	scanf("%d %s", &n, s);
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			int x = 0, y = 0;
			for (int k = i; k < j; k++) {
				if (s[k] == 'L') x--;
				if (s[k] == 'R') x++;
				if (s[k] == 'U') y--;
				if (s[k] == 'D') y++;
			}
			
			if (x == 0 && y == 0) ans++;
		}
	
	printf("%d\n", ans);
	
	return 0;
}