#include<bits/stdc++.h>
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
	if(a<b)return 0&puts("-1");
	printf("%.12lf",1.0*(a+b)/2/((a+b)/2/b));
	return 0;
}