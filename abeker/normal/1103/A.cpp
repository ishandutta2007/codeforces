#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

char s[MAXN];
int hor, ver;

void out(int a, int b) {
	printf("%d %d\n", ++a, ++b);
}

int main() {
	scanf("%s", s);
	
	for (int i = 0; s[i]; i++)
		if (s[i] == '1') {
			out(hor, 0);
			hor = (hor + 1) % 4;
		}
		else {
			out(ver, 3);
			ver = (ver + 2) % 4;
		}
		
	return 0;
}