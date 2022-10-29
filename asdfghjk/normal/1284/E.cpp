#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node
{
	int x,y;
}a[5505],b[5505];
int n,i,j,k,cnt;
ll ans;
int xx(node a)
{
	if(a.y>0)
	{
		if(a.x>0)
			return 1;
		else
			return 2;
	}
	else
	{
		if(a.x>0)
			return 4;
		else
			return 3;
	}
}
ll Mult(node a,node b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool cmp(node a,node b)
{
	int i=xx(a),j=xx(b);
	if(i!=j)
		return i<j;
	ll mt=Mult(a,b);
	return mt>0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;++i)
	{
		cnt=0;
		for(j=1;j<=n;++j)
			if(i!=j)
				b[++cnt]=(node){a[j].x-a[i].x,a[j].y-a[i].y};
		sort(b+1,b+1+cnt,cmp);
		for(j=1;j<=cnt;++j)
			b[j+cnt]=b[j];
		for(j=1,k=2;j<=cnt;++j)
		{
			k=max(k,j+1);
			while(Mult(b[j],b[k])>0)
				++k;
			ans+=1ll*(k-j-1)*(k-j-2)/2+1ll*(cnt-1-(k-j-1))*(cnt-1-(k-j-1)-1)/2;
			//printf("%d %d   %d %d   %d %d   %lld\n",a[i].x,a[i].y,b[j].x,b[j].y,b[k].x,b[k].y,1ll*(k-j-1)*(cnt-1-(k-j-1)));
		}
	}
	ans/=2;
	ans=1ll*(n-1)*(n-2)*(n-3)/6*n-ans;
	ans=ans*(n-4)/2;
	printf("%lld",ans);
	return 0;
}