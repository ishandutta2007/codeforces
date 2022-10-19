#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

int N, X, Y;
char s[MAXN];

int main() {
	scanf("%d%d%d%s", &N, &X, &Y, s);
	
	int blocks = 0;
	for (int i = 0; i < N; i++)	
		if (s[i] == '0' && (!i || s[i - 1] == '1'))
			blocks++;
	
	ll sol = 1e18;
	for (int i = 0; i < blocks; i++) 
		sol = min(sol, (ll)i * X + (ll)(blocks - i) * Y);
	
	printf("%lld\n", blocks ? sol : 0);
	
	return 0;
}