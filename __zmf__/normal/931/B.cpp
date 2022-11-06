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
int n,a,b,l,res,len;
int main()
{
	n=read(),a=read(),b=read();
	while(n%2==0)l++,n/=2;
	res=1;len=2;
	while(res<=l)
	{
		if((a-1)/len==(b-1)/len)break;
		res++,len=len*2;
	}
	if(res>=l)puts("Final!");
	else cout<<res<<endl;
	return 0;
}