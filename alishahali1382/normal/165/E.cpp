#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int dp[5*MAXN];

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", A+i);
		dp[A[i]]=A[i];
	}
	int tmp=(1<<22)-1;
	for (int x=0; x<22; x++) for (int i=1; i<=tmp; i++) if (dp[i]!=-1) dp[i|(1<<x)]=dp[i];
	for (int i=1; i<=n; i++) printf("%d ", dp[tmp^A[i]]);
	
	return 0;
}