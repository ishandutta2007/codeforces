#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 4000 + 5;
const int maxk = 800 + 5;
const int inf = 1e9 + 100;

ll a[maxn][maxn], dp[maxk][maxn];

int sum(int i, int idx){
 	return a[idx][idx] - a[idx][i] - a[i][idx] + a[i][i];
}

inline int get(int idx, int l, int r, int row){
	int ret = -1;
	for (int i = l; i < min(idx, r); i++){
		if (dp[row][idx] > dp[row - 1][i] + sum(i, idx)){
			ret = i;
			dp[row][idx] = dp[row - 1][i] + sum(i, idx);
		}
	}
	return ret;
}

void cal_dp(int L, int R, int l, int r, int row){
	if (L >= R)
		return;
	int mid = (L + R) >> 1;
	int idx = get(mid, l, r, row);
	if (L + 1 == R)
		return;
	cal_dp(L, mid, l, idx + 1, row);
	cal_dp(mid + 1, R, idx, r, row);
}

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x = (getchar(), getchar()) - '0';
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++){
		cal_dp(i, n + 1, 0, n + 1, i);
	}
	cout << dp[k][n] / 2 << endl;
}