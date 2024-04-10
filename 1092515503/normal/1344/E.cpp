#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dis[100100];
vector<int>v[100100];
void dfs(int x){for(auto y:v[x])dis[y]+=dis[x],dfs(y);}
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct LCT{int fa,ch[2],tag,tim;}t[100100];
int identify(int x){if(t[t[x].fa].ch[0]==x)return 0;if(t[t[x].fa].ch[1]==x)return 1;return -1;}
void SET(int x,int tim){t[x].tag=t[x].tim=tim;}
void pushdown(int x){
	if(!t[x].tag)return;
	if(lson)SET(lson,t[x].tag);
	if(rson)SET(rson,t[x].tag);
	t[x].tag=0;
}
void pushall(int x){if(identify(x)!=-1)pushall(t[x].fa);pushdown(x);}
void rotate(int x){
	int y=t[x].fa,z=t[y].fa,diry=identify(y),dirx=identify(x),b=t[x].ch[!dirx];
	if(diry!=-1)t[z].ch[diry]=x;t[x].fa=z;
	if(b)t[b].fa=y;t[y].ch[dirx]=b;
	t[x].ch[!dirx]=y,t[y].fa=x;
}
void splay(int x){
	for(pushall(x);identify(x)!=-1;rotate(x))if(identify(t[x].fa)!=-1)rotate(identify(x)==identify(t[x].fa)?t[x].fa:x);
}
map<ll,vector<ll> >mp;
void access(int x,int tim){
	splay(x);
	pushdown(x);
	if(lson)SET(lson,tim);
	int y=x;x=t[x].fa;
	for(;x;x=t[y=x].fa){
		splay(x);
		if(t[x].tim)mp[dis[x]+t[x].tim+1].push_back(dis[x]+tim);
		else mp[1].push_back(dis[x]+tim);
		pushdown(x),t[x].tim=tim;
		if(lson)SET(lson,tim);
		rson=y;
	}
}
int swi;
ll fnt=-1;
priority_queue<ll,vector<ll>,greater<ll> >q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),t[y].fa=x,rson=y,scanf("%lld",&dis[y]),v[x].push_back(y);
	dfs(1);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),access(x,y);
	ll tim=1;
	for(auto x:mp){
		while(tim<x.first&&!q.empty()){
			ll y=q.top();q.pop();
			if(y<tim){fnt=y;while(!q.empty())q.pop();break;}
			tim++,swi++;
		}
		if(fnt!=-1)break;
		tim=x.first;
		for(auto y:x.second)q.push(y);
	}
	while(!q.empty()){
		ll y=q.top();q.pop();
		if(y<tim){fnt=y;while(!q.empty())q.pop();break;}
		tim++,swi++;
	}
	if(fnt==-1){printf("-1 %d\n",swi);return 0;}
	swi=0,tim=1;
	for(auto x:mp){
		while(tim<x.first&&!q.empty()){
			ll y=q.top();q.pop();
			if(y<tim){printf("%lld %d\n",fnt,swi);return 0;}
			tim++,swi++;
		}
		tim=x.first;
		for(auto y:x.second)if(y<fnt)q.push(y);
	}
	while(!q.empty()){
		ll y=q.top();q.pop();
		if(y<tim){printf("%lld %d\n",fnt,swi);return 0;}
		tim++,swi++;
	}
	printf("%lld %d\n",fnt,swi);
	return 0;
}