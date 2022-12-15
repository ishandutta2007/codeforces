#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;

int dp[101][11];

int main() {
	int n,t;
	scanf("%d%d",&n,&t);
	if(t==10) {
		if(n==1) puts("-1");
		else {
			for(int i=0;i<n-2;i++) printf("1");
			printf("%d\n",t);
		}
	} else {
		for(int i=0;i<n;i++) printf("%d",t);
	}
	return 0;
}