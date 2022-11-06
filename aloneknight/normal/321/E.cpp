#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<(a).size();++i)
#define gc getchar
inline ll rd()
{
	ll x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=4005;
int n,k,ql,qr,s[N][N],f[N],g[N];
struct st{int x,l,r;}q[N];
inline int w(int i,int j,int v){return f[j]+(s[i][i]+s[j][j])/2-s[i][j]+v;}
inline void calc(int v)
{
	f[0]=g[0]=0;ql=1;qr=1;q[1]=(st){0,1,n};
	rep(i,1,n)
	{
		while(ql<qr&&q[ql].r<i)ql++;
		f[i]=w(i,q[ql].x,v);g[i]=g[q[ql].x]+1;
		if(w(n,i,v)>=w(n,q[qr].x,v))continue;
		while(ql<qr&&w(q[qr].l,q[qr].x,v)>w(q[qr].l,i,v))qr--;
		int l=q[qr].l,r=q[qr].r+1;
		while(l<r)
		{
			int m=l+r>>1;
			if(w(m,i,v)<w(m,q[qr].x,v))r=m;else l=m+1;
		}
		q[qr].r=r-1;q[++qr]=(st){i,r,n};
	}
}
int main()
{
	n=rd();k=rd();
	rep(i,1,n)rep(j,1,n)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+rd();
	int l=0,r=s[n][n];
	while(l<r)
	{
		int m=l+r>>1;calc(m);
		if(g[n]>k)l=m+1;else r=m;
	}
	calc(r);printf("%d\n",f[n]-r*k);return 0;
}