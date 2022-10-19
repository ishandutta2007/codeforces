#include<bits/stdc++.h>
using namespace std;
#define mpp make_pair
#define pii pair<int,int>
#define mid ((l+r)>>1)
#define lson x<<1
#define rson x<<1|1
typedef long long ll;
const int N=3e5;
int n;
ll res;
map<pii,int>mp;
vector<pii>v[1200100];
void modify(int x,int l,int r,int L,int R,pii p){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){v[x].push_back(p);return;}
	modify(lson,l,mid,L,R,p),modify(rson,mid+1,r,L,R,p);
}
struct DSU{
	int fa;
	pii sz;
	DSU(int a=0,pii b=mpp(0,0)){fa=a,sz=b;}
}dsu[600100];
int find(int x){
	return dsu[x].fa==x?x:find(dsu[x].fa);
}
struct Query{
	int u,v;
	ll r;
	pii su,sv;
	Query(int a=0,pii b=mpp(0,0),int c=0,pii d=mpp(0,0),ll e=0){u=a,su=b,v=c,sv=d,r=e;}
};
stack<Query>s;
bool merge(int x,int y){
//	printf("%d %d\n",x,y);
	x=find(x),y=find(y);
	if(x==y)return false;
	s.push(Query(x,dsu[x].sz,y,dsu[y].sz,res));
	res-=1ll*dsu[x].sz.first*dsu[x].sz.second+1ll*dsu[y].sz.first*dsu[y].sz.second;
	if(dsu[x].sz.first+dsu[x].sz.second>dsu[y].sz.first+dsu[y].sz.second){
		dsu[x].sz.first+=dsu[y].sz.first;
		dsu[x].sz.second+=dsu[y].sz.second;
		dsu[y].fa=x;
		res+=1ll*dsu[x].sz.first*dsu[x].sz.second;
	}else{
		dsu[y].sz.first+=dsu[x].sz.first;
		dsu[y].sz.second+=dsu[x].sz.second;
		dsu[x].fa=y;
		res+=1ll*dsu[y].sz.first*dsu[y].sz.second;
	}
	return true;
}
void Pop(){
	dsu[s.top().u]=DSU(s.top().u,s.top().su);
	dsu[s.top().v]=DSU(s.top().v,s.top().sv);
	res=s.top().r;
	s.pop();
}
void iterate(int x,int l,int r){
	int tot=0;
	for(int i=0;i<v[x].size();i++)tot+=merge(v[x][i].first,v[x][i].second+N);
	if(l==r)printf("%lld ",res);
	else iterate(lson,l,mid),iterate(rson,mid+1,r);
	while(tot--)Pop();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=N;i++)dsu[i]=DSU(i,mpp(1,0));
	for(int i=N+1;i<=2*N;i++)dsu[i]=DSU(i,mpp(0,1));
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(mp.find(mpp(x,y))==mp.end())mp[mpp(x,y)]=i;
		else modify(1,1,n,mp[mpp(x,y)],i-1,mpp(x,y)),mp.erase(mpp(x,y));
	}
	for(auto it:mp)modify(1,1,n,it.second,n,it.first);
	iterate(1,1,n);
	return 0;
}