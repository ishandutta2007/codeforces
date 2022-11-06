#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=1e7+5,P=1e9+7;
int n,cc,ans,a[N],b[N],c[N],vis[N],pr[N],mu[N];
int main()
{
	mu[1]=1;
	rep0(i,2,N)
	{
		if(!vis[i])pr[++cc]=i,mu[i]=-1;
		for(int j=1,t;j<=cc&&1ll*i*pr[j]<N;j++){vis[t=i*pr[j]]=1;if(i%pr[j])mu[t]=-mu[i];else break;}
	}
	n=rd();rep(i,1,n)a[rd()]++;
	b[1]=1;rep(i,2,n)b[i]=(b[i-1]*2+1)%P;
	rep(j,1,cc)per(i,(N-1)/pr[j],1)a[i]+=a[i*pr[j]];
	int t=0;rep0(i,1,N)c[i]=b[a[i]];
	rep0(i,1,N)if(mu[i])t=(t+(mu[i]==1?c[i]:P-c[i]))%P;
	c[1]=(c[1]+P-t)%P;
	rep0(i,1,N)if(mu[i])ans=(ans+1ll*(mu[i]==1?a[i]:P-a[i])*c[i])%P;
	printf("%d\n",ans);return 0;
}