#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,l,r,mid,val1,valn,valx,valy,valz,val[100009];
int main()
{
	n=read();l=1,r=n;
	val[0]=val[n+1]=1e9;
	for(int i=1;i<=30;i++)
	{
		if(r-l<=10)
		{
			if(l-1!=0)
			{
				printf("? %d\n",l-1);
				fflush(stdout);
				scanf("%d",&val[l-1]);
			}
			if(r+1!=n+1)
			{
				printf("? %d\n",r+1);
				fflush(stdout);
				scanf("%d",&val[r+1]);
			}
			for(int j=l;j<=r;j++)
			{
				printf("? %d\n",j);
				fflush(stdout);
				scanf("%d",&val[j]);
			}
			for(int j=l;j<=r;j++)
			{
				if(val[j]<val[j-1]&&val[j]<val[j+1])
				{
					printf("! %d\n",j);
					fflush(stdout);
					return 0;
				}
			}
		}
		mid=(l+r)/2;
		printf("? %d\n",mid);
		fflush(stdout);
		scanf("%d",&valx);
		printf("? %d\n",mid+1);
		fflush(stdout);
		scanf("%d",&valy);
		printf("? %d\n",mid-1);
		fflush(stdout);
		scanf("%d",&valz);
		if(valy<valx)
		{
			l=mid+1;
		}
		else if(valz<valx)
		{
			r=mid-1;
		}
		else
		{
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}