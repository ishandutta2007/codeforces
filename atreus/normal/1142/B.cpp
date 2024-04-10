#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;

int seg[4 * maxn];

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1, ret = maxn;
	if (l < mid)
		ret = min(ret, get(2 * id + 0, L, mid, l, min(mid, r)));
	if (mid < r)
		ret = min(ret, get(2 * id + 1, mid, R, max(l, mid), r));
	return ret;
}

void change(int id, int L, int R, int idx, int val){
	if (L + 1 == R){
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	if (idx < mid)
		change(2 * id + 0, L, mid, idx, val);
	else
		change(2 * id + 1, mid, R, idx, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
}

int p[maxn], nex[maxn], a[maxn], dp[maxn][20], last[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		nex[p[i]] = p[(i + 1) % n];
	for (int i = 0; i < m; i++)
		cin >> a[i];
	memset(last, -1, sizeof last);
	memset(dp, -1, sizeof dp);
	for (int i = m - 1; i >= 0; i--){
		last[a[i]] = i;
		dp[i][0] = last[nex[a[i]]];
	}
	for (int i = 1; i <= 18; i++)
		for (int j = 0; j < m; j++)
			if (dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
	for (int i = 0; i < m; i++){
		int mynex = i;
		for (int j = 0; mynex != -1 and j <= 18; j++)
			if ((n - 1) & (1 << j))
				mynex = dp[mynex][j];
		if (mynex == -1)
			mynex = m + 1;
		change(1, 0, m, i, mynex);
	}
	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l --;
		cout << (get(1, 0, m, l, r) < r);
	}
	cout << endl;
}