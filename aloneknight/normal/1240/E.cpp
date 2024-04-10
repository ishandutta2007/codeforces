#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
int n,m,a[N],s[N],nxt[N];ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m=max(m,a[i]),s[a[i]]++;
	for(int i=1;i<=m;i++)nxt[i]=s[i]?i:nxt[i-1],s[i]+=s[i-1];
	for(int y=2;y<=m;y++)
	{
		ll cnt=0;int mx=-1,mx1=-1,mx2=-1,p;
		for(int j=y;j<=m;j+=y)cnt+=1ll*(j/y)*(s[min(j+y-1,m)]-s[j-1]);
		for(int j=m-m%y;j>=0;j-=y)
		{
			int x=nxt[min(m,j+y-1)];if(x>=j)mx=max(mx,x%y);if(mx<0)continue;
			if(min(cnt-j/y,1ll*(mx+j)/2)>1)ans=max(ans,1ll*y*min(cnt-j/y,1ll*(mx+j)/2));
		}
		for(int j=m-m%y;j>=0;j-=y)
		{
			int l=min(m,j+y-1),x=nxt[l],z=(x>0&&s[x]-s[x-1]>1)?x:nxt[max(0,x-1)];
			if(x>=j)
			{
				if(x%y>mx1)mx2=mx1,mx1=x%y,p=x;else if(x%y>mx2)mx2=x%y;
				if(x%y==mx1)p=x;
			}
			if(z>=j)mx2=max(mx2,z%y);if(mx2<0)continue;
			ll t=min(1ll*(mx2+j),cnt-j/y*2);if(t>1)ans=max(ans,1ll*y*t);
			t=min(1ll*(mx1+j),cnt-j/y*2-1);
			if((p>=j+y&&s[m]-s[l]>=2||p<j+y&&s[m]-s[l]>=1)&&t>1)ans=max(ans,1ll*y*t);
		}
	}
	printf("%lld\n",ans);
	return 0;
}