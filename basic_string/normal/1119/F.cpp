#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=250009;
int he[N],to[N*2],len[N*2],ne[N*2],tot,o,m,d[N],fl[N];
ll f[N],g[N];
vector<pair<int,int>>e[N];
vector<ll>ans;
basic_string<int>po[N],pos;
int vis[N];
void add(int x,int y,int z){
	ne[++tot]=he[x],to[tot]=y,len[tot]=z,he[x]=tot;
	ne[++tot]=he[y],to[tot]=x,len[tot]=z,he[y]=tot;
}
struct T{
	int s,l,r;
	ll w;
}s[N*20];
int u,v,w,rt[N],id;
void upd(int&k,int l,int r){
	if(!k)k=++id;
//	cout<<k<<' '<<l<<' '<<r<<'\n';
	s[k].s+=v,s[k].w+=w;
	if(l==r)return;
	int m=l+r>>1;
	if(u<=m)upd(s[k].l,l,m);
	else upd(s[k].r,m+1,r);
}
ll kth(int k,int t){
//	cout<<k<<' '<<t<<'\n';
	if(t<=0)return 0;
	if(t>s[k].s)return 1e18;
	if(t==s[k].s)return s[k].w;
	if(s[s[k].l].s<t)return kth(s[k].r,t-s[s[k].l].s)+s[s[k].l].w;
	return kth(s[k].l,t);
}
struct DP{
	ll f,g,p;
	bool operator<(DP x){return p<x.p;}
};
const ll inf=1e18;
void dfs(int x){
	vis[x]=o;
	__int128 sf=0,sum,ans;
	int i,j;
	vector<DP>ve;
	for(i=he[x];i;i=ne[i])if(vis[j=to[i]]!=o){
		fl[j]=len[i],dfs(j),ve.push_back({f[j],g[j],g[j]-f[j]}),sf+=f[j];
	}
	sort(ve.begin(),ve.end());
	int l=ve.size();
	sum=sf,ans=1e18;
	for(i=0;i<=l;++i){
		//cout<<o<<' '<<d[x]-o+1-i<<' '<<s[rt[x]].s<<'\n';
		ans=min(ans,sum+kth(rt[x],d[x]-o+1-i));
		if(i<l)sum+=ve[i].p;
	}
	f[x]=ans;
	if(fl[x]){
		sum=sf+fl[x],ans=1e18;
		for(i=0;i<=l;++i){
			ans=min(ans,sum+kth(rt[x],d[x]-o-i));
			if(i<l)sum+=ve[i].p;
		}
	g[x]=ans;
	//if(o==1)cout<<x<<' '<<f[x]<<' '<<g[x]<<'\n';
	}
}
struct LSH{
	int a,i;
	bool operator<(LSH x){return a<x.a;}
}a[N];
int lsh[N];
vector<ll>minimum_closure_costs(int n,vector<int>u,vector<int>v,vector<int>w){
	int i,j;
	ll as;
	for(int z:w)++m,a[m]={z,m-1};
	sort(a+1,a+m+1);
	for(i=1;i<=m;++i)lsh[a[i].i]=i;
//	for(int z:w)a[++m]=z;
//	sort(a+1,a+m+1),m=unique(a+1,a+m+1)-a-1;
	for(i=0;i<n-1;++i){
		++u[i],++v[i];
		e[u[i]].push_back({v[i],i});
		e[v[i]].push_back({u[i],i});
		++d[u[i]],++d[v[i]];
	}
	for(i=1;i<=n;++i)po[d[i]]+=i;
	for(o=n;o;--o){
		as=0;//cout<<o<<'?'<<'\n';
		for(int z:po[o]){
			pos+=z,vis[z]=-1;
			for(auto pa:e[z]){
				j=lsh[pa.second];
				if(vis[pa.first]){
					::u=j,::v=-1,::w=-w[pa.second],upd(rt[pa.first],1,m);
					add(z,pa.first,w[pa.second]);
					//cout<<::u<<' '<<::v<<' '<<::w<<' '<<pa.first<<'!'<<'\n';
				}else{
					::u=j,::v=1,::w=w[pa.second],upd(rt[z],1,m);
				//	cout<<::u<<' '<<::v<<' '<<::w<<' '<<z<<'!'<<'\n';
				}
			}
		}
		for(int z:pos)if(vis[z]!=o)fl[z]=0,dfs(z),as+=f[z];
		ans.push_back(as);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	vector<int>uu,vv,ww;
	vector<ll>aa;
	int n,i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l),--j,--k;
		uu.push_back(j),vv.push_back(k),ww.push_back(l);
	}
	aa=minimum_closure_costs(n,uu,vv,ww);
	for(auto o:aa)printf("%lld ",o);
	return 0;
}