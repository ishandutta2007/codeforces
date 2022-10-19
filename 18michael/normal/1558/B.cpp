#include<bits/stdc++.h>
using namespace std;
int n,m,res=0;
int a[4000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void Add(int &x,int y)
{
	if((x+=y)>=m)x-=m;
	if(x<=-m)x+=m;
}
int main()
{
	read(n),read(m),a[1]=1,a[2]=-1;
	for(int i=1,i1;i<n;++i)
	{
		Add(res,a[i]),i1=i+1,Add(a[i1],res);
		for(int j=i;j<=n;j+=i)Add(a[j],res);
		for(int j=i1;j<=n;j+=i1)Add(a[j],-res);
		res<<=1;
	}
	Add(res,a[n]);
	return 0&printf("%d",(res+m)%m);
}