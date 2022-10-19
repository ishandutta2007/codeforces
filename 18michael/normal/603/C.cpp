#include<bits/stdc++.h>
using namespace std;
int n,k,res=0;
int a[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int SG(int x)
{
	if(x==0)return 0;
	if(x==1)return 1;
	if(x==2)return k? 0:2;
	if(x==3)return k? 1:0;
	if(x==4)return k? 2:1;
	if(x&1)return SG(x-1)? 0:1;
	if(!k)return 1;
	return SG(x/2)==1? 2:1;
}
int main()
{
	read(n),read(k),k&=1;
	for(int i=1;i<=n;++i)read(a[i]),res^=SG(a[i]);
	return 0&puts(res? "Kevin":"Nicky");
}