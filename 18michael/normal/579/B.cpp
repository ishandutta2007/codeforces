#include<bits/stdc++.h>
using namespace std;
int n,a_t=0;
int to[802];
struct aaa
{
	int x,y,val;
}a[640002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val>b.val? 1:0;
}
int main()
{
	read(n),n<<=1;
	for(int i=2;i<=n;++i)
		for(int j=1;j<i;++j)
			read(a[++a_t].val),a[a_t].x=i,a[a_t].y=j;
	sort(a+1,a+a_t+1,cmp);
	for(int i=1;i<=a_t;++i)
	{
		if(to[a[i].x] || to[a[i].y])continue;
		to[a[i].x]=a[i].y,to[a[i].y]=a[i].x;
	}
	for(int i=1;i<=n;++i)printf("%d ",to[i]);
	return 0;
}