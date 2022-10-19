#include<bits\stdc++.h>
using namespace std;
int n,m,t=1;
int a[10002],l[10002],r[10002],x[10002],id[10002],arr[10002]={},to[10002],ans[10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int A,int B)
{
	return a[x[A]]<a[x[B]]? 1:0;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x)
{
	while(x<=n)++arr[x],x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]),to[a[i]]=i;
	for(int i=1;i<=m;++i)read(l[i]),read(r[i]),read(x[i]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		while(t<a[x[id[i]]])modify(to[t]),++t;
		ans[id[i]]=(query(r[id[i]])-query(l[id[i]]-1)==x[id[i]]-l[id[i]]);
	}
	for(int i=1;i<=m;++i)puts(ans[i]? "Yes":"No");
	return 0;
}