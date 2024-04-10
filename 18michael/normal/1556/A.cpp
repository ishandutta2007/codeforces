#include<bits/stdc++.h>
using namespace std;
int a,b,Test_num;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(a),read(b);
		if((a+b)&1)puts("-1");
		else if(!a && !b)puts("0");
		else if(a==b)puts("1");
		else puts("2");
	}
	return 0;
}