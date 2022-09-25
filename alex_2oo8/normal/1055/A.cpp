#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

void no() {
	printf("%s\n", "NO");
	exit(0);
}

void yes() {
	printf("%s\n", "YES");
	exit(0);
}

int a[MX], b[MX];

int main() {
	int n, s;
	ignore = scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) ignore = scanf("%d", a + i);
	for (int i = 0; i < n; i++) ignore = scanf("%d", b + i);
	
	if (a[0] == 0) no();
	if (a[s - 1] == 1) yes();
	if (b[s - 1] == 0) no();
	
	for (int i = s; i < n; i++) if (a[i] + b[i] == 2) yes();
	
	no();
	
	return 0;
}