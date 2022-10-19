#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
char s[MAXN];

int main() {
	scanf("%s", s);
	N = strlen(s);
	
	bool ok = true;
	for (int i = 1; i < N; i++)
		if (s[i - 1] == '(' && s[i] == ')')
			ok = false;
	
	if (ok) {
		puts("0");
		return 0;
	}
	
	int closed = 0;
	for (int i = 0; i < N; i++)
		closed += s[i] == ')';
	
	int open = 0;
	for (int i = 0; i < N - 1; i++) {
		open += s[i] == '(';
		closed -= s[i] == ')';
		if (open == closed) {
			puts("1");
			printf("%d\n", open + closed);
			for (int j = 0; j <= i; j++)
				if (s[j] == '(')
					printf("%d ", j + 1);
			for (int j = i + 1; j < N; j++)
				if (s[j] == ')')
					printf("%d ", j + 1);
			puts("");
			return 0;
		}
	}
	
	assert(false);
	
	return 0;
}