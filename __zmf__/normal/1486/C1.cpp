#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int l,r,n,mid,taxi,x,x1,flag;
int main()
{
	scanf("%d",&n);
	l=1,r=n;
	//cout<<l<<" "<<r<<endl;
	while(l<r)
	{
		
		if(r-l==1)
		{
			if(flag==1)x=x1;
			else
			{
				printf("? %d %d\n",l,r);
				fflush(stdout);
				scanf("%d",&x);
			}
			if(l==x)printf("! %d\n",r);
			else printf("! %d\n",l);
			return 0;
		}
		mid=(l+r)/2;
		if(flag==1)
		{
			x=x1;
		}
		else
		{
			printf("? %d %d\n",l,r);
			fflush(stdout);
			scanf("%d",&x);
		}
		flag=0;
		if(x<=mid)
		{
			if(l==mid)
			{
				l=mid+1;continue;
			}
			printf("? %d %d\n",l,mid);
			fflush(stdout);
			scanf("%d",&x1);
			if(x1==x)r=mid,flag=1;
			else l=mid+1;
		}
		else
		{
			if(mid+1==r)
			{
				r=mid;continue;
			}
			printf("? %d %d\n",mid+1,r);
			fflush(stdout);
			scanf("%d",&x1);
			if(x1==x)l=mid+1,flag=1;
			else r=mid;
		}
	}
	if(l==r)printf("! %d\n",l);
	return 0;
}