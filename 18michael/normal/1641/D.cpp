#include<bits/stdc++.h>
#define LL long long
#define inf 0x7fffffff
using namespace std;
int n,m,ans=inf,trie_t=0,Mx,res;
int id[100002],w[32];
int a[100002][7];
int to[100002][32];
struct aaa
{
	int cnt;
	unordered_map<int,int> mp;
}trie[3200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int newnode()
{
	trie[++trie_t].cnt=0,trie[trie_t].mp.clear();
	return trie_t;
}
inline bool cmp(int x,int y)
{
	return a[x][m]<a[y][m]? 1:0;
}
inline void dfs(int x,int y,int z,int s)
{
	if(y==m)return (void)(++trie[to[x][s]=z].cnt);
	dfs(x,y+1,z,s);
	if(!trie[z].mp.count(a[x][y]))trie[z].mp[a[x][y]]=newnode();
	dfs(x,y+1,trie[z].mp[a[x][y]],s|(1<<y));
}
int main()
{
	read(n),read(m),Mx=(1<<m),w[0]=1;
	for(int i=1;i<Mx;++i)w[i]=w[i>>1]*(i&1? -1:1);
	for(int i=1;i<=n;++i)
	{
		id[i]=i;
		for(int j=0;j<=m;++j)read(a[i][j]);
		sort(a[i],a[i]+m),dfs(i,0,0,0);
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1,j=n+1;i<j;++i)
	{
		for(;;)
		{
			res=0;
			for(int k=0;k<Mx;++k)res+=w[k]*trie[to[id[i]][k]].cnt;
			if(!res)break;
			--j;
			for(int k=0;k<Mx;++k)--trie[to[id[j]][k]].cnt;
		}
		if(j<=n)ans=min(ans,a[id[i]][m]+a[id[j]][m]);
	}
	return 0&printf("%d",ans==inf? -1:ans);
}