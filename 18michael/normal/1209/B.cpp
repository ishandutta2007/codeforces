#include<bits/stdc++.h>
using namespace std;
int n,mx=0,res;
int a[102],b[102];
char s[102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),scanf("%s",s+1);
	for(int i=1;i<=n;++i)read(a[i]),read(b[i]),s[i]-='0',mx+=s[i];
	for(int i=1;i<=100000;++i)
	{
		res=0;
		for(int j=1;j<=n;++j)
		{
			if(i>=b[j] && !((i-b[j])%a[j]))s[j]^=1;
			res+=s[j];
		}
		mx=max(mx,res);
	}
	return 0&printf("%d",mx);
}