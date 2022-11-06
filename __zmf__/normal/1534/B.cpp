	//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9;
int taxi,n,a[N],ans;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();a[n+1]=0;
		for(int i=1;i<=n+1;i++)ans+=abs(a[i]-a[i-1]);
		for(int i=1;i<=n;i++)
			if(a[i]>a[i-1]&&a[i]>a[i+1])ans-=(a[i]-max(a[i-1],a[i+1])),a[i]=max(a[i-1],a[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}