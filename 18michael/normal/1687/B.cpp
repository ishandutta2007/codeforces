#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,ans=0;
int a[502],b[502],id[502];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)
	{
		id[i]=i,printf("? ");
		for(int j=1;j<=m;++j)printf("%d",j==i);
		puts(""),fflush(stdout),scanf("%d",&a[i]);
	}
	sort(id+1,id+m+1,cmp);
	for(int i=1,x;i<=m;++i)
	{
		//printf("ans:%d a[%d]:%d\n",ans,i,a[i]);
		b[id[i]]=1,printf("? ");
		for(int j=1;j<=m;++j)printf("%d",b[j]);
		puts(""),fflush(stdout),scanf("%d",&x);
		if(x-ans!=a[id[i]])b[id[i]]=0;
		else ans=x;
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}