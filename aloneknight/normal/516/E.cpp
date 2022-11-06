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
const int N=200005;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int exgcd(int a,int b,int&x,int&y){if(!b){x=1;y=0;return a;}int g=exgcd(b,a%b,y,x);y=y-a/b*x;return g;}
int nn;set<int>S,gn[N],gm[N];map<int,int>D;
struct st{int t,d,o;}a[N];
inline bool cmp(st a,st b){return a.t<b.t;}
ll sol(int n,int m,int o)
{
	ll res=-1e14;S.clear();D.clear();
	for(int x:gn[o])S.insert(x),D[x]=x;
	for(int x:gm[o])
	{
		int y=x%n;S.insert(y);
		if(D.count(y))D[y]=min(D[y],x);else D[y]=x;
	}
	int x,y;exgcd(m,n,x,y);x=(x%n+n)%n;nn=0;int t=*S.begin();
	for(int p:S)a[++nn]=(st){1ll*x*(p-t)%n,D[p],gn[o].count(p)};
	sort(a+1,a+nn+1,cmp);a[nn+1]=(st){n,-1,-1};
	rep(i,1,nn)if(!a[i].o||a[i+1].t>a[i].t+1)res=max(res,a[i].d+1ll*(a[i+1].t-a[i].t-1)*m);
	return res;
}
int main()
{
	int n=rd(),m=rd(),g=gcd(n,m);ll ans=0;
	if(g>200000){puts("-1");return 0;}
	int B=rd();rep(i,1,B){int x=rd();gn[x%g].insert(x/g);}
	int G=rd();rep(i,1,G){int x=rd();gm[x%g].insert(x/g);}
	rep0(i,0,g)
	{
		if(!gn[i].size()&&!gm[i].size()){puts("-1");return 0;}
		ans=max(ans,sol(n/g,m/g,i)*g+i);swap(gn[i],gm[i]);
		ans=max(ans,sol(m/g,n/g,i)*g+i);swap(gn[i],gm[i]);
	}
	printf("%lld\n",ans);return 0;
}