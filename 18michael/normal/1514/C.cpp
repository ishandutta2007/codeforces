#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;LL res=1;
vector<int> ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<n;++i)if(__gcd(i,n)==1)ans.push_back(i),res=(res*i)%n;
	if(n>2 && res==n-1)
	{
		printf("%d\n",ans.size()-1);
		for(int i=0;i<ans.size()-1;++i)printf("%d ",ans[i]);
	}
	else
	{
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	}
	return 0;
}