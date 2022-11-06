#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Mx = (int) 1e6 + 9;
vector<int> occ[Mx + 9];
int dp1[Mx + 9];
int dp2[Mx + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, X;
	cin >> n >> X;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		occ[x].push_back(i);
	}

	fill(dp1, dp1 + Mx, Mx);
	fill(dp2, dp2 + Mx, -1);

	dp1[0] = -1;
	dp2[X + 1] = Mx;

	for (int i = 1; i <= X; ++i) {
		if (occ[i].empty())
			dp1[i] = dp1[i - 1];
		else if (occ[i].front() <= dp1[i - 1])
			break;
		else
			dp1[i] = occ[i].back();
	}

	for (int i = X; i >= 1; --i) {
		if (occ[i].empty())
			dp2[i] = dp2[i + 1];
		else if (occ[i].back() >= dp2[i + 1])
			break;
		else
			dp2[i] = occ[i].front();
	}

	ll ans = 0;
	for (int i = 0, j = 2;; ++i) {
		j = max(j, i + 2);
		while (j <= X + 1 && dp1[i] >= dp2[j])
			++j;
		if (j > X + 1)
			break;
		ans += X + 1 - j + 1;
	}
	cout << ans;
	return 0;
}