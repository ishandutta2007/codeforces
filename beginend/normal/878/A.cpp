#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=15;

int n,bin[N],f[N][2];

int main()
{
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<=10;i++) bin[i]=bin[i-1]*2;
	for (int i=0;i<10;i++) f[i][1]=1;
	for (int i=1;i<=n;i++)
	{
		char ch[2];int x;
		scanf("%s%d",ch,&x);
		if (ch[0]=='|')
		{
			for (int j=0;j<10;j++)
				if (x&bin[j]) f[j][0]=f[j][1]=1;
		}
		else if (ch[0]=='&')
		{
			for (int j=0;j<10;j++)
				if (!(x&bin[j])) f[j][0]=f[j][1]=0;
		}
		else
		{
			for (int j=0;j<10;j++)
				if (x&bin[j]) f[j][0]^=1,f[j][1]^=1;
		}
	}
	printf("%d\n",3);
	int ans=bin[10]-1;
	for (int i=0;i<10;i++)
		if (f[i][0]==0&&f[i][1]==0) ans-=bin[i];
	printf("& %d\n",ans);
	ans=0;
	for (int i=0;i<10;i++)
		if (f[i][0]&&f[i][1]) ans+=bin[i];
	printf("| %d\n",ans);
	ans=0;
	for (int i=0;i<10;i++)
		if (f[i][0]&&!f[i][1]) ans+=bin[i];
	printf("^ %d\n",ans);
	return 0;
}