#include<bits/stdc++.h>
using namespace std;
int a[200005],a2[200005],a3[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(a3,0,sizeof(a3));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),a2[i]=a3[i]=a[i];
		int bm=n,cm=1;
		for(int i=1;i<n;i++)
		{
			if(a2[i]>a2[i+1])
			{
				bm=i;
				break;
			}
			a2[i+1]-=a2[i];
		}
		for(int i=n;i>1;i--)
		{
			if(a3[i]>a3[i-1])
			{
				cm=i;
				break;
			}
			a3[i-1]-=a3[i];
		}
		if(bm==n&&a2[n]==0||cm==1&&a3[1]==0)
		{
			puts("YES");
			continue;
		}
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if(i-1>bm||i+2<cm)continue;
			int xa=a2[i-1],xb=a[i+1],xc=a[i],xd=a3[i+2];
			if(xa>xb)continue;
			xb-=xa;
			if(xd>xc)continue;
			xc-=xd;
			if(xb==xc)
			{
				flag=1;
				puts("YES");
				break;
			}
		}
		if(!flag)puts("NO");
	}
	return 0;
}