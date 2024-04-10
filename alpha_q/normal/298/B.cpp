#include <bits/stdc++.h>

using namespace std;

int main() {
	char S[100005];
	int t, a, b, c, d, i, j, x, y;
	scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
	scanf("%s", S);
	
	if (c >= a && d >= b) {
		for (i = 0; i < t; i++) {
			if (S[i] == 'E' && a < c) a++;
			else if (S[i] == 'N' && b < d) b++;
			if (a == c && b == d) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
		printf("-1\n");
	}
	else if (c >= a && d <= b) {
		for (i = 0; i < t; i++) {
			if (S[i] == 'E' && a < c) a++;
			else if (S[i] == 'S' && b > d) b--;
			if (a == c && b == d) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
		printf("-1\n");
	}
	else if (c <= a && d >= b) {
		for (i = 0; i < t; i++) {
			if (S[i] == 'W' && a > c) a--;
			else if (S[i] == 'N' && b < d) b++;
			if (a == c && b == d) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
		printf("-1\n");
	}
	else {
		for (i = 0; i < t; i++) {
			if (S[i] == 'W' && a > c) a--;
			else if (S[i] == 'S' && b > d) b--;
			if (a == c && b == d) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
		printf("-1\n");
	}
	
	return 0;
}