#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n;
char s[N];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += s[i] == 'z';
	int m = (n - cnt * 4) / 3;
	while (m--)
		putchar('1'), putchar(' ');
	while (cnt--)
		putchar('0'), putchar(' ');
	return 0;
}