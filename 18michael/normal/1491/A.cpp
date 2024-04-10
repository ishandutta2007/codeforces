#include<bits/stdc++.h>
using namespace std;
int n,q,one=0,opt,x;
int a[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(q);
	for(int i=1;i<=n;++i)read(a[i]),one+=a[i];
	while(q--)
	{
		read(opt),read(x);
		if(opt==1)one+=(a[x]? -1:1),a[x]^=1;
		else puts(x<=one? "1":"0");
	}
	return 0;
}