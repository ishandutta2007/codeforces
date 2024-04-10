#include<bits/stdc++.h>
using namespace std;
int n,ok,Test_num;
int a[2024],p[2024];
vector<int> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void rev(int x)
{
	vec.push_back(x);
	for(int i=1;i<=x/2;++i)swap(a[i],a[x+1-i]),swap(p[a[i]],p[a[x+1-i]]);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ok=0,vec.clear();
		for(int i=1;i<=n;++i)
		{
			read(a[i]),p[a[i]]=i;
			if((a[i]^i)&1)ok=1;
		}
		if(ok)
		{
			puts("-1");
			continue;
		}
		for(int i=n/2;i;--i)rev(p[2*i+1]),rev(p[2*i]-1),rev(p[2*i]+1),rev(3),rev(2*i+1);
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
	}
	return 0;
}