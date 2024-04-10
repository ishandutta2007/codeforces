#include<bits\stdc++.h>
using namespace std;
int a,b;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(a),read(b);
	for(int i=1;;++i)
	{
		if(i&1)a-=i;else b-=i;
		if(a<0)return 0&puts("Vladik");
		if(b<0)return 0&puts("Valera");
	}
	return 0;
}