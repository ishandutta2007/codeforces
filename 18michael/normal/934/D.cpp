#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL p;int k,res=1;
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
	read(p),read(k);
	while(p)
	{
		if(res&1)ans.push_back(p%k),p/=k;
		else ans.push_back((k-(p%k))%k),p+=(k-(p%k))%k,p/=k;
		res^=1;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	return 0;
}