#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
#define int long long
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=1e6+5,M=1e7+5,INF=1e7;
int n,m,k,a[N],num,c[N],ans;
struct S{int b,id;}s[N];
inline bool cmp(S a,S b){return a.b<b.b;}
struct bit
{
	int t[M];
	inline int lowbit(int x){return x&-x;}
	inline void add(int x,int v){while(x<=INF)t[x]+=v,x+=lowbit(x);}
	inline int query(int x){int tmp=0;while(x)tmp+=t[x],x-=lowbit(x);return tmp;}
}t;
signed main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i])t.add(a[i],1);else num++;
		if(t.query(a[i])+num>(a[i]+1)*k)return puts("-1"),0;
	}
	for(int i=1;i<=m;i++)read(s[i].b),s[i].id=i;
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(t.query(s[i].b)+num>=(s[i].b+1)*k)continue;
		if(s[i].b)t.add(s[i].b,1);else num++;
		c[++ans]=s[i].id;
	}
	write(ans);
	for(int i=1;i<=ans;i++)printf("%d ",c[i]);
	return 0;
}