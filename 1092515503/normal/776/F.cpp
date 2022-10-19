/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,stk[100100],tp,fa[100100],ord[100100],RT,SZ,msz[100100],sz[100100],res[100100];
pair<int,int>p[100100];
vector<int>v[100100],u[100100];
vector<int>w;
bool vis[100100];
void getroot(int x,int fa){
	msz[x]=0,sz[x]=1;
	for(auto y:v[x])if(y!=fa&&!vis[y])getroot(y,x),msz[x]=max(msz[x],sz[y]),sz[x]+=sz[y];
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
void getsz(int x,int fa){sz[x]=1;for(auto y:v[x])if(y!=fa&&!vis[y])getsz(y,x),sz[x]+=sz[y];}
void solve(int x,int dep){
	getsz(x,0),vis[x]=true,res[x]=dep;
	for(auto y:v[x])if(!vis[y])RT=0,SZ=sz[y],getroot(y,0),solve(RT,dep+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		p[i]=make_pair(x,y);
	}
	p[++m]=make_pair(1,n);
	sort(p+1,p+m+1,[](const pair<int,int>&u,const pair<int,int>&v){return u.first==v.first?u.second<v.second:u.first>v.first;});
	for(int i=1;i<=m;i++){
		w.push_back(p[i].first);
		while(tp&&p[stk[tp]].second<=p[i].second)
			w.push_back(p[stk[tp]].first),w.push_back(p[stk[tp]].second),v[i].push_back(stk[tp]),v[stk[tp]].push_back(i),tp--;
		w.push_back(p[i].second);
		for(int j=0;j+1<w.size();j+=2)for(int k=w[j];k<=w[j+1];k++)if(u[i].empty()||u[i].back()!=k)u[i].push_back(k);
		w.clear();
		stk[++tp]=i;
	}
	for(int i=1;i<=m;i++)ord[i]=i;
	sort(ord+1,ord+m+1,[](int x,int y){
		for(auto i=u[x].rbegin(),j=u[y].rbegin();;i++,j++)if(*i!=*j)return *i<*j;
	});
	SZ=m,msz[RT=0]=m,getroot(1,0),solve(RT,1);
	for(int i=1;i<=m;i++)printf("%d ",res[ord[i]]);puts("");
	return 0;
}