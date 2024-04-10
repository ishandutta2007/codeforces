#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,trie_t=0,now;
bool ok=1;
char c,c1;
LL res,res1;
typedef pair<LL,int> P;
vector<P> vec;
struct aaa
{
	int col;
	LL num;
	int to[2];
}trie[6600002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x,int d)
{
	int col=0;
	for(int i=0;i<2;++i)
		if(trie[x].to[i])
		{
			dfs(trie[x].to[i],d+1),col|=(trie[trie[x].to[i]].col==3? 0:trie[trie[x].to[i]].col);
			if(!ok)return ;
		}
	if(trie[x].col && (trie[x].col|col)==3)
	{
		ok=0;
		return ;
	}
	if(col==3)
	{
		if(trie[trie[x].to[0]].col==1)vec.push_back(P(trie[trie[x].to[0]].num,d+1));
		else vec.push_back(P(trie[trie[x].to[1]].num,d+1));
		trie[x].col|=2;
	}
	else trie[x].col|=col;
}
int main()
{
	read(n);
	for(int i=1,x;i<=n;++i)
	{
		res=now=0;
		do c1=getchar();while(c1!='+' && c1!='-');
		while(c<'0' || c>'9')c=getchar();
		for(res1=0;c>='0' && c<='9';)res1=(res1<<3)+(res1<<1)+(c^48),c=getchar();res=((res<<8)|res1);
		while(c<'0' || c>'9')c=getchar();
		for(res1=0;c>='0' && c<='9';)res1=(res1<<3)+(res1<<1)+(c^48),c=getchar();res=((res<<8)|res1);
		while(c<'0' || c>'9')c=getchar();
		for(res1=0;c>='0' && c<='9';)res1=(res1<<3)+(res1<<1)+(c^48),c=getchar();res=((res<<8)|res1);
		while(c<'0' || c>'9')c=getchar();
		for(res1=0;c>='0' && c<='9';)res1=(res1<<3)+(res1<<1)+(c^48),c=getchar();res=((res<<8)|res1);
		if(c!='\n')read(x);else x=32;
		for(int j=31,k;j>=32-x;--j)
		{
			k=((res>>j)&1);
			if(!trie[now].to[k])trie[trie[now].to[k]=(++trie_t)].num=(trie[now].num|(res&(1LL<<j)));
			now=trie[now].to[k];
		}
		trie[now].col|=(c1=='-'? 1:2);
	}
	dfs(0,0);
	if(!ok)puts("-1");
	else
	{
		if(trie[0].col==1)vec.push_back(P(0,0));
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%lld.%lld.%lld.%lld/%d\n",(vec[i].first>>24),((vec[i].first>>16)&255),((vec[i].first>>8)&255),(vec[i].first&255),vec[i].second);
	}
	return 0;
}