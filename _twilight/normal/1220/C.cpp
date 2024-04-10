#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 5e5 + 5;

int n;
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	char minc = 'z';
	for (int i = 1; i <= n; i++) {
		puts((minc < s[i]) ? ("Ann") : ("Mike"));
		minc = min(minc, s[i]);
	}
	return 0;
}