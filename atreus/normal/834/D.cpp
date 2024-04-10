#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 4e4 + 10;

int seg[4 * maxn], lazy[4 * maxn], last[maxn], pre[maxn];

int a[maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int val){
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

int dp[55][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	memset(dp, -63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++){ // dp[i][j] = dp[i - 1][k - 1] + cost[k][j]
		for (int j = 1; j <= n; j++){
			change(1, 1, n + 1, j, j + 1, dp[i - 1][j - 1]);
			change(1, 1, n + 1, pre[j] + 1, j + 1, 1);
			dp[i][j] = seg[1];
		}
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
	}
	cout << dp[k][n] << endl;
}