#include <bits/stdc++.h>

using namespace std;

typedef double D;

const int K = 53;
const int N = 2e5 + 7;
const D inf = 1e15 + 9;

int n, k;
D dp[K][N];
double pref[N];
double rev_pref[N];
double all_pref[N];

inline D f(int from, int to){
	if(from > to)
		return inf;
	return all_pref[to] - all_pref[from - 1] - pref[from - 1] * (rev_pref[to] - rev_pref[from - 1]);
}

void dc(int row, int from, int to, int s, int e){
	if(from > to || s > e)
		return;

	int mid = (from + to) / 2;
	int opt = s;
	
	for(int i = s + 1; i <= e; ++i)
		if(dp[row - 1][i] + f(i + 1, mid) < dp[row - 1][opt] + f(opt + 1, mid))
			opt = i;
	dp[row][mid] = dp[row - 1][opt] + f(opt + 1, mid);
	
	dc(row, from, mid - 1, s, opt);
	dc(row, mid + 1, to, opt, e);
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%lf", &pref[i]);
		all_pref[i] = all_pref[i - 1] + (pref[i] + pref[i - 1]) / pref[i];
		rev_pref[i] = rev_pref[i - 1] + 1.0 / pref[i];
		pref[i] += pref[i - 1];
	}
	
	for(int i = 1; i <= n; ++i)
		dp[0][i] = inf;
	for(int i = 1; i <= k; ++i)
		dc(i, 1, n, 0, n);
	printf("%.6lf\n", dp[k][n]);
	return 0;
}