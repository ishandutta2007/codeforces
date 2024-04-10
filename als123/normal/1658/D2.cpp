#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
int T;
int bin[N];
int a[N];
int main()
{
	bin[0]=bin[1]=0;for (int u=2;u<(1<<17);u++) bin[u]=bin[u>>1]+1;
	scanf("%d",&T);
	while (T--)
	{
		int l,r,n;
		scanf("%d%d",&l,&r);
		n=(r-l+1);
	
		for (int u=l;u<=r;u++) scanf("%d",&a[u]);
		int up=17,ans=0;
		int cnt0,cnt1,d,t;
		while (up>=0)
		{
			t=1<<up;
			cnt0=0;cnt1=0;d;
			for (int u=r;u>=l;u--) 
			{
				if (u&t) 
				{
					cnt0++;
					d=u;
				}
				if (a[u]&t) cnt1++;
			}
			if (cnt0==0||cnt0==n)
			{
				if (cnt0!=cnt1)
				{
					//printf("%d %d %d\n",up,cnt0,cnt1);
					ans^=t;
					for (int u=l;u<=r;u++) a[u]^=t;
				}
				up--;
			}
			else break;
		}
		if (up>=0)
		{
			if (cnt0!=cnt1)
			{
				ans^=t;
				for (int u=l;u<=r;u++) a[u]^=t;
			}
		}
		sort(a+l,a+r+1);
		/*for (int u=l;u<=r;u++) printf("%d ",a[u]); 
		printf("%d\n",d);*/
		for (int u=up-1;u>=0;u--)
		{
			int tot=0,xx=(1<<u);
			for (int i=d;i<=r;i++) 
				if (a[i]&xx) tot--;
				else tot++;
		//	printf("%d:%d\n",u,tot);
			if (tot<0) 
			{
				for (int i=l;i<=r;i++) a[i]^=xx;
				ans^=xx;
			}
			tot=0;
			for (int i=d-1;i>=l;i--) 
				if (a[i]&xx) tot++;
				else tot--;
		//	printf("%d %d\n",u,tot);
			if (tot<0) ans^=xx;
		}
		printf("%d\n",ans);
	}
	return 0;
}