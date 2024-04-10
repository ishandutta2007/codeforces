// https://official.contest.yandex.ru/opencupXIX/contest/12091/run-report/68740786/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1000005],b[1000005];//sx,sy;
int f[1000005];
ll sumf[1000005];
int F(int x,int xfl,int i,int j,int typ)
{
	if(typ==0) return min(i-1,f[j]-1)+(xfl==0&&a[1]+b[j]<=x);
	return min(n-i,n-f[j])+(xfl==1&&a[1]+b[j]>x);
}
int cmp(const int x,const int y)
{
	return x>y;
}
void solve(int x,int xfl,int yfl,ll &ans0,ll &ans1)
{
	int c=1;
	ll ans2=0;
	for(int j=2;j<=m;j++)
		ans2+=(xfl==1&&a[1]+b[j]>x);
	int q=m+1;
	for(int i=1;i<=n;i++)
	{
		ll nans=0;
		if(!yfl) nans+=min(i-1,f[1]-1);
		else nans+=min(n-i,n-f[1]);
		while(c<m&&F(x,xfl,i,c+1,0)>F(x,xfl,i,c+1,1))
		{
			ans2-=(xfl==1&&a[1]+b[c+1]>x);
			ans2+=(xfl==0&&a[1]+b[c+1]<=x);
			c++;
		}
		while(q>2&&f[q-1]<=i) q--;
		//int q=lower_bound(f+2,f+m+1,i,cmp)-f;
		ll q1=min(q,c+1),q2=max(q,c+1);
	//	for(int j=2;j<=c;j++)
	//		nans+=F(x,xfl,i,j,0);
		nans+=1ll*(i-1)*(q1-2)+sumf[c]-sumf[q1-1]-(c-(q1-1));
	//	for(int j=c+1;j<=m;j++)
	//		nans+=F(x,xfl,i,j,1);
		nans+=1ll*(n-i)*(m-q2+1)+1ll*n*(q2-1-c)-(sumf[q2-1]-sumf[c]);
		nans+=ans2;
	//	printf("solve:x=%d,xfl=%d,yfl=%d,i=%d,q=%d,%lld,%lld,ans2=%lld,nans=%lld,%lld,%lld\n",x,xfl,yfl,i,q,q1,q2,ans2,nans,
	//	1ll*(i-1)*(q1-2)+sumf[c]-sumf[q1-1]-(c-(q1-1)),
	//	1ll*(n-i)*(m-q2+1)+1ll*n*(q2-1-c)-(sumf[q2-1]-sumf[c]));
		ans0=max(ans0,nans);
		ans1=max(ans1,nans+(xfl&&yfl));
	}
}
int check(int x)
{
	if(a[1]+b[1]<=x) return 1;
	int nw=1;
	while(nw<n&&a[nw+1]+b[1]<=x) nw++;
	f[1]=nw;
	nw=1;
	for(int i=m;i>1;i--)
	{
		while(nw<n&&a[nw+1]+b[i]<=x) nw++;
		f[i]=nw;
	}
	sumf[1]=0;
	for(int i=2;i<=m;i++)
		sumf[i]=sumf[i-1]+f[i];
	ll ans0=0,ans1=0;
	solve(x,0,0,ans0,ans1);
	solve(x,0,1,ans0,ans1);
	solve(x,1,0,ans0,ans1);
	solve(x,1,1,ans0,ans1);
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d",(int)(a[i]+b[j]>x));
		printf("\n");
	}
	printf("check:x=%d,ans0=%lld,ans1=%lld\n",x,ans0,ans1);*/
	return ans0==ans1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+2,a+n+1);
	sort(b+2,b+m+1);
	int l=0,r=1e9,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}