#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<ll,int>
#define pll pair<ll,ll>
#define db long double
#define mp make_pair
#define X first
#define Y second
#define FR first
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<(a).size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc getchar
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=300010;
const int P=998244353;
int r[N],w[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline void ntt(int n,int*a,int f)
{
	int l=1;while((1<<l)<n)l++;
	rep0(i,1,n)r[i]=r[i>>1]>>1|(i&1)<<(l-1);
	rep0(i,0,n)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int wn=pw(3,f==1?(P-1)/i:P-1-(P-1)/i);
		w[0]=1;rep0(j,1,(i>>1))w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<n;j+=i)
		{
			int*x=a+j,*y=a+j+(i>>1);
			rep0(k,0,(i>>1)){int v=1ll*y[k]*w[k]%P;y[k]=(x[k]+P-v)%P;x[k]=(x[k]+v)%P;}
		}
	}
	if(f==-1){int iv=pw(n,P-2);rep0(i,0,n)a[i]=1ll*a[i]*iv%P;}
}
inline vi operator+(const vi&a,const vi&b)
{
	vi c=a;c.resize(max(a.size(),b.size()));
	fore(i,b)c[i]=(c[i]+b[i])%P;return c;
}
int t1[N],t2[N];
inline vi operator*(vi a,vi b)
{
	int na=a.size(),nb=b.size(),nc=na+nb-1;
	int nn=1;while(nn<nc)nn<<=1;
//	cout<<"op1"<<" "<<nn<<endl;
	rep0(i,0,nn)t1[i]=t2[i]=0;
	fore(i,a)t1[i]=a[i];
	fore(i,b)t2[i]=b[i];
//	fore(i,a)cout<<a[i]<<" ";cout<<endl;
//	fore(i,b)cout<<b[i]<<" ";cout<<endl;
	ntt(nn,t1,1);ntt(nn,t2,1);
	rep0(i,0,nn)t1[i]=1ll*t1[i]*t2[i]%P;
	ntt(nn,t1,-1);vi c;c.resize(nc);
	fore(i,c)c[i]=t1[i];
//	fore(i,c)cout<<c[i]<<" ";cout<<endl;
	return c;
}
int n,fa[N],sz[N],hs[N];ll m;vi G[N],a[N],p[N];
void dfs(int x,int p)
{
	fa[x]=p;sz[x]=1;hs[x]=0;
	for(int y:G[x])if(y!=p)
	{
		dfs(y,x);sz[x]+=sz[y];
		if(sz[y]>sz[hs[x]])hs[x]=y;
	}
}
void sol(int l,int r,vi&f,vi&g)
{
	if(l==r){f=g=a[l];return;}int m=l+r>>1;vi fl,fr,gl,gr;
	sol(l,m,fl,gl);sol(m+1,r,fr,gr);f=fl*fr;g=(fl*gr)+gl;
}
vi dfs2(int x)
{
	for(int t=x;t;t=hs[t])
	{
		p[t].clear();p[t].pb(1);
		for(int y:G[t])if(y!=fa[t]&&y!=hs[t])p[t]=p[t]*dfs2(y);
		p[t].resize(p[t].size()+1);
		for(int i=p[t].size()-1;i;i--)p[t][i]=p[t][i-1];
		p[t][0]=0;
//		cout<<x<<"T"<<t<<endl;
	}
//	cout<<" X "<<x<<":";fore(i,p[x])cout<<p[x][i]<<" ";cout<<endl;
	int nn=0;for(int t=x;t;t=hs[t])a[++nn]=p[t];
//	cout<<nn<<" A:"<<endl;
//	rep(i,1,nn){fore(j,a[i])cout<<a[i][j]<<" ";cout<<endl;}
	vi f,g;sol(1,nn,f,g);
	g[0]++;
//	cout<<" X "<<x<<":";fore(i,g)cout<<g[i]<<" ";cout<<endl;
	return g;
}
int main()
{
	n=rd();m=rd()%P;
	rep0(i,1,n){int u=rd(),v=rd();G[u].pb(v);G[v].pb(u);}
	dfs(1,0);vi res=dfs2(1);int c=1,ans=0;res[0]=(res[0]+P-1)%P;
	for(int i=1;i<res.size();i++)
	{
//		cout<<i<<" "<<res[i]<<" "<<c<<endl;
		ans=(ans+1ll*c*res[i])%P;
		c=1ll*c*(m+i)%P*pw(i,P-2)%P;
	}
	printf("%d\n",ans);return 0;
}