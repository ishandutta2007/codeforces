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
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=1e6+5,INF=1e8;
struct E{int to,next;}edge[N<<1];
int n,head[N],tot,fa[N],tt[N],in[N],out[N],Time,sum[N],total,cnt,ans1,ans2,rt,num[N],have[N];
void dfs(int u,int f)
{
	in[u]=++Time;sum[u]=tt[u];
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=f)dfs(edge[i].to,u),sum[u]+=sum[edge[i].to];
	out[u]=Time;
}
int main()
{
	memset(head,-1,sizeof(head));
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(fa[i]),read(tt[i]);total+=tt[i];
		if(fa[i])
		{
			edge[++tot]=(E){fa[i],head[i]};head[i]=tot;
			edge[++tot]=(E){i,head[fa[i]]};head[fa[i]]=tot;
		}
		else rt=i;
	}
	if(abs(total)%3)return puts("-1"),0;
	total/=3;
	dfs(rt,0);
	for(int i=1;i<=n;i++)if(i!=rt&&sum[i]==total)have[in[i]]=1;
	for(int i=n-1;i>=1;i--)have[i]|=have[i+1];
	for(int i=1;i<=n;i++)if(i!=rt&&sum[i]==total&&have[out[i]+1])ans1=i;
	if(ans1)for(int i=1;i<=n;i++)if(in[i]>out[ans1]&&sum[i]==total)return printf("%d %d\n",ans1,i),0;
	for(int i=1;i<=n;i++)if(i!=rt&&sum[i]==total)num[in[i]]=1;
	for(int i=1;i<=n;i++)num[i]+=num[i-1];
	for(int i=1;i<=n;i++)if(i!=rt&&sum[i]==2*total&&num[out[i]]-num[in[i]]>0)ans1=i;
	if(ans1)for(int i=1;i<=n;i++)if(in[i]>in[ans1]&&in[i]<=out[ans1]&&sum[i]==total)return printf("%d %d\n",ans1,i),0;
	puts("-1");
	return 0;
}