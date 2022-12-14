#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
template<class T>inline void print(T x,int op=1){
	static int top,stk[105];
	if(x<0)x=-x,putchar('-');
	if(x==0)putchar('0');
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]+'0');
	if(~op)putchar(" \n"[op]);
}
const int SIZE=1e6+5;
const int P=998244353;
int fac[SIZE],inv[SIZE];
int fast(int a,int b=P-2){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return res;
}
int comb(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;
}
const int M=5005;
int cas,n,A[M],tmp[M],cnt[M],sum[M];
int dp[M][M];
void add(int &x,int y){
	x+=y;
	if(x>=P)x-=P;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	fac[0]=1;
	for(int i=1;i<SIZE;i++)fac[i]=1ll*fac[i-1]*i%P;
	inv[SIZE-1]=fast(fac[SIZE-1]);
	for(int i=SIZE-2;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%P;
	rd(cas);
	while(cas--){
		int uni=0;
		rd(n);
		for(int i=1;i<=n;i++)rd(A[i]),tmp[++uni]=A[i];
		sort(tmp+1,tmp+1+uni);
		uni=unique(tmp+1,tmp+1+uni)-tmp-1;
		for(int i=1;i<=n;i++)A[i]=lower_bound(tmp+1,tmp+1+uni,A[i])-tmp;
		for(int i=1;i<=n;i++)cnt[uni+1-A[i]]++;
		for(int i=1;i<=uni;i++)sum[i]=sum[i-1]+cnt[i];
		if(cnt[1]==1)dp[1][1]=1;
		for(int i=2;i<=uni;i++){
			for(int j=0;j<=n/2;j++){
				if(dp[i-1][j]==0)continue;
				int k=sum[i-1]-j;
				if(j<n/2)add(dp[i][j+1],1ll*dp[i-1][j]*comb(j-1-k,cnt[i]-1)%P);
				if(j<n/2)add(dp[i][j],1ll*dp[i-1][j]*comb(j-1-k,cnt[i])%P);
				if(j==n/2)add(dp[i][j],1ll*dp[i-1][j]*comb(j-k,cnt[i])%P);
			}
		}
		print(dp[uni][n/2]);
		for(int i=0;i<=n;i++)cnt[i]=sum[i]=0;
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
	}
	return (0-0);
}