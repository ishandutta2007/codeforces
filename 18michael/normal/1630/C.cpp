#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,ans=0,st,mx=0,res=0,la=0;
int a[200002],l[200002],r[200002],f[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]),r[a[i]]=i;
		if(!l[a[i]])l[a[i]]=i;
	}
	/*for(int i=1;i<=n;++i)
	{
		f[i]=min(f[l[a[i]]-1]+2,f[i-1]+1);
	}*/
	for(st=1;st<=n;/*printf("%d:%d %d %d\n",st,ans,mx,res),*/++st)
	{
		if(l[a[st]]!=r[a[st]] || st<mx)++ans;
		//printf("%d %d\n",l[a[st]],r[a[st]]);
		if(l[a[st]]==st)
		{
			if(r[a[st]]<mx)continue;
			if(r[a[st]]>st)
			{
				if(la<=st)la=mx,++res;
				mx=r[a[st]];
			}
		}
		if(st==mx)ans-=res+1,res=0;
	}
	return 0&printf("%d",ans);
}
/*
10
1 2 3 4 5 1 2 3 4 5
10
1 2 3 4 1 5 2 3 4 5
*/