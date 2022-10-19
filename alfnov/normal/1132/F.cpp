#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int f[505][505];
char s[505];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=n-1;i>=0;i--)s[i+1]=s[i];
	s[0]=0;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])f[i][j]=min(f[i+1][j],f[i][j-1]);
			else for(int k=i;k<j;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	printf("%d\n",f[1][n]);
	return 0;
}