#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Inf = (int) 1e6;

int a[4][4];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	a[1][1] = a[2][2] = a[3][3] = Inf;

	const int ci = 1;
	const int tr = 2;
	const int sq = 3;

	a[tr][ci] = 3;
	a[tr][sq] = Inf;

	a[ci][tr] = 3;
	a[ci][sq] = 4;

	a[sq][tr] = Inf;
	a[sq][ci] = 4;

	int n, res = 0;
	cin >> n;
	vector<int> b(n);
	for (int &x : b)
		cin >> x;
	for (int i = 1; i < n; ++i) {
		res += a[b[i - 1]][b[i]];
		res -= b[i - 1] == sq && b[i] == ci && i + 1 < n && b[i + 1] == tr;
	}
	cout << (res >= Inf ? (string) "Infinite" : "Finite\n" + to_string(res));
	return 0;
}