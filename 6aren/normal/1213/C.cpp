#include<bits/stdc++.h>
using namespace std;

#define int long long

int check[20];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		int t = n / m;
		int tmp = m;
		check[1] = m % 10;
		int chuky, schuky = 0;
		for (int i = 2; i <= 11; i++) {
			tmp += m % 10;
			check[i] = tmp % 10;
			if (check[i] == check[1]) chuky = i - 1;
		}
		for (int i = 1; i < chuky; i++) {
			schuky += check[i];
		}
		int o = 0;
		for (int i = 1; i <= t % chuky; i++) {
			o += check[i];
		}
		cout << t / chuky * schuky + o << endl;
	}
	return 0;
}