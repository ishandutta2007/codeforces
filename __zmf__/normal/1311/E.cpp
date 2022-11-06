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
const int N=5000;
int T,n,d;
int fa[N+9],son[N+9],lg[N+9],to[N+9],l[N+9],r[N+9];									
int main()
{
	T=read();to[1]=1;
	for(int i=2;i<=N;i++)lg[i]=lg[i/2]+1,to[i]=to[i/2]*2;
	for(int i=1;i<=N;i++)l[i]=l[i-1]+lg[i],r[i]=i*(i-1)/2;
	for(int ttt=1;ttt<=T;ttt++)
	{
		n=read(),d=read();
		if(l[n]>d||r[n]<d)
		{
			puts("NO");continue;
		}
		else
		{
			puts("YES");
			int now=l[n];
			for(int i=2;i<=n;i++)fa[i]=i/2;
			for(int i=1;i<=n;i++)son[i]=0;
			for(int i=2;i<=n;i*=2)son[i/2]=i;
			for(int i=n;i>=1&&now<d;i--)
				if(to[i]!=i)
				{
					int pp=to[i];
					while(now<d&&pp)
					{
						now++;fa[i]=pp;pp=son[pp];
					}
					son[fa[i]]=i;
				}
			for(int i=2;i<=n;i++)printf("%d ",fa[i]);puts(""); 
		}
	}
	return 0;
}