#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define ll long long
struct data
{
	int x,y,Y,v;
	bool operator<(const data &a)const
	{
		return x<a.x;
	}
}a[N];
int b[N],cnt[N],n,x,y,t,m;
ll ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		a[i]={x,y,y+m,1};
		a[i+n]={x+m,y,y+m,-1};
		b[i]=y;
		b[i+n]=y+m;
	}
	sort(b+1,b+2*n+1);
	/*for (int i=1;i<=2*n;++i)
		if (b[i]!=b[i-1])
			b[++b[0]]=b[i];*/
	t=unique(b+1,b+2*n+1)-b-1;
	for (int i=1;i<=2*n;++i)
	{
		a[i].y=lower_bound(b+1,b+1+t,a[i].y)-b+1;
		a[i].Y=lower_bound(b+1,b+1+t,a[i].Y)-b;
	}
	sort(a+1,a+2*n+1);
	for (int i=1;i<=2*n;++i)
		for (int j=a[i].y;j<=a[i].Y;++j)
		{
			ans[cnt[j]]+=1ll*(b[j]-b[j-1])*a[i].x;
			cnt[j]+=a[i].v;
			ans[cnt[j]]-=1ll*(b[j]-b[j-1])*a[i].x;
		}
	for (int i=1;i<=n;++i)
		cout<<ans[i]<<' ';
}