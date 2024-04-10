#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,b,a) for(register int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(register int i=(a);i<(b);++i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
#define gc() getchar()
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=200005;
int n,k,a[N],dep[N],sz[N];ll ans;vi g[N];
void dfs(int x,int p)
{
	dep[x]=dep[p]+1;sz[x]=1;
	for(int y:g[x])if(y!=p)
	{
		dfs(y,x);sz[x]+=sz[y];
	}
}
int main()
{
	n=rd();k=rd();
	rep(i,1,n-1){int u=rd(),v=rd();g[u].pb(v);g[v].pb(u);}
	dfs(1,0);
	rep(i,1,n)a[i]=dep[i]-sz[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	rep(i,1,k)ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}