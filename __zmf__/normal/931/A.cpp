//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int a,b,x,pp,qq;
int main()
{
	a=read(),b=read();x=abs(a-b);
	pp=x/2,qq=x-pp;
	cout<<pp*(pp+1)/2+qq*(qq+1)/2<<endl;
	return 0;
}