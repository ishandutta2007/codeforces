#include<bits/stdc++.h>
using namespace std;
int k;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(k);
	if(k>36)puts("-1");
	else
	{
		while(k>1)printf("8"),k-=2;
		if(k)printf("6");
	}
	return 0;
}