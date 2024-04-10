#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int a[N],b[N],f[N],n,m,mx[N];
int pos[N],x[N];
long long p[N];
int main()
{
    int T;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&p[i]),pos[i]=(i-1)*100,p[i]+=p[i-1];
	for(int i=1;i<=m;++i)scanf("%d",&x[i]);
	sort(x+1,x+m+1);
	x[m+1]=2e9;
	x[0]=-1e9;
	int now=0,now1=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		while(x[now+1]<=pos[i])now++;
		if(pos[i]==x[now])continue;
		now1=max(now1,i);
		ll pp=pos[i]+(pos[i]-x[now]);
		while(now1<n&&pos[now1+1]<x[now+1]&&(x[now+1]-pos[now1+1])>pos[now1+1]-pp)now1++;
		ans=max(ans,p[now1]-p[i-1]);
	}
	cout<<ans;
	return 0;
}