#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

int n, k, x, ans;
bitset<262144> dp;

int main(){
	scanf("%d%d", &n, &k);
	dp[0]=1;
	while (n--){
		scanf("%d", &x);
		dp |= (dp<<(x*512)) | (dp<<(x*512+x));
	}
	for (int i=0; i<=500; i++) if (dp[k*512+i]) ans++;
	printf("%d\n", ans);
	for (int i=0; i<=500; i++) if (dp[k*512+i]) printf("%d ", i);
	return 0;
}