#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
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
const int N=1<<21;
int n,nn,mx,sz[N],o[N],f[N];ll a[25],s[N];
int main()
{
	n=rd();rep(i,1,n){a[i]=rd();if(!a[i])n--,i--;}nn=1<<n;
	rep0(i,0,nn)rep(j,1,n)if(i>>(j-1)&1)s[i]+=a[j],sz[i]++;
	rep0(i,1,nn)
	{
		for(int j=(i-1)&i;2*j>=i&&j;j=(j-1)&i)
		{
			int S=i^j,T=j,c=sz[i]-1;ll w=abs(s[S]-s[T]);
			if(w<=c&&(w+c)%2==0){o[i]=1;f[i]=1;break;}
		}
	}
	rep0(i,1,nn)if(o[i])
	{
		int S=(nn-1)^i;
		for(int j=S;j;j=(j-1)&S)f[i|j]=max(f[i|j],f[j]+1);
	}
	rep0(i,0,nn)mx=max(mx,f[i]);
	printf("%d\n",n-mx);return 0;
}