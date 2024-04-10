#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=5005;
char ss[N];
char c;
int n;
int f[N][N];//i    
int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	int tot=0,tot1;
	while ((1<<(tot+1))<=n) tot++;
	tot1=(1<<tot)-1;// 
//	printf("YES:%d\n",tot1);
	memset(f,true,sizeof(f));
	for (int u=1;u<=n-tot1;u++)
	{
		for (int i=0;i<=tot1;i++) f[u][i]=f[u-1][i];
		c='z';
		for (int i=0;i<=tot1;i++)
			if (f[u][i]&&ss[u+i]<c)
			{
			//	printf("YES:%d %d\n",u,i);
				c=ss[u+i];
			}
		printf("%c",c);
		for (int i=0;i<=tot1;i++) if (ss[u+i]!=c)	f[u][i]=false;
		for (int i=0;i<=tot1;i++)
		if (f[u][i])
		for (int j=0;j<tot;j++)
		if ((i&(1<<j))==0)
		f[u][i^(1<<j)]=true;
	}
	return 0;
}