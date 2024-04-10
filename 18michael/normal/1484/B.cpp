#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
int a[100002];
set<int> s;
set<int>::iterator it;
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
		read(n),s.clear();
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=n;i>1;--i)s.insert(a[i]-a[i-1]);
		if(s.size()>2)puts("-1");
		else if(s.size()<=1)puts("0");
		else
		{
			it=s.begin(),++it;
			if(1LL*(*s.begin())*(*it)>=0)puts("-1");
			else
			{
				for(int i=1;i<=n;++i)if(a[i]>=(*it-*s.begin())){puts("-1");goto QAQ;}
				printf("%d %d\n",*it-*s.begin(),*it);QAQ:;
			}
		}
	}
	return 0;
}