#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 5005
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char s[maxn][3];
int dp[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]);
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		if(s[i - 1][0] == 'f'){
			for(int j=n;j>=1;j--) dp[j] = dp[j - 1];
		}else{
			for(int j=n;j>=1;j--){
				dp[j] = (dp[j + 1] + dp[j]) % mod;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans + dp[i]) % mod;
	}
	printf("%d\n",ans);
	return 0;
}