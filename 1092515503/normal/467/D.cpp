#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n,q,col[500100],c,in[500100];
string s[100100];
unordered_map<string,int>mp;
pair<string,string>p[100100];
pair<int,int>val[500100],mn[500100];
pair<ll,ll>res; 
void func(string &x){for(int i=0;i<x.size();i++)if(x[i]<='Z')x[i]=x[i]-'A'+'a';}
int R(string x){int rr=0;for(auto i:x)rr+=(i=='r');return rr;}
namespace SCC{
	int tot,dfn[500100],low[500100],head[500100],cnt;
	struct node{
		int to,next;
	}edge[1001000];
	void ae(int u,int v){
	//	cout<<u<<" "<<v<<endl;
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	}
	stack<int>stk;
	void Tarjan(int x){
		dfn[x]=low[x]=++tot,stk.push(x);
		for(int i=head[x];i!=-1;i=edge[i].next){
			if(!dfn[edge[i].to])Tarjan(edge[i].to),low[x]=min(low[x],low[edge[i].to]);
			if(!col[edge[i].to])low[x]=min(low[x],dfn[edge[i].to]);
		}
		if(low[x]<dfn[x])return;
		c++;
		while(stk.top()!=x)col[stk.top()]=c,mn[c]=min(mn[c],val[stk.top()]),stk.pop();
		col[stk.top()]=c,mn[c]=min(mn[c],val[stk.top()]),stk.pop();
	}	
}
namespace TOPO{
	int head[500100],in[500100],cnt;
	struct node{
		int to,next;
	}edge[1001000];
	void ae(int u,int v){
	//	cout<<u<<" "<<v<<endl;
		in[v]++;
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	}
	queue<int>q;
	void topo(){
		for(int i=1;i<=c;i++)if(!in[i])q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x];i!=-1;i=edge[i].next){
				mn[edge[i].to]=min(mn[edge[i].to],mn[x]),in[edge[i].to]--;
				if(!in[edge[i].to])q.push(edge[i].to);
			}
		}
	}
}
void operator +=(pair<ll,ll> &x,const pair<int,int> &y){
	x.first+=y.first,x.second+=y.second;
}
int main(){
	cin>>m,memset(SCC::head,-1,sizeof(SCC::head)),memset(TOPO::head,-1,sizeof(TOPO::head)),memset(mn,0x3f3f3f3f,sizeof(mn));
	for(int i=1;i<=m;i++)cin>>s[i],func(s[i]),mp[s[i]]=true;
	cin>>q;
	for(int i=1;i<=q;i++)cin>>p[i].first>>p[i].second,func(p[i].first),func(p[i].second),mp[p[i].first]=true,mp[p[i].second]=true;
	for(unordered_map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		++n;
		val[n]=make_pair(R(it->first),(it->first).size());
		it->second=n;
	}
	for(int i=1;i<=q;i++)SCC::ae(mp[p[i].first],mp[p[i].second]);
	for(int i=1;i<=n;i++)if(!SCC::dfn[i])SCC::Tarjan(i);
	for(int i=1;i<=n;i++)for(int j=SCC::head[i];j!=-1;j=SCC::edge[j].next)if(col[i]!=col[SCC::edge[j].to])TOPO::ae(col[SCC::edge[j].to],col[i]);
	TOPO::topo();
	for(int i=1;i<=m;i++)res+=mn[col[mp[s[i]]]];
	cout<<res.first<<" "<<res.second<<endl;
	return 0;
}