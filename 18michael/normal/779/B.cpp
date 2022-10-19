#include<bits/stdc++.h>
using namespace std;
int n,k,t,ans=0;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(k);
	while(n && k)++t,ans+=((n%10)>0),k-=(!(n%10)),n/=10;
	return 0&printf("%d",k? t-(ans!=t):ans);
}