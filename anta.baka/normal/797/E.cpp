#include <bits/stdc++.h>

using namespace std;

const int co = 300;

int n, a[100000], q, b[co][100000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> q;
	for(int i = 1; i < co; i++)
		for(int j = n - 1; j >= 0; j--)
			b[i][j] = (j + a[j] + i < n ? b[i][j + a[j] + i] + 1 : 1);
	for(int i = 0; i < q; i++) {
		int p, k;
		cin >> p >> k;
		--p;
		if(k < co)
			cout << b[k][p] << '\n';
		else {
			int c = 0;
			while(p < n) {
				c++;
				p += a[p] + k;
			}
			cout << c << '\n';
		}
	}
}