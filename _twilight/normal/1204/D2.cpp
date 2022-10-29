#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005];

int main() {
	int sum = 0;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = n; i; i--) {
		if (s[i] == '0') {
			sum++;
		} else {
			(sum) ? (--sum) : (s[i] = '0');
		}
	}
	puts(s + 1);
	return 0;
}