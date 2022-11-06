#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
const int N=500005;
int n,m,ans,a[N],w[N];ll b[N];
map<int,ll>mp;
inline int rnd(){return rand()<<15^rand();}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void sol()
{
	scanf("%d%d",&n,&m);mp.clear();ll ans=0;
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]),a[i]=rnd(),w[i]=0;
	for(int i=1,u,v;i<=m;i++){scanf("%d%d",&u,&v);w[v]^=a[u];}
	for(int i=1;i<=n;i++)mp[w[i]]+=b[i];
	for(map<int,ll>::iterator it=mp.begin();it!=mp.end();it++)if(it->X)ans=gcd(ans,it->Y);
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	srand(time(0));
	while(T--)
	{
		sol();
	}
	return 0;
}