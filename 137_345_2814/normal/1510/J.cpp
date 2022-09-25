#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100500
int n,is[N],mn=1e9,f1=1,f2=1,as[N],ct,s2[N];
char st[N];
int main()
{
	scanf("%s",st+1);n=strlen(st+1);
	st[n+2]='#';
	int s1=0;
	for(int i=0;i<=n+2;i++)if(st[i]=='#')
	{
		if(!s1)continue;
		mn=min(mn,s1),is[s1-1]=1;
		if(s1&1)f2=0;
		if(s1>1)f1=0;
		s1=0;
	}
	else s1++;
	for(int i=1;i<=mn;i++)
	{
		if(i==1&&!f1)continue;
		if(i==2&&!f2)continue;
		if(is[i])continue;
		int ls=0;
		for(int j=0;j<=n+2;j++)if(st[j]=='#')
		{
			int l1=ls,r1=j-1;ls=j+1;
			if(l1>=j)continue;
			r1-=i-1;s2[r1]=1;
			while(l1<r1)
			{
				s2[l1]=1;
				int v1=l1+i;
				if(v1>r1)v1=r1;
				if(v1==r1-1)v1--;
				l1=v1;
			}
		}
		int s3=0;
		for(int j=1;j<=n-i+1;j++)if(s2[j]){if(s3)as[++ct]=s3,s3=0;}else s3++;
		if(s3)as[++ct]=s3;
		printf("%d\n",ct);for(int i=1;i<=ct;i++)printf("%d ",as[i]);
		return 0;
	}
	printf("-1\n");
}