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
	ll x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=1<<19,M=55,P=998244353;
int n,m,sz,C[M][M],s[N],b[M],ans[M];ll a[M];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int gtw(ll x){return s[x&524287]+s[(x>>19)&524287]+s[x>>38];}
namespace Sol1
{
	void dfs(int x,ll w)
	{
		if(x==sz){ans[gtw(w)]++;return;}
		dfs(x+1,w);dfs(x+1,w^a[b[x]]);
	}
}
namespace Sol2
{
	ll st[M+3];ll f[M+3];
	void dfs(int x,int c,ll w)
	{
		if(x==m){f[c+gtw(w)]++;return;}
		dfs(x+1,c,w);dfs(x+1,c+1,w^st[x]);
	}
	void sol()
	{
		rep0(i,sz,m)rep0(j,0,sz)if(a[b[j]]>>b[i]&1)st[i]|=1ll<<j;
		dfs(sz,0,0);
		rep(k,0,m)
		{
			rep(i,0,m)
			{
				int res=0;
				rep(j,0,min(i,k))res=(res+1ll*(j&1?P-1:1)*C[i][j]%P*C[m-i][k-j])%P;
				ans[k]=(ans[k]+1ll*res*f[i])%P;
			}
			ans[k]=1ll*ans[k]*pw((P+1)/2,m-sz)%P;
		}
	}
}
int main()
{
	n=rd();m=rd();
	rep(i,0,m)C[i][0]=1;
	rep(i,1,m)rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	rep0(i,1,N)s[i]=s[i>>1]+(i&1);
	rep(i,1,n)
	{
		ll x=rd();
		per(j,m-1,0)if(x>>j&1){if(!a[j]){a[j]=x;sz++;break;}else x^=a[j];}
	}
	per(i,m-1,0)if(a[i])rep0(j,i+1,m)if(a[j]>>i&1)a[j]^=a[i];
	for(int i=0,j=0;i<sz;b[i++]=j++)while(!a[j])j++;
	for(int i=sz,j=0;i<m;b[i++]=j++)while(a[j])j++;
	if(sz<=26)Sol1::dfs(0,0);else Sol2::sol();
	int t=pw(2,n-sz);rep(i,0,m)printf("%d ",1ll*ans[i]*t%P);return 0;
}