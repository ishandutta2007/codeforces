#include <bits/stdc++.h> 

using namespace std;

const int N = 2e5 + 10;

bool v[N];
int n, p[N], tot = 0, on = 0;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf("%d", &x);
		on += x;
	}
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			++tot;
			v[i] = 1;
			int j = p[i];
			while (j != i) v[j] = 1, j = p[j];
		}
	}
	if (tot == 1) tot = 0;
	if (!(on & 1)) ++tot;
	printf("%d\n", tot);
	return 0;
}