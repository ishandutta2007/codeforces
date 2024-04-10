#include<bits/stdc++.h>
using namespace std;
int n,m,dfn[10100],low[10100],tot;
vector<int>v[10100];
map<pair<int,int>,int>mp;
vector<vector<int> >circ;
stack<int>s;
bool sub[101000];//colours that have substitudes.
void Tarjan(int x){
	dfn[x]=low[x]=++tot,s.push(x);
	for(auto y:v[x]){
		if(!dfn[y]){
			Tarjan(y),low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				vector<int>u;
				while(s.top()!=y)u.push_back(s.top()),s.pop();u.push_back(s.top()),s.pop();
				u.push_back(x);
				if(u.size()<3)continue;//not a circle.
				vector<int>ed;
				for(int i=0;i<u.size();i++){
					auto tmp=make_pair(min(u[i],u[(i+1)%u.size()]),max(u[i],u[(i+1)%u.size()]));
					ed.push_back(mp[tmp]),mp.erase(tmp);
				}
				int tmp=ed.size();
				sort(ed.begin(),ed.end()),ed.resize(unique(ed.begin(),ed.end())-ed.begin());
				if(ed.size()!=tmp)for(auto i:ed)sub[i]=true;
				else circ.push_back(ed);
			}
		}else low[x]=min(low[x],dfn[y]);
	}
}
int dsu[20100],res;
bool sp[20100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool merge(int x,int y){x=find(x),y=find(y);if(x==y)return true;dsu[y]=x;return false;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),v[x].push_back(y),v[y].push_back(x);
		if(x>y)swap(x,y);mp[make_pair(x,y)]=z;
	}
	Tarjan(1);
	for(auto i:mp)sub[i.second]=true;
//	for(int i=1;i<=m;i++)printf("%d ",sub[i]);puts("");puts("");
//	for(auto i:circ){for(auto j:i)printf("%d ",j);puts("");}
	int N=circ.size();
	for(int i=1;i<=m+N;i++)dsu[i]=i;
	for(int i=0;i<N;i++)for(auto j:circ[i])if(merge(m+i+1,j))sub[j]=true;
	for(int i=1;i<=m;i++)if(sub[i])sp[find(i)]=true;else if(sp[find(i)])sub[i]=true;
	res=m;
	for(int i=1;i<=m+N;i++)if(dsu[i]==i&&!sp[i])res--;
	printf("%d\n",res);
	return 0;
}