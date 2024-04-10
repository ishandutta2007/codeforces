#include<bits/stdc++.h>
using namespace std;
const int N=200005,P=1e9+7;
int n,c,pc[N],iv[N],vis[N],pr[N],mu[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int s(int x,int t){return (pc[x]==1)?t:1ll*iv[x]*(pc[x*t]-1)%P;}
int S(int x,int t)
{
	if(pc[x]==1)return 1ll*t*(t+1)/2%P;
	return (1ll*pc[x*t]*t-s(x,t-1)-1)%P*iv[x]%P;
}
int main()
{
	scanf("%d%d",&n,&c);mu[1]=1;
	if(c==1){printf("%d\n",1ll*(n-1)*(n-1)%P);return 0;}
	for(int i=2;i<N;i++)
	{
		if(!vis[i])pr[++pr[0]]=i,mu[i]=-1;
		for(int j=1;j<=pr[0]&&i*pr[j]<N;j++)
		{
			int t=i*pr[j];vis[t]=1;mu[t]=-mu[i];
			if(i%pr[j]==0){mu[t]=0;break;}
		}
	}
	for(int i=pc[0]=1;i<N;i++)pc[i]=1ll*pc[i-1]*c%P,iv[i]=pw(pc[i]-1,P-2)+1;
	int f=0,g=0,a,b;
	for(int d=1;d<n;d++)
	{
		int t=0;
		for(int k=1,ed=(n-1)/d;k<=ed;k++)b=(n-1+d)/d/k,t=(t+1ll*mu[k]*b*(b-1)/2)%P;
		f=(f+1ll*t*pw(pc[n-d],P-2))%P;
	}
	for(int d=1;d<n;d++)
	{
		int t=0;
		for(int k=1,ed=(n-1)/d;k<=ed;k++)
		{
			a=(n-1)/d/k*2,b=(n-1+d)/d/k;
			t=(t+1ll*mu[k]*(a+1)*(s(d*k,a)-s(d*k,b)))%P;
			t=(t-1ll*mu[k]*(S(d*k,a)-S(d*k,b)))%P;
		}
		g=(g+1ll*t*pw(pc[n+n],P-2))%P;
	}
	printf("%d\n",(1ll*f+g+P+P)%P);
	return 0;
}