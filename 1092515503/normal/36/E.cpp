#include<bits/stdc++.h>
using namespace std;
int m,n,X[10010],Y[10010],dsu[20010],lim,id[20010];
bool deg[20010],used[10010];
vector<int>v,u[20010],w[20010];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	dsu[y]=x;
}
#define lst list<int>::iterator
list<int>ls;
void dfs(lst pos,int x){
	while(true){
		while(!w[x].empty()&&used[w[x].back()])w[x].pop_back();
		if(w[x].empty())return;
		int i=w[x].back(),y=X[i]^Y[i]^x;w[x].pop_back(),used[i]=true;
		dfs(ls.insert(pos,i),y);
	}
}
vector<int>s[3];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&X[i],&Y[i]),v.push_back(X[i]),v.push_back(Y[i]);
	if(m==1){puts("-1");return 0;}
	sort(v.begin(),v.end()),v.resize(n=unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1;i<=m;i++)merge(X[i]=lower_bound(v.begin(),v.end(),X[i])-v.begin()+1,Y[i]=lower_bound(v.begin(),v.end(),Y[i])-v.begin()+1),deg[X[i]]^=1,deg[Y[i]]^=1;
//	for(int i=1;i<=m;i++)printf("%d %d\n",X[i],Y[i]);
//	for(int i=1;i<=n;i++)printf("(%d,%d)",find(i),deg[i]);puts("");
	for(int i=1;i<=n;i++)if(dsu[i]==i)id[i]=++lim;
	for(int i=1;i<=n;i++)u[id[find(i)]].push_back(i);
	if(lim>=3){puts("-1");return 0;}
	for(int i=1;i<=m;i++)w[X[i]].push_back(i),w[Y[i]].push_back(i);
	if(lim==1){
		vector<int>sp;
		for(auto i:u[1])if(deg[i])sp.push_back(i);
		if(sp.size()>4){puts("-1");return 0;}
		for(int i=0;i<sp.size();i+=2){
			int eid=m+i/2+1;
			X[eid]=sp[i],Y[eid]=sp[i+1],w[sp[i]].push_back(eid),w[sp[i+1]].push_back(eid);
		}
		dfs(ls.begin(),u[1].back());
//		printf("%d\n",sp.size());
		if(sp.empty()){
			s[1].push_back(ls.front()),ls.pop_front();
			for(auto i:ls)s[2].push_back(i);
		}
		if(sp.size()==2){
			while(ls.front()<=m)ls.push_back(ls.front()),ls.pop_front();
			ls.pop_front();
			s[1].push_back(ls.front()),ls.pop_front();
			while(!ls.empty())s[2].push_back(ls.front()),ls.pop_front();
		}
		if(sp.size()==4){
			while(ls.front()<=m)ls.push_back(ls.front()),ls.pop_front();
			ls.pop_front();
			while(ls.front()<=m)s[1].push_back(ls.front()),ls.pop_front();
			ls.pop_front();
			while(!ls.empty())s[2].push_back(ls.front()),ls.pop_front();
		}
	}
	if(lim==2){
		for(int i=1;i<=2;i++){
			ls.clear();
			vector<int>sp;
			for(auto j:u[i])if(deg[j])sp.push_back(j);
			if(sp.size()>2){puts("-1");return 0;}
			if(!sp.empty())X[m+1]=sp[0],Y[m+1]=sp[1],w[sp[0]].push_back(m+1),w[sp[1]].push_back(m+1),used[m+1]=false;
			dfs(ls.begin(),u[i].back());
			if(!sp.empty()){while(ls.front()<=m)ls.push_back(ls.front()),ls.pop_front();ls.pop_front();}
			while(!ls.empty())s[i].push_back(ls.front()),ls.pop_front();
		}
	}
	for(int i=1;i<=2;i++){
		printf("%d\n",s[i].size());
		for(auto j:s[i])printf("%d ",j);puts("");
	}
	return 0;
}