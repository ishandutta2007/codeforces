#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

// http://codeforces.com/contest/867/problem/D

typedef long double ld;

const int MxN = 50;
const int MxX = MxN * 100;

int n, R;
int F[MxN], S[MxN];
ld P[MxN];
ld dp[MxN + 1][MxX + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);

	cin >> n >> R;
	for (int i = 0; i < n; ++i) {
		cin >> F[i] >> S[i] >> P[i];
		P[i] /= 100;
	}

	const ld eps = 1e-10;
	ld lo = 0, hi = 1e10;

	while (hi - lo > eps) {
		const ld mid = (lo + hi) / 2;

		for (int i = n; i >= 0; --i) {
			for (int j = 0; j <= MxX; ++j) {
				ld &res = dp[i][j];
				if (j > R)
					res = mid;
				else if (i == n)
					res = 0;
				else
					res = min(mid, P[i] * (F[i] + dp[i + 1][j + F[i]]) + (1 - P[i]) * (S[i] + dp[i + 1][j + S[i]]));
			}
		}
		if (dp[0][0] < mid)
			hi = mid;
		else
			lo = mid;
	}
	cout << dp[0][0];
	return 0;
}