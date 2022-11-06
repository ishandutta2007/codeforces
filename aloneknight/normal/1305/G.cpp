#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=300005,M=1<<18;
int n,a[N],fa[N],cnt[N];ll ans;
int fnd(int x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
void merge(int u,int v,int w)
{
	if(!cnt[u]||!cnt[v])return;
	u=fnd(u);v=fnd(v);if(u==v)return;
	ans+=1ll*w*(cnt[u]+cnt[v]-1);fa[u]=v;cnt[v]=1;
}
int main()
{
	scanf("%d",&n);cnt[0]=1;
	rep(i,1,n){scanf("%d",&a[i]);cnt[a[i]]++;ans-=a[i];}
	for(int i=0;i<M;i++)fa[i]=i;
	for(int i=M-1;~i;i--)
	{
		for(int j=i;j;j=(j-1)&i)if(cnt[j]&&cnt[i^j])merge(j,i^j,i);
		merge(i,0,i);
	}
	printf("%lld\n",ans);return 0;
}