#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
const int MxL = 253;

int n, Q;
int dp[MxL + 1][MxL + 1][MxL + 1];
char str[MxN + 9];
array<int, 26> nxtOcc[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> Q >> str;
	nxtOcc[n].fill(n + 1);
	nxtOcc[n + 1].fill(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		nxtOcc[i] = nxtOcc[i + 1];
		nxtOcc[i][str[i] - 'a'] = i;
	}

	for (int i = 0; i < MxL; ++i)
		for (int j = 0; j < MxL; ++j)
			for (int k = 0; k < MxL; ++k)
				dp[i][j][k] = n + 1;
	dp[0][0][0] = 0;

	string a, b, c;
	while (Q--) {
		char type;
		int idx;
		cin >> type >> idx;
		idx--;

		if (type == '+') {
			char ch;
			cin >> ch;
			(idx == 0 ? a : idx == 1 ? b : c).push_back(ch);
		}

		int fromI = 0, toI = (int) a.size();
		int fromJ = 0, toJ = (int) b.size();
		int fromK = 0, toK = (int) c.size();

		if (idx == 0)
			fromI = toI;
		else if (idx == 1)
			fromJ = toJ;
		else if (idx == 2)
			fromK = toK;

		if (type == '+') {
			for (int i = fromI; i <= toI; ++i)
				for (int j = fromJ; j <= toJ; ++j)
					for (int k = fromK; k <= toK; ++k) {
						int &curr = dp[i][j][k];
						if (i > 0)
							curr = min(curr, nxtOcc[dp[i - 1][j][k]][a[i - 1] - 'a'] + 1);
						if (j > 0)
							curr = min(curr, nxtOcc[dp[i][j - 1][k]][b[j - 1] - 'a'] + 1);
						if (k > 0)
							curr = min(curr, nxtOcc[dp[i][j][k - 1]][c[k - 1] - 'a'] + 1);
					}
		} else {
			for (int i = fromI; i <= toI; ++i)
				for (int j = fromJ; j <= toJ; ++j)
					for (int k = fromK; k <= toK; ++k)
						dp[i][j][k] = n + 1;

			(idx == 0 ? a : idx == 1 ? b : c).pop_back();
		}

		const bool yes = dp[(int) a.size()][(int) b.size()][(int) c.size()] <= n;
		cout << (yes ? "YES" : "NO") << '\n';
	}
	return 0;
}