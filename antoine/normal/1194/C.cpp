#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

string s, t;
int dp[109][109];

int f(const int i, const int j, array<int, 26> &occ) {
	int &res = dp[i][j];
	if (res != -1)
		return res;

	if (j == (int) t.size())
		return res = i == (int) s.size();

	if (i < (int) s.size() && s[i] == t[j] && f(i + 1, j + 1, occ))
		return res = 1;

	if (!occ[t[j] - 'a'])
		return res = 0;
	--occ[t[j] - 'a'];
	res = f(i, j + 1, occ);
	++occ[t[j] - 'a'];
	return res;
}

ll f() {
	memset(dp, -1, sizeof dp);

	string p;
	cin >> s >> t >> p;
	array<int, 26> occ;
	occ.fill(0);
	for (char c : p)
		++occ[c - 'a'];
	return f(0, 0, occ);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int Q;
	cin >> Q;
	while (Q--)
		cout << (f() ? "YES" : "NO") << '\n';
	return 0;
}