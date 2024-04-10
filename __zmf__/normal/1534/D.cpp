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
const int N=2009;
int n,cnt[N],dep[N],res,qwq,maxdep,x[N],y[N],awa,dis[N];
int main()
{
	scanf("%d",&n);
	printf("? 1\n");fflush(stdout);
	for(int i=1;i<=n;i++)scanf("%d",&dep[i]);
	for(int i=1;i<=n;i++)dis[i]=dep[i];
	for(int i=2;i<=n;i++)cnt[dep[i]]++,maxdep=max(maxdep,dep[i]);
	for(int i=2;i<=maxdep;i+=2)res+=cnt[i];
	if(res>(n-1)-res)qwq=1;
	else qwq=0;
	for(int i=1;i<=n;i++)
		if(dep[i]%2==qwq)
		{
			if(i!=1)
			{
				printf("? %d\n",i);
				fflush(stdout);
				for(int j=1;j<=n;j++)scanf("%d",&dis[j]);
			}
			for(int j=1;j<=n;j++)
				if(dis[j]==1)x[++awa]=i,y[awa]=j;
		}
	printf("!\n");
	for(int i=1;i<=awa;i++)printf("%d %d\n",x[i],y[i]);
	return 0;
}