#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,sq,Test_num;
LL ans;
int a[1000002];
vector<int> vec;
vector<int> b[552];
typedef pair<int,int> P;
map<P,bool> mp;
unordered_map<int,int> cnt,u;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return x>y? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		mp.clear(),cnt.clear(),u.clear(),vec.clear(),read(n),read(m),sq=sqrt(n),ans=0;
		for(int i=1;i<=sq;++i)b[i].clear();
		for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]];
		for(int i=1,x,y;i<=m;++i)read(x),read(y),mp[P(x,y)]=mp[P(y,x)]=1;
		for(int i=1;i<=n;++i)
			if(!u.count(a[i]))
			{
				u[a[i]]=1;
				if(cnt[a[i]]<=sq)b[cnt[a[i]]].push_back(a[i]);
				else vec.push_back(a[i]);
			}
		for(int i=1;i<=sq;++i)sort(b[i].begin(),b[i].end(),cmp);
		for(int i=0;i<vec.size();++i)
		{
			for(int j=i+1;j<vec.size();++j)
				if(!mp.count(P(vec[i],vec[j])))
					ans=max(ans,1LL*(cnt[vec[i]]+cnt[vec[j]])*(vec[i]+vec[j]));
			for(int j=1;j<=sq;++j)
				for(int k=0;k<b[j].size();++k)
					if(!mp.count(P(vec[i],b[j][k])))
					{
						ans=max(ans,1LL*(cnt[vec[i]]+j)*(vec[i]+b[j][k]));
						break;
					}
		}
		for(int i=1;i<=sq;++i)
			for(int j=i;j<=sq;++j)
			{
				for(int k=0;k<b[i].size();++k)
					for(int l=0;l<b[j].size();++l)
						if(b[i][k]!=b[j][l] && !mp.count(P(b[i][k],b[j][l])))
						{
							ans=max(ans,1LL*(i+j)*(b[i][k]+b[j][l]));
							if(!l)goto QAQ;
							break;
						}
				QAQ:;
			}
		printf("%lld\n",ans);
	}
	return 0;
}