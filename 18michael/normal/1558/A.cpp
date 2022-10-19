#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,Test_num;
bool u[200002];
vector<int> vec;
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
		vec.clear(),read(a),read(b),c=a+b;
		if(a>b)swap(a,b);
		for(int i=0;i<=c;++i)u[i]=0;
		if(!(c&1))
		{
			d=(b-a)/2,e=(b+3*a)/2;
			for(int i=d;i<=e;i+=2)u[i]=1;
		}
		else
		{
			d=(b-1-a)/2,e=(b+1+3*a)/2;
			for(int i=d;i<=e;i+=2)u[i]=u[c-i]=1;
		}
		for(int i=0;i<=c;++i)if(u[i])vec.push_back(i);
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
	}
	return 0;
}