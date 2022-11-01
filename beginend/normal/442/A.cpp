#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;

int n,size[N*10],bin[15],cnt[2005];
struct data{int x,y;}a[N],t[N*10][N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch[3];scanf("%s",ch);
		if (ch[0]=='R') a[i].x=1;
		else if (ch[0]=='G') a[i].x=2;
		else if (ch[0]=='B') a[i].x=3;
		else if (ch[0]=='Y') a[i].x=4;
		else a[i].x=5;
		a[i].y=ch[1]-'0';
	}
	int ans=10;
	bin[0]=1;
	for (int i=1;i<=10;i++) bin[i]=bin[i-1]*2;
	for (int i=0;i<bin[10];i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int s=0;s<bin[10];s++)
	{
		memset(size,0,sizeof(size));
		int tot=1;size[1]=n;
		for (int i=1;i<=n;i++) t[1][i]=a[i];
		for (int i=1;i<=5;i++)
		{
			if (!(s&bin[i-1])) continue;
			int tmp=tot;
			for (int j=1;j<=tmp;j++)
			{
				tot++;
				for (int k=1;k<=size[j];k++)
					if (t[j][k].x==i) t[tot][++size[tot]]=t[j][k],t[j][k].x=t[j][k].y=0;
				if (!size[tot]) tot--;
			}
		}
		for (int i=1;i<=5;i++)
		{
			if (!(s&bin[i+4])) continue;
			int tmp=tot;
			for (int j=1;j<=tmp;j++)
			{
				tot++;
				for (int k=1;k<=size[j];k++)
					if (t[j][k].y==i) t[tot][++size[tot]]=t[j][k],t[j][k].x=t[j][k].y=0;
				if (!size[tot]) tot--;
			}
		}
		int flag=0;
		for (int i=1;i<=tot;i++)
		{
			data u;u.x=u.y=0;
			for (int j=1;j<=size[i];j++)
			{
				if (!t[i][j].x) continue;
				if (!u.x) u=t[i][j];
				else if (u.x!=t[i][j].x||u.y!=t[i][j].y) {flag=1;break;}
			}
			if (flag) break;
		}
		if (!flag) ans=min(ans,cnt[s]);
	}
	printf("%d",ans);
	return 0;
}