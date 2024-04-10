#include<bits/stdc++.h>
using namespace std;
enum{N=100009,M=N*7};
int n,a[N],v[N],id;
long long ans[N],t[N];
set<int>s[N];
struct P{int x,y,i;}p[M],q[M];
void add(int x,int y){for(;x<=n;t[x]+=y,x+=x&-x)if(v[x]<id)v[x]=id,t[x]=0;}
long long sum(int x){long long r=0;for(;x;x-=x&-x)if(v[x]==id)r+=t[x];return r;}
void cdq(int l,int r){
	if(l==r)return;
	int m=l+r>>1,i=l,j=m+1,k=l;
	for(cdq(l,m),cdq(j,r),++id;j<=r;q[k++]=p[j++]){
		for(;i<=m&&p[i].x>=p[j].x;q[k++]=p[i++])if(p[i].i<2)add(p[i].y,p[i].i*(p[i].y-p[i].x));
		if(p[j].i>1)ans[p[j].i]+=sum(p[j].y);
	}
	memcpy(q+k,p+i,sizeof(P)*(r-k+1)),memcpy(p+l,q+l,sizeof(P)*(r-l+1));
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int m,i,j,k,l,t=0,q=1;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		if(cin>>a[i],s[l=a[i]].size())p[++t]={*s[l].rbegin(),i,1};
		s[l].insert(i);
	}
	while(m--)if(cin>>i>>j>>k,i==2)p[++t]={j,k,++q};else{
		auto u=s[l=a[j]].lower_bound(j);
		if(u!=s[l].begin())if(p[++t]={*prev(u),j,-1},u!=--s[l].end())p[++t]={*prev(u),*next(u),1};
		if(u!=--s[l].end())p[++t]={j,*next(u),-1};
		s[l].erase(u),u=s[k].insert(j).first,a[j]=k;
		if(u!=s[k].begin())if(p[++t]={*prev(u),j,1},u!=--s[k].end())p[++t]={*prev(u),*next(u),-1};
		if(u!=--s[k].end())p[++t]={j,*next(u),1};
	}
	for(cdq(1,t),i=2;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}