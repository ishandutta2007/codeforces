#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const LD eps = 1e-6;
const int mxn = 2e5 + 7;
const LD INF = 1e16 + 9;
const int MX = 1e9 + 9;

int n, k;
LD a[mxn];
LD pref[mxn];
LD prefInv[mxn];
LD prefSum[mxn];
LD dp[57][mxn];

LD val(int from, int to){
	return prefSum[to] - prefSum[from - 1] - pref[from - 1] * (prefInv[to] - prefInv[from - 1]);
}

void Div(int row, int s1, int e1, int s2, int e2){
	if(e2 < s2 || e1 < s1)
		return;
	
	if(s2 == e2){
		dp[row][s2] = INF;
		for(int i = s1; i <= e1; ++i)
			dp[row][s2] = min(dp[row - 1][i] + val(i + 1, s2), dp[row][s2]);
		return;
	}
	
	int mid = (s2 + e2)/2;
	int mid2 = s1;
	dp[row][mid] = INF;
	int to = min(e1, mid - 1);
	
	for(int i = s1; i <= to; ++i){
		if(dp[row][mid] > dp[row - 1][i] + val(i + 1, mid)){
			dp[row][mid] = dp[row - 1][i] + val(i + 1, mid);
			mid2 = i;
		}
	}
	
	Div(row, s1, mid2, s2, mid - 1);
	Div(row, mid2, e1, mid + 1, e2);
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%lf", &a[i]);
		pref[i] = pref[i - 1] + a[i];
		prefInv[i] = prefInv[i - 1] + 1.0 / a[i];
		prefSum[i] = prefSum[i - 1] + pref[i] / a[i];
	}
	
	for(int i = 1; i <= n; ++i)
		dp[0][i] = INF;
	
	for(int i = 1; i <= k; ++i)
		Div(i, i - 1, n, i, n);
	
	printf("%.7lf\n", dp[k][n]);
	return 0;
}