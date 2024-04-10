//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e6+9,INF=1e9;
int floyd[109][109],n,m,top;
int stac[N];
char s[109];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			floyd[i][j]=INF;
	for(int i=1;i<=n;i++)floyd[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			if(s[j]=='1')floyd[i][j]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
	m=read();
	for(int i=1;i<=m;i++)
	{
		stac[++top]=read();
		while(top>=3)
		{
			if(floyd[stac[top-2]][stac[top-1]]+floyd[stac[top-1]][stac[top]]==floyd[stac[top-2]][stac[top]])top--,stac[top]=stac[top+1];
			else break;
		}
	}
	cout<<top<<endl;
	for(int i=1;i<=top;i++)printf("%d ",stac[i]);
	return 0;
}