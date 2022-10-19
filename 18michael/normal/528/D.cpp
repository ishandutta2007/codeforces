#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
const int G=3,Gi=332748118;
int n,m,k,lim,t,mid,ans=0,inv;
int r[524302];
LL A[524302],B[524302],sum[524302],w[524302],iw[524302];
char S[200002],T[200002];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	for(lim=1,t=-1;lim<=n+m;lim<<=1,++t);
	for(int i=1;i<lim;++i)r[i]=((r[i>>1]>>1)|((i&1)<<t));
	inv=Pow(lim,mod-2),mid=(lim>>1),w[mid]=iw[mid]=1,w[mid+1]=Pow(G,(mod-1)/lim),iw[mid+1]=Pow(Gi,(mod-1)/lim);
	for(int i=mid+2;i<=lim;++i)w[i]=(w[i-1]*w[mid+1])%mod,iw[i]=(iw[i-1]*iw[mid+1])%mod;
	for(int i=mid-1;i>0;--i)w[i]=w[i<<1],iw[i]=iw[i<<1];
}
inline void NTT(LL A[],int o)
{
	LL tmp;for(int i=0;i<lim;++i)if(i<r[i])swap(A[i],A[r[i]]);
	for(int i=1;i<lim;i<<=1)for(int j=0;j<lim;j+=(i<<1))for(int k=0;k<i;++k)tmp=((o? w[i+k]:iw[i+k])*A[i+j+k])%mod,A[i+j+k]=(A[j+k]-tmp)%mod,(A[j+k]+=tmp)%=mod;
}
inline void solve(char c)
{
	for(int i=0;i<lim;++i)A[i]=B[i]=0;
	for(int i=0;i<n;++i)if(S[i]==c)++A[max(i-k,0)],--A[min(i+k+1,n)];
	for(int i=0;i<n;++i)A[i+1]+=A[i],A[i]=(A[i]>0);
	for(int i=0;i<m;++i)B[i]=(T[m-1-i]==c);
	NTT(A,1),NTT(B,1);
	for(int i=0;i<lim;++i)(sum[i]+=A[i]*B[i])%=mod;
}
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,S,T),init(),solve('A'),solve('C'),solve('G'),solve('T'),NTT(sum,0);
	for(int i=0;i<lim;++i)ans+=(((((sum[i]*inv)%mod)+mod)%mod)==m);
	return 0&printf("%d",ans);
}