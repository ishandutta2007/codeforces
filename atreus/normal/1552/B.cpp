#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

int r[maxn][6];

bool cmpFunc(int fi, int se) {
	int cnt = 0;
	for (int i = 1; i <= 5; i++)
		cnt += r[fi][i] < r[se][i];
	return cnt < 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 5; j++)
				cin >> r[i][j];
		int mxm = -1;
		for (int i = 1; i <= n; i++)
			if (mxm == -1 or cmpFunc(mxm, i))
				mxm = i;
		for (int i = 1; i <= n; i++)
			if (mxm != -1 and i != mxm and cmpFunc(mxm, i))
				mxm = -1;
		cout << mxm << '\n';
	}
}