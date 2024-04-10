#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("O2")
using namespace std;
int T,n,m,a[1000005],b[1000005],cnt;
pair<int,int> p[2000005];
vector<int> v[2000005];
int t[2000005];
void add(int x){while(x<=cnt)++t[x],x+=(x&-x);}
int sum(int x){int ret=0;while(x)ret+=t[x],x-=(x&-x);return ret;}
int M[5000005],A[5000005],L,R;
void upd(int k,int l,int r){
	if(l>=L&&r<=R){
		++A[k];
		++M[k];
		return;
	}
	int m=(l+r)>>1,lc=k<<1,rc=lc|1;
	if(A[k]){
		A[lc]+=A[k],A[rc]+=A[k],M[lc]+=A[k],M[rc]+=A[k];
		A[k]=0;
	}
	if(L<=m)upd(lc,l,m);
	if(R>m)upd(rc,m+1,r);
	M[k]=min(M[lc],M[rc]);
}
void upd2(int k,int l,int r){
	if(l>=L&&r<=R){
		--A[k];
		--M[k];
		return;
	}
	int m=(l+r)>>1,lc=k<<1,rc=lc|1;
	if(A[k]){
		A[lc]+=A[k],A[rc]+=A[k],M[lc]+=A[k],M[rc]+=A[k];
		A[k]=0;
	}
	if(L<=m)upd2(lc,l,m);
	if(R>m)upd2(rc,m+1,r);
	M[k]=min(M[lc],M[rc]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",a+i),p[i]=mp(a[i],i);
		for(int i=1;i<=m;++i)scanf("%d",b+i),p[i+n]=mp(b[i],-i);
		sort(p+1,p+n+m+1);
		cnt=0;
		for(int i=1;i<=n+m;++i){
			if(p[i].first!=p[i-1].first)++cnt;
			if(p[i].second>0)a[p[i].second]=cnt;
			else b[-p[i].second]=cnt;
		}
		sort(b+1,b+m+1);
		for(int i=1;i<=cnt;++i)v[i].clear(),t[i]=0;
		for(int i=1;i<=n;++i)v[a[i]].pb(i);
		ll ans=0;
		for(int i=1;i<=n;++i)ans+=i-1ll-sum(a[i]),add(a[i]);
		for(int i=1;i<=(n+1)*4;++i)M[i]=A[i]=0;
		for(int i=1;i<=n;++i)L=i+1,R=n+1,upd(1,1,n+1);
		int _=0;
		for(int i=1;i<=m;++i){
			while(_<b[i]){
				for(int j=0;j<v[_].size();++j)L=1,R=v[_][j],upd(1,1,n+1);
				++_;
				for(int j=0;j<v[_].size();++j)L=v[_][j]+1,R=n+1,upd2(1,1,n+1);
			}
			ans+=M[1];
		}
		printf("%I64d\n",ans);
				
	}
    return 0;
}