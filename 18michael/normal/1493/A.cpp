#include<bits/stdc++.h>
using namespace std;
int Test_num,n,k;
vector<int> v;
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
		read(n),read(k),v.clear();
		for(int i=k+1;i<=n;++i)v.push_back(i);
		for(int i=(k+1)/2;i<k;++i)v.push_back(i);
		printf("%d\n",v.size());
		for(int i=0;i<v.size();++i)printf("%d ",v[i]);
		puts("");
	}
	return 0;
}