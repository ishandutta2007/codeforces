#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

char s[MAXN];

int main() {
	scanf("%s", s);

	int mini = 30;	
	for (int i = 0; s[i]; i++) {
		int tmp = s[i] - 'a';
		if (mini < tmp)
			puts("Ann");
		else {
			puts("Mike");
			mini = tmp;
		}
	}
	
	return 0;
}