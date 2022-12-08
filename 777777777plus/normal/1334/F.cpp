#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const int M = 21;

int n,m,a[N],w[N],b[N];
int rt[N];
ll f[N],sufw[N],ans=1e18;
vector<int>pos[N];

struct CMT{
	int tot=0;
	int ls[N*M],rs[N*M];
	ll w[N*M];
	
	int insert(int y,int l,int r,int p,int val){
		int x=++tot;
		w[x]=w[y]+val;
		if(l==r)return x;
		ls[x]=ls[y];rs[x]=rs[y];
		int mid=l+r>>1;
		if(p<=mid)ls[x]=insert(ls[y],l,mid,p,val);
		else rs[x]=insert(rs[y],mid+1,r,p,val);
		return x;
	}
	
	ll get(int x,int y,int l,int r,int L,int R){
		if(L>R)return 0;
		if(L<=l&&r<=R)return w[x]-w[y];
		int mid=l+r>>1;
		ll ret=0;
		if(L<=mid)ret=get(ls[x],ls[y],l,mid,L,R);
		if(R>mid)ret+=get(rs[x],rs[y],mid+1,r,L,R);
		return ret;
	}
	
}T0;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	a[++n]=n;
	pos[0].push_back(0);
	for(int i=1;i<=n;++i){
		sufw[i]=sufw[i-1]+w[i];
		pos[a[i]].push_back(i);
		rt[i]=T0.insert(rt[i-1],1,n,a[i],max(w[i],0));
		f[i]=1e18;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	b[++m]=n;
	for(int i=1;i<=m;++i){
		int x=b[i],y=b[i-1];
		ll det=0,mn=1e18;
		for(int j=0,t=0;j<pos[x].size();++j){
			int p=pos[x][j];
			if(j)det+=sufw[p-1]-sufw[pos[x][j-1]-1]-T0.get(rt[p-1],rt[pos[x][j-1]-1],1,n,1,y);
			while(t<pos[y].size()&&pos[y][t]<p){
				ll tmp=sufw[p-1]-sufw[pos[y][t]]-T0.get(rt[p-1],rt[pos[y][t]],1,n,1,y);
				if(f[pos[y][t]]!=1e18)mn=min(mn,f[pos[y][t]]+tmp-det);
				++t;
			}
			if(mn!=1e18)f[p]=mn+det;
			if(i==m)ans=min(ans,f[p]);
		}
	}
	if(ans>=1e18)printf("NO\n");
	else printf("YES\n%lld\n",ans);
}