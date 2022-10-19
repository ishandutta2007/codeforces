#include<bits/stdc++.h>
using namespace std;
int n,m,num[101],head[103],cnt,S,T,dep[103],cur[103],res;
struct node{
	int to,next,val;
}edge[100100];
map<int,bool>mp;
void sieve(int ip){
	int tmp=ip;
	for(int i=2;i*i<=tmp;i++)while(!(ip%i))mp[i]=true,ip/=i;
	if(ip!=1)mp[ip]=true;
}
int Sieve(int ip,int val){
	int res=0;
	while(!(ip%val))ip/=val,res++;
	return res;
}
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
}
pair<int,int>p[101];
queue<int>q;
bool bfs(){
	memset(dep,0,sizeof(dep)),dep[S]=1,q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
	}
	return dep[T]>0;
}
bool reach;
int dfs(int x,int flow){
	if(x==T||!flow){res+=flow,reach=true;return flow;}
	int used=0;
	for(int &i=cur[x];i!=-1;i=edge[i].next){
		if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
		int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
		if(ff){
			edge[i].val-=ff;
			edge[i^1].val+=ff;
			used+=ff;
			if(used==flow)break;
		}
	}
	return used;
}
int main(){
	scanf("%d%d",&n,&m),S=n+1,T=n+2;
	for(int i=1;i<=n;i++)scanf("%d",&num[i]),sieve(num[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
		if(!(p[i].first&1))swap(p[i].first,p[i].second);
	}
	for(map<int,bool>::iterator it=mp.begin();it!=mp.end();it++){
		memset(head,-1,sizeof(head)),cnt=0;
		for(int i=1,tmp;i<=n;i+=2){
			tmp=Sieve(num[i],it->first);
			if(tmp)ae(S,i,tmp);
		}
		for(int i=2,tmp;i<=n;i+=2){
			tmp=Sieve(num[i],it->first);
			if(tmp)ae(i,T,tmp);
		}
		for(int i=1;i<=m;i++)ae(p[i].first,p[i].second,0x3f3f3f3f);
		while(bfs()){
			reach=true;
			while(reach)reach=false,dfs(S,0x3f3f3f3f);
		}
	}
	printf("%d\n",res);
	return 0;
}