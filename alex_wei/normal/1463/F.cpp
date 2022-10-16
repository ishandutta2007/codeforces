#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans, f[2][1 << 22];
void cmax(int &x, int y) {x = x > y ? x : y;}
int main() {
	cin >> n >> x >> y;
	if(x < y) swap(x, y);
	for(int i = 1; i <= min(n, x + y); i++) {
		int coef = n / (x + y) + (i <= n % (x + y));
		for(int S = 0; S < 1 << x; S++) {
			cmax(f[i & 1][(S << 1) & (1 << x) - 1], f[i & 1 ^ 1][S]);
			if(!(S >> x - 1 & 1) && !(S >> y - 1 & 1))
				cmax(f[i & 1][S << 1 & (1 << x) - 1 | 1], f[i & 1 ^ 1][S] + coef);
		}
	} for(int i = 0; i < 1 << x; i++) cmax(ans, f[min(n, x + y) & 1][i]);
	cout << ans << endl;
	return 0;
}

/*
stupid mistakes:
	& (L - 1) -> & L =.= 
	& (1 << x) - 1 -> & (L - 1) =.=
*/