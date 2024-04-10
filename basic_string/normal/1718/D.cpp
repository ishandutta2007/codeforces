#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
int p[N],a[N],lc[N],rc[N],st[N],k,mn[N],s[N];
bool fl;
struct P{
	int l,r;
}w[N];
void dfs(int x,int y){
	if(a[x])y=min(y,a[x]),mn[x]=a[x];
	if(lc[x])dfs(lc[x],y),mn[x]=max(mn[x],mn[lc[x]]);
	if(rc[x])dfs(rc[x],y),mn[x]=max(mn[x],mn[rc[x]]);
	if(!a[x])w[++k]={mn[x],y};else if(mn[x]>a[x])fl=1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,q,i,tp;
	for(cin>>T;T--;){
		cin>>n>>q,tp=k=0;
		for(i=1;i<=n;++i){
			cin>>p[i],lc[i]=rc[i]=mn[i]=0;
			while(tp&&p[st[tp]]<p[i])lc[i]=st[tp--];
			if(tp)rc[st[tp]]=i;
			st[++tp]=i;
		}
		for(i=1;i<=n;++i)cin>>a[i];
		fl=0,dfs(st[1],1e9);
		for(i=1;i<k;++i)cin>>s[i];
		if(fl){
			while(q--)cin>>i,cout<<"NO\n";
			continue;
		}
		sort(w+1,w+k+1,[](P a,P b){return a.r<b.r;});
		set<int>h;
		for(i=1;i<k;++i)h.insert(s[i]);
		int lp=-1,rp=-1;
		for(i=1;i<=k;++i){
			auto o=h.lower_bound(w[i].l);
			if(o==end(h)||*o>w[i].r){
				if(rp==-1)rp=w[i].r;else fl=1;
			}else h.erase(o);
		}
		if(!fl){
			sort(w+1,w+k+1,[](P a,P b){return a.l>b.l;});
			for(i=1;i<k;++i)h.insert(s[i]);
			for(i=1;i<=k;++i){
				auto o=h.upper_bound(w[i].r);
				if(o==begin(h)||*(--o)<w[i].l){
					if(lp==-1)lp=w[i].l;else fl=1;
				}else h.erase(o);
			}
		}
		if(fl){
			while(q--)cin>>i,cout<<"NO\n";
			continue;
		}
		while(q--)if(cin>>i,lp<=i&&i<=rp)cout<<"YES\n";else cout<<"NO\n";
	}
}