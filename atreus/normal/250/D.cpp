#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a, b;
int match[maxn], ya[maxn], yb[maxn], len[maxn];

ld dis(int x1, int y1, int x2, int y2){
	ld X = x2 - x1, Y = y1 - y2;
	return sqrt(X*X + Y*Y);
}

ld check(int i, int j){
	return dis(0, 0, a, ya[i]) + dis(a, ya[i], b, yb[j]) + len[j];
}

void divide(int l, int r, int lo, int hi){
	if (r <= l)
		return;
	int mid = (l + r) >> 1;
	int idx = lo;
	for (int i = lo; i <= hi; i++)
		if (check(mid, i) < check(mid, idx))
			idx = i;
	match[mid] = idx;
	divide(l, mid, lo, idx);
	divide(mid+1, r, idx, hi);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> ya[i];
	for (int i = 1; i <= m; i++)
		cin >> yb[i];
	for (int i = 1; i <= m; i++)
		cin >> len[i];
	divide(1, n+1, 1, m);
	int idx = 1;
	for (int i = 2; i <= n; i++)
		if (check(i, match[i]) < check(idx, match[idx]))
			idx = i;
	cout << idx << " " << match[idx] << endl;
}