#include<bits/stdc++.h>
using namespace std;
int a,b;
double ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(double x)
{
	return x>=b;
}
int main()
{
	read(a),read(b);
	if(a<b)return 0&puts("-1");
//	1.0*(a+b)/((a+b)/2/b)
//	ans=1.0*(a+b)/2;
//	while(check(ans/2))ans/=2;
	printf("%.12lf",1.0*(a+b)/2/((a+b)/2/b));
	return 0;
}