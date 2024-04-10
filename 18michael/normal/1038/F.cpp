#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define mod 10000103
using namespace std;
int n,l,Mx,len;
LL ans=0,tmp;
char s[42];
LL pre[42];
int to[42][2];
LL dp[82][42];
struct HashTable
{
	vector<LL> vec[mod];
	inline bool find(LL x)
	{
		int y=x%mod;
		for(int i=0;i<vec[y].size();++i)if(vec[y][i]==x)return 1;
		return 0;
	}
	inline void ins(LL x)
	{
		vec[x%mod].push_back(x);
	}
}mp;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void solve1()
{
	for(int i=2;i<=l;++i)for(int j=0;j<2;to[i][j]+=(!(s[to[i][j]+1]^j)),++j)for(to[i][j]=to[i-1][s[i-1]];to[i][j] && (s[to[i][j]+1]^j);to[i][j]=to[to[i][j]][s[to[i][j]]]);
	for(int i=1;i<=l;++i)to[i][s[i]]=i;
	to[l+1][0]=to[l+1][1]=l,Mx=(1<<l);
	for(int i=0;i<Mx;++i)
	{
		dp[0][0]=1;
		for(int j=0;j<n+l;++j)
		{
			for(int k=0;k<=l;++k)dp[j+1][k]=0;
			for(int k=0;k<=l;++k)for(int o=0;o<2;++o)if((j>=l && j<n) || o==((i>>(j%n))&1))dp[j+1][to[k+1][o]]+=dp[j][k];
		}
		ans+=dp[n+l][l];
	}
}
inline void dfs(int x)
{
	if(x>n)
	{
		len=n;
		for(int i=1;i<=n;++i)
		{
			if(mp.find(tmp=((pre[n]&((1LL<<(n-i+1))-1))<<(i-1))+pre[i-1]))
			{
				len=0;
				break;
			}
			if(i>1 && tmp==pre[n])
			{
				len=i-1;
				break;
			}
		}
		if(len)ans+=len,mp.ins(pre[n]);
		return ;
	}
	s[x]=0,pre[x]=(pre[x-1]<<1),dfs(x+1),s[x]=1,++pre[x],dfs(x+1);
}
inline void solve2()
{
	for(int i=1;i<=l;++i)pre[i]=(pre[i-1]<<1)+s[i];
	dfs(l+1);
}
int main()
{
	read(n),scanf("%s",s+1),l=strlen(s+1);
	for(int i=1;i<=l;++i)s[i]^=48;
	if(l<=19)solve1();
	else solve2();
	return 0&printf("%lld",ans);
}