#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,l,n2;
int nx[202];
char s[202];
int f[202][202][102]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int add(int x,int y)
{
	if((x+=y)>=mod)x-=mod;
	return x;
}
int main()
{
	read(n),n2=(n<<1),scanf("%s",s+1),l=strlen(s+1),f[0][0][0]=1,nx[1]=0;
	for(int i=2;i<=l;++i)
	{
		for(nx[i]=nx[i-1];nx[i] && s[i]!=s[nx[i]+1];nx[i]=nx[nx[i]]);
		if(s[i]==s[nx[i]+1])++nx[i];
	}
	for(int i=l;i;--i)
	{
		for(nx[i]=nx[i-1];nx[i] && s[i]==s[nx[i]+1];nx[i]=nx[nx[i]]);
		if(s[i]!=s[nx[i]+1])++nx[i];
	}
	for(int i=0,c;i<n2;++i)
	{
		for(int k=0;k<l;++k)
			for(int j=0;j<=n;++j)
			{
				if((c=j+(s[k+1]=='('? 1:-1))>=0 && c<=n)f[i+1][k+1][c]=add(f[i+1][k+1][c],f[i][k][j]);
				if((c=j-(s[k+1]=='('? 1:-1))>=0 && c<=n)f[i+1][nx[k+1]][c]=add(f[i+1][nx[k+1]][c],f[i][k][j]);
			}
		for(int j=0;j<=n;++j)
		{
			if((c=j+1)<=n)f[i+1][l][c]=add(f[i+1][l][c],f[i][l][j]);
			if((c=j-1)>=0)f[i+1][l][c]=add(f[i+1][l][c],f[i][l][j]);
		}
	}
	return 0&printf("%d",f[n2][l][0]);
}