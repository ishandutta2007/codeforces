#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 3;

int a[maxn], seg[4 * maxn];
ll dp[maxn];

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	int fi = get(2 * id + 0, L, mid, l, r);
	int se = get(2 * id + 1, mid, R, l, r);
	if (a[fi] > a[se])
		return fi;
	return se;
}

void build(int id, int L, int R){
	if (L + 1 == R){
		seg[id] = L;
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	if (a[seg[2 * id + 0]] > a[seg[2 * id + 1]])
		seg[id] = seg[2 * id + 0];
	else
		seg[id] = seg[2 * id + 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n; 
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
		cin >> a[i];
	build(1, 1, n + 1);
	ll answer = 0;
	for (int j = n - 1; j >= 1; j--){
		int idx = get(1, 1, n + 1, j + 1, a[j] + 1);
		dp[j] = dp[idx] + (n - a[j]) + (idx - j);
		answer += dp[j];
	}
	cout << answer << endl;
}