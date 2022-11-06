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
const int N=100005;
int n,m,nn,lst=2e9,a[N],b[N],p1[N],p2[N],vis[N];pii f[N];
inline int gt(int x){return a[f[x].Y]==-1?p2[x]:f[x].Y;}
int main()
{
	n=rd();rep(i,1,n)a[i]=rd();
	m=rd();rep(i,1,m)b[i]=rd();
	sort(b+1,b+m+1);
	rep(i,1,n)
	{
		if(a[i]==-1)
		{
			nn+=b[m]>f[nn].X;
			for(int j=m,k=nn;j;j--)
			{
				while(k>1&&f[k-1].X>=b[j])k--;
				f[k]={b[j],i};p2[k]=gt(k-1);
			}
		}
		else
		{
			int l=1,r=nn+1,md;
			while(l<r)if(f[md=l+r>>1].X<a[i])l=md+1;else r=md;
			f[l]={a[i],i};p2[l]=p1[i]=gt(l-1);nn+=nn<l;
		}
	}
	for(int i=gt(nn),j=n,k=m;;lst=a[i],i=p1[i])
	{
		for(;j>i;j--)if(a[j]==-1)
		{
			while(b[k]>=lst)k--;
			if(k&&b[k]>a[i])lst=a[j]=b[k],vis[k--]=1;
		}
		if(!i)break;
	}
	int j=1;rep(i,1,n)if(a[i]==-1){while(vis[j])j++;a[i]=b[j++];}
	rep(i,1,n)printf("%d ",a[i]);return 0;
}