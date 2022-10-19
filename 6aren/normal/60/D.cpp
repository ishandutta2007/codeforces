#include<bits/stdc++.h>
using namespace std;

const int MAXA = 10000000;
const int N = 1000005;

int n, a[N], check[MAXA + 10], res, p[N];

int root(int x) {
	if (p[x] == x) return x;
	return (p[x] = root(p[x]));
}

void unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return;
	res--;
	p[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; res = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		check[a[i]] = i;
		p[i] = i;
	}
	int maxx = sqrt(3 * MAXA / 2) + 5;
	int maxy = sqrt(MAXA / 2) + 5;
	for (int x = 2; x < maxx; x++) {
		for (int y = 1; y < min(x, maxy); y++) {
			vector<int> v;
			int a1 = x * x - y * y;
			int a2 = 2 * x * y;
			int a3 = x * x + y * y;
			if (__gcd(a1, a2) != 1) continue;
			if (a1 < MAXA && check[a1]) v.push_back(check[a1]);
			if (a2 < MAXA && check[a2]) v.push_back(check[a2]);
			if (a3 < MAXA && check[a3]) v.push_back(check[a3]);
			if (v.size() >= 2) unite(v[0], v[1]);
			if (v.size() == 3) unite(v[1], v[2]);
		}
	}
	cout << res;
	return 0;
}