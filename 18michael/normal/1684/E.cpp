#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,j,k,k1,mex,dif,Test_num;
int a[1000002];
set<int> s;
map<int,int> mp;
map<int,int>::iterator it;
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
		read(n),read(k),k1=k,mex=dif=0,s.clear(),mp.clear(),vec.clear();
		for(int i=1;i<=n;++i)read(a[i]);
		sort(a+1,a+n+1);
		for(mex=0,j=1;mex<=n;++mex)
		{
			while(j<=n && a[j]<mex)++j;
			if(j>n || a[j]>mex)
			{
				if(!k1)break;
				--k1;
			}
		}
		//printf("%d\n",mex);
		dif=mex;
		//printf("%d-%d=\n",dif,mex);
		for(int i=1;i<=n;++i)
			if(a[i]>=mex)
			{
				if(!mp.count(a[i]))++dif;
				++mp[a[i]];
			}
		//printf("%d-%d=\n",dif,mex);
		for(it=mp.begin();it!=mp.end();++it)vec.push_back((*it).second);
		sort(vec.begin(),vec.end()),k1=0;
		for(int i=0;i<vec.size();++i)
		{
			if((k1+=vec[i])<=k)--dif;
			else break;
		}
		//printf("%d-%d=\n",dif,mex);
		printf("%d\n",dif-mex);
	}
	return 0;
}