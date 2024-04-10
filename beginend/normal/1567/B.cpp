#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int s[N];

int main() {
	for (int i = 1; i <= 300000; i++) s[i] = s[i - 1] ^ i;
	int T; scanf("%d", &T);
	while (T--) {
		int a, b; scanf("%d%d", &a, &b);
		if ((s[a - 1] ^ b) == 0) printf("%d\n", a);
		else if ((s[a - 1] ^ b) == a) printf("%d\n", a + 2);
		else printf("%d\n", a + 1); 
	}
	return 0;
}