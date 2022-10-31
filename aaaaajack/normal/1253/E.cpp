#include<bits/stdc++.h>
#define N 100100
using namespace std;
struct seg{
	int x;
	int r;
	bool operator<(seg rhs)const {return x+r<rhs.x+rhs.r;}
}s[100];
int dp[N];
const int inf=1023456789;
int solve(int t,int n){
	if(t<=0) return 0;
	if(dp[t]!=inf) return dp[t];
	int i=n-1,nxt=t;
	while(i>=0&&s[i].x+s[i].r>=nxt){
		nxt=min(nxt,s[i].x-s[i].r-1);
		i--;
	}
	if(i<0) return dp[t]=max(0,nxt);
	int ret=nxt;
	for(int j=0;j<=i;j++){
		int ext=nxt-s[j].x-s[j].r;
		ret=min(ret,ext+solve(s[j].x-s[j].r-ext-1,n));
	}
	return dp[t]=ret;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fill(dp,dp+N,inf);
	for(int i=0;i<n;i++){
		scanf("%d%d",&s[i].x,&s[i].r);
	}
	sort(s,s+n);
	printf("%d\n",solve(m,n));
	return 0;
}