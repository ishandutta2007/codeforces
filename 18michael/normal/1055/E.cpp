#include<bits/stdc++.h>
using namespace std;
int n,s,m,k,l=1,r,mid;
int a[1502],id[1502],S[1502],E[1502],num[1502],id1[1502],pre[1502];
int f[1502][1502]={};
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
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
inline bool cmp1(int x,int y)
{
	return E[x]<E[y]? 1:0;
}
int main()
{
	read(n),read(s),read(m),read(k),r=n;
	for(int i=1;i<=n;++i)read(a[i]),id[i]=i;
	for(int i=1;i<=s;++i)read(S[i]),read(E[i]),id1[i]=i;
	sort(id+1,id+n+1,cmp),sort(id1+1,id1+s+1,cmp1);
	for(int i=1;i<=s;++i)
		for(int j=1;j<=s;++j)
			if(i!=j && E[j]<E[i] && E[j]>=S[i] && (!num[i] || S[j]<S[num[i]]))
				num[i]=j;
	while(l<=r)
	{
		mid=((l+r)>>1);
		for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(a[i]<=a[id[mid]]);
		for(int i=1,i1=1;i<=n;++i)
		{
			for(int j=0;j<=m;++j)f[i][j]=f[i-1][j];
			for(;i1<=s && E[id1[i1]]==i;++i1)
				for(int j=1;j<=m;++j)
				{
					f[i][j]=max(f[i][j],f[S[id1[i1]]-1][j-1]+pre[i]-pre[S[id1[i1]]-1]);
					if(num[id1[i1]])f[i][j]=max(f[i][j],f[E[num[id1[i1]]]][j-1]+pre[i]-pre[E[num[id1[i1]]]]);
				}
		}
		if(f[n][m]>=k)r=mid-1;else l=mid+1;
	}
	return 0&printf("%d",l<=n? a[id[l]]:-1);
}