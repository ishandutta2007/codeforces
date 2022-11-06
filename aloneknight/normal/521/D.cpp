#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
const int N=1e5+5;
int k,n,m,a[N],op[N];pii mx[N];
vector<pii>add[N];
vector<pair<double,int> >mul;
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int o,p,x;scanf("%d%d%d",&o,&p,&x);op[i]=o;
		if(o==1)mx[p]=max(mx[p],mp(x,i));
		if(o==2)add[p].pb(mp(x,i));
		if(o==3)mul.pb(mp(x,i));
	}
	for(int i=1;i<=k;i++)
	{
		if(mx[i].X>a[i])add[i].pb(mp(mx[i].X-a[i],mx[i].Y));
		sort(add[i].begin(),add[i].end()),reverse(add[i].begin(),add[i].end());
		ll s=a[i];for(pii t:add[i])mul.pb(mp(1.0*(s+t.X)/s,t.Y)),s+=t.X;
	}
	sort(mul.begin(),mul.end());reverse(mul.begin(),mul.end());m=min(m,(int)mul.size());
	printf("%d\n",m);
	for(int i=0;i<m;i++)if(op[mul[i].Y]==1)printf("%d ",mul[i].Y);
	for(int i=0;i<m;i++)if(op[mul[i].Y]==2)printf("%d ",mul[i].Y);
	for(int i=0;i<m;i++)if(op[mul[i].Y]==3)printf("%d ",mul[i].Y);
	return 0;
}