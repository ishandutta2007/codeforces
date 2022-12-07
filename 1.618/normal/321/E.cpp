#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define inf 0x3f3f3f3f
#define maxn 4005
using namespace std;
typedef long long ll;
typedef pair <int,int> P;
int a[maxn][maxn],w[maxn][maxn],dp[2][maxn];
int n,k;
int getint(){
	char c;
	for(c = getchar();c < '0' || c > '9';c = getchar());
	int res = c - '0';
	for(c = getchar();c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
	return res;
}
void calc(int l,int r,int L,int R){//calc dp[1][l,r] using dp[0][L,R]
	int mid = (l + r) >> 1;
	int minval = inf,minpos = 0;
	for(int i=L;i <= R && i < mid;i++){
		if(dp[0][i] + w[i][mid] < minval){
			minval = dp[0][i] + w[i][mid];
			minpos = i;
		}
	}
	dp[1][mid] = minval;
	if(mid != l) calc(l,mid - 1,L,minpos);
	if(mid != r) calc(mid + 1,r,minpos,R);
}
int main(){
  n = getint(),k = getint();
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j] = getint();
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
  	a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			w[i][j] = a[j][j] - a[i][j] - a[j][i] + a[i][i];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<i;j++) dp[1][j] = inf;
		calc(i,n,0,n);
		for(int j=0;j<=n;j++) dp[0][j] = dp[1][j];
	}
	printf("%d\n",dp[0][n] / 2);
  return 0;
}