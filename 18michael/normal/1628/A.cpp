#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,t,t1,now,la,Test_num;
int a[200002],cnt[200002],ans[200002];
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
		read(n),memset(cnt,0,sizeof(cnt)),t=0,now=1,vec.clear();
		for(int i=1;i<=n;++i)read(a[i]);
		for(int i=n;i;--i)
		{
			++cnt[a[i]];
			while(cnt[t])++t;
			ans[i]=t;
		}
		memset(cnt,0,sizeof(cnt)),t=0,t1=ans[now],la=1;
		for(;now<=n;++now)
		{
			++cnt[a[now]];
			while(cnt[t])++t;
			if(t==t1)
			{
				vec.push_back(t),t=0,t1=ans[now+1];
				for(int i=la;i<=now;++i)cnt[a[i]]=0;
				la=now+1;
			}
		}
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
	}
	return 0;
}