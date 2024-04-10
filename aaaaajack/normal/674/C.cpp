#include<bits/stdc++.h>
#define N 200100
#define K 60
using namespace std;
double dp[K][N],b[N];
double s[N],is[N];
int a[N];
int stk[N],now,sz;
bool early(int p1,int p2,int p3){
	return (b[p3]-b[p1])*(s[p2]-s[p1])<(b[p2]-b[p1])*(s[p3]-s[p1]);
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		s[i+1]=s[i]+a[i];
		is[i+1]=is[i]+1.0/a[i];
	}
	for(int i=1;i<=n;i++){
		dp[1][i]=dp[1][i-1]+s[i]/a[i-1];
	}
	for(int t=1;t<k;t++){
		for(int i=t;i<n;i++){
			b[i]=dp[t][i]+s[i]*is[i]-dp[1][i];
		}
		now=0;
		sz=0;
		for(int i=t;i<n;i++){
			while(sz>=2&&early(stk[sz-2],stk[sz-1],i)) sz--;
			stk[sz++]=i;
			if(now>sz-1) now=sz-1;
			while(now<sz-1&&b[stk[now+1]]-s[stk[now+1]]*is[i+1]<b[stk[now]]-s[stk[now]]*is[i+1]) now++;
			dp[t+1][i+1]=b[stk[now]]-s[stk[now]]*is[i+1]+dp[1][i+1];
		}
	}
	cout<<setprecision(10)<<dp[k][n]<<endl;
	return 0;
}