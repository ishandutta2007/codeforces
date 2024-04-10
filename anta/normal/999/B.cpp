#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (~scanf("%d", &n)) {
		char S[101];
		scanf("%s", S);
		for (int d = 1; d <= n; ++ d) if (n % d == 0)
			reverse(S, S + d);
		puts(S);
	}
}