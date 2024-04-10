#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,X,Test_num,ans;
int a[1000002];
unordered_map<int,int> mp;
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
		read(n),read(X),mp.clear(),ans=n;
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
		{
			if(!(a[i]%X) && mp.count(a[i]/X) && mp[a[i]/X]>0)--mp[a[i]/X],ans-=2;
			else ++mp[a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}