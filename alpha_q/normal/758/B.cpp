#include <bits/stdc++.h> 

using namespace std;

const int N = 105;

char s[N];
map <int, char> mod;
int n, r, b, y, g;

int main (int argc, char const *argv[]) {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] != '!') {
			mod[i % 4] = s[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '!') {
			int j = i % 4;
			if (mod[j] == 'R') ++r;
			if (mod[j] == 'B') ++b;
			if (mod[j] == 'Y') ++y;
			if (mod[j] == 'G') ++g;
		}
	}
	printf("%d %d %d %d\n", r, b, y, g);
	return 0;
}