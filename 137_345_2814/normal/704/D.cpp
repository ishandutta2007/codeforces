#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 105000
int n,q,r,w,s,t,ss,tt,a,b,c,v[N][2],su[N][2],ct1,ct2,head[N*2],cnt=1,cur[N*2],dis[N*2],as1[N];
map<int,int> tp1,tp2;
struct edge{int t,next,v,id;}ed[N*20];
void adde(int f,int t,int v,int id=-1){ed[++cnt]=(edge){t,head[f],v,id};head[f]=cnt;ed[++cnt]=(edge){f,head[t],0,id};head[t]=cnt;}
bool bfs(int s,int t)
{
	queue<int> tp;tp.push(s);memset(dis,-1,sizeof(dis));dis[s]=0;memcpy(cur,head,sizeof(cur));
	while(!tp.empty())
	{
		int r=tp.front();tp.pop();
		for(int i=head[r];i;i=ed[i].next)
		if(ed[i].v&&dis[ed[i].t]==-1)
		{
			dis[ed[i].t]=dis[r]+1;tp.push(ed[i].t);
			if(ed[i].t==t)return 1;
		}
	}
	return 0;
}
int dfs(int u,int t,int f)
{
	if(!f||u==t)return f;
	int as=0,tp;
	for(int &i=cur[u];i;i=ed[i].next)
	if(ed[i].v&&dis[ed[i].t]==dis[u]+1&&(tp=dfs(ed[i].t,t,min(ed[i].v,f))))
	{
		ed[i].v-=tp;ed[i^1].v+=tp;
		f-=tp,as+=tp;
		if(!f)return as;
	}
	return as;
}
int main()
{
	scanf("%d%d%d%d",&n,&q,&r,&w);
	s=n*2+1,t=n*2+2,ss=s+2,tt=t+2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(!tp1[a])tp1[a]=++ct1,v[ct1][0]=1e9;
		if(!tp2[b])tp2[b]=++ct2,v[ct2][1]=1e9;
		su[tp1[a]][0]++;su[tp2[b]][1]++;
		adde(tp1[a],tp2[b]+n,1,i);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)v[tp1[b]][0]=min(v[tp1[b]][0],c);
		else v[tp2[b]][1]=min(v[tp2[b]][1],c);
	}
	int suf=0,su2=0,as=0;
	adde(t,s,1e9);
	for(int i=1;i<=ct1;i++)
	{
		int vl=su[i][0],c1=v[i][0];
		if(c1>vl){adde(s,i,vl);continue;}
		if((vl&1)&&!c1){printf("-1\n");return 0;}
		int lb=(vl-c1+1)/2,rb=(vl+c1)/2;
		adde(s,i,rb-lb);adde(ss,i,lb);adde(s,tt,lb);suf+=lb;as+=lb;
	}
	for(int i=1;i<=ct2;i++)
	{
		int vl=su[i][1],c1=v[i][1];
		if(c1>vl){adde(i+n,t,vl);continue;}
		if((vl&1)&&!c1){printf("-1\n");return 0;}
		int lb=(vl-c1+1)/2,rb=(vl+c1)/2;
		adde(i+n,t,rb-lb);adde(i+n,tt,lb);adde(ss,t,lb);suf+=lb;
	}
	while(bfs(ss,tt))
	su2+=dfs(ss,tt,1e9);
	if(su2<suf){printf("-1\n");return 0;}
	for(int i=head[ss];i;i=ed[i].next)ed[i].v=0;
	for(int i=head[tt];i;i=ed[i].next)ed[i].v=0;
	for(int i=head[s];i;i=ed[i].next)if(ed[i].t==t||ed[i].t==tt)ed[i].v=0;else as+=ed[i^1].v;
	for(int i=head[t];i;i=ed[i].next)if(ed[i].t==s||ed[i].t==ss)ed[i].v=0;
	while(bfs(s,t))as+=dfs(s,t,1e9);
	for(int i=1;i<=ct1;i++)
	for(int j=head[i];j;j=ed[j].next)
	if(ed[j].id!=-1)as1[ed[j].id]=!ed[j].v;
	if(r>=w)
	{
		printf("%lld\n",1ll*w*as+1ll*r*(n-as));
		for(int i=1;i<=n;i++)printf("%c",as1[i]?'b':'r');
	}
	else
	{
		printf("%lld\n",1ll*r*as+1ll*w*(n-as));
		for(int i=1;i<=n;i++)printf("%c",as1[i]?'r':'b');
	}
}