#include<bits/stdc++.h>
using namespace std;
const int lim=1<<6;
int n,mask[100100],m,tot[lim],cmp[6],enm[80][80];
char s[100100],ss[6];
namespace MaxFlow{
	const int N=10000,M=200000;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{
		int to,next,val;
	}edge[M];
	void ae(int u,int v,int w){
		enm[u][v]=cnt,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		enm[v][u]=cnt,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline int dfs(int x,int flow){
		if(x==T){
			res+=flow;
			reach=true;
			return flow;
		}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){
				edge[i].val-=ff;
				edge[i^1].val+=ff;
				used+=ff;
				if(used==flow)break;
			}
		}
		return used;
	}
	inline void Dinic(){
		while(bfs()){
			reach=true;
			while(reach)reach=false,dfs(S,0x3f3f3f3f);
		}
	}
}
using namespace MaxFlow;
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
bool fillin(int msk,int cha){
	if(!(msk&(1<<cha)))return false;
	int p1=cha,p2=msk+6;
	int e1=enm[S][p1],e2=enm[p2][T];
	if(!edge[e1^1].val||!edge[e2^1].val)return false;
	edge[e1^1].val--;
	edge[e1].val++;
	vector<int>afe;
	afe.push_back(e1);
	for(int i=head[p1],x;i!=-1;i=edge[i].next){
		if((i&1)||!edge[i^1].val)continue;
		afe.push_back(i);
		edge[i^1].val--;
		edge[i].val++;
		x=edge[i].to;
		for(int j=head[x];j!=-1;j=edge[j].next){
			if(j&1)continue;
			afe.push_back(j);
			edge[j^1].val--;
			edge[j].val++;
			break;
		}
		break;
	}
	if(edge[e2].val){edge[e2].val--,edge[e1].val--;return true;}
	afe.push_back(e2);
	edge[e2^1].val--;
	edge[e2].val++;
	for(int i=head[p2],x;i!=-1;i=edge[i].next){
		if(!(i&1)||!edge[i].val)continue;
		afe.push_back(i^1);
		edge[i^1].val++;
		edge[i].val--;
		x=edge[i].to;
		for(int j=head[x];j!=-1;j=edge[j].next){
			if(!(j&1))continue;
			afe.push_back(j^1);
			edge[j^1].val++;
			edge[j].val--;
			break;
		}
		break;
	}
	edge[e1].val--;
	edge[e2].val--;
	res=0;
	Dinic();
	if(res)return true;
	edge[e1].val++;
	edge[e2].val++;
	for(int i=0;i<afe.size();i++)edge[afe[i]].val--,edge[afe[i]^1].val++;
	return false;
} 
int main(){
	scanf("%s",s+1),n=strlen(s+1),S=6+lim,T=6+lim+1;
	for(register int i=1;i<=n;i++)cmp[s[i]-'a']++;
	read(m);
	for(register int i=1,x,y;i<=m;i++){
		read(x),scanf("%s",ss),y=strlen(ss);
		for(register int j=0;j<y;j++)mask[x]|=1<<(ss[j]-'a'); 
	}
	for(register int i=1;i<=n;i++)if(!mask[i])mask[i]=lim-1;
	for(register int i=1;i<=n;i++)tot[mask[i]]++;
	memset(head,-1,sizeof(head));
	for(register int i=0;i<6;i++)ae(S,i,cmp[i]);
	for(register int i=0;i<lim;i++)for(register int j=0;j<6;j++)if(i&(1<<j))ae(j,i+6,0x3f3f3f3f);
	for(register int i=0;i<lim;i++)ae(i+6,T,tot[i]);
	Dinic();
	if(res!=n){puts("Impossible");return 0;}
	for(register int i=1;i<=n;i++)for(register int j=0;j<6;j++)if(fillin(mask[i],j)){putchar('a'+j);break;}
	return 0;
}