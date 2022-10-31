#include<bits/stdc++.h>
#define N 200100
#define all(x) begin(x),end(x)
using namespace std;
struct seg{
	int st,ed,y;
	bool operator<(seg rhs)const{return y<rhs.y;}
}h[N];
int f[N],gp[N];
long long emv[N],len[N];
const int inf=1<<30;
int mx[N*4],mn[N*4],sz[N*4],tag[N*4];
int find(int x){
	if(gp[x]==x) return x;
	return gp[x]=find(gp[x]);
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		emv[fy]+=emv[fx];
		len[fy]+=len[fx];
		gp[fx]=fy;
	}
}
void push(int u){
	int lc=u*2,rc=u*2+1;
	if(tag[u]>=0){
		if(sz[lc]) tag[lc]=mx[lc]=mn[lc]=tag[u];
		if(sz[rc]) tag[rc]=mx[rc]=mn[rc]=tag[u];
	}
	tag[u]=-1;
}
void pull(int u){
	int lc=u*2,rc=u*2+1;
	sz[u]=sz[lc]+sz[rc];
	mx[u]=max(mx[lc],mx[rc]);
	mn[u]=min(mn[lc],mn[rc]);
}
int qry(int u,int l,int r,int ll,int rr,int id){
	if(!sz[u] || r<=ll || l>=rr) return 0;
	if(ll<=l&&rr>=r&&mx[u]==mn[u]){
		//id will be root
		uni(mx[u],id);
		assert(gp[id]==id);
		mx[u]=mn[u]=tag[u]=id;
		return sz[u];
	}
	int m=(l+r)/2;
	push(u);
	int res=qry(u*2,l,m,ll,rr,id)+qry(u*2+1,m,r,ll,rr,id);
	pull(u);
	return res;
}
int upd(int u,int l,int r,int x, int v, int &cnt){
	int res;
	if(l+1==r){
		sz[u]+=v;
		if(v>0) res=tag[u]=mx[u]=mn[u]=cnt++;
		else res=mx[u],tag[u]=-1,mx[u]=-inf,mn[u]=inf;
		return res;
	}
	int m=(l+r)/2;
	push(u);
	if(x<m) res=upd(u*2,l,m,x,v,cnt);
	else res=upd(u*2+1,m,r,x,v,cnt);
	pull(u);
	return res;
}
int main(){
	int x1,x2,y1,y2;
	int n,hc=0,vc=0,cnt=0;
	scanf("%d",&n);
	vector<pair<int,pair<int,int>>> v;
	vector<int> num;
	for(int i=0;i<n;i++){
		gp[i]=i;
		emv[i]=-1;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			num.push_back(x1);
			vc+=2;
			v.push_back(make_pair(y1,make_pair(x1,1)));
			v.push_back(make_pair(y2+1,make_pair(x1,-1)));
		}
		else{
			h[hc].st=x1;
			h[hc].ed=x2;
			h[hc].y=y1;
			hc++;
		}
	}
	for(int i=0;i<n*2;i++) mx[i]=-inf,mn[i]=inf,sz[i]=0,tag[i]=-1;
	sort(all(v));
	sort(h,h+hc);
	sort(all(num));
	num.resize(unique(all(num))-begin(num));
	int vi=0;
	set<int> in,cp_in;
	h[hc].y=1<<30;
	for(int i=0;i<=hc;i++){
		while(vi<vc && v[vi].first<=h[i].y){
			int pos=lower_bound(all(num),v[vi].second.first)-begin(num);
			int add=v[vi].second.second;
			int id=upd(1,0,num.size(),pos,add,cnt);
			if(add>0) len[find(id)]-=v[vi].first;
			else len[find(id)]+=v[vi].first-1;
			vi++;
		}
		if(i==hc) break;
		int l=lower_bound(all(num),h[i].st)-begin(num),r=upper_bound(all(num),h[i].ed)-begin(num);
		int inter=qry(1,0,num.size(),l,r,cnt);
		len[find(cnt)]+=h[i].ed-h[i].st;
		emv[find(cnt)]+=inter;
		cnt++;
	}
	assert(cnt==n);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(gp[i]==i){
			ans=max(ans,len[i]-(emv[i]+1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}