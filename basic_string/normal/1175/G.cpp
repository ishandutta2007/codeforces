#include<bits/stdc++.h>
using namespace std;
const int N=2e4+3,M=N<<5;
int u[N],v[N],*f=u,*g=v,a[N],rt[N],id,K[N],b[N],lc[M],rc[M],s[M],st[N];
#define F(x,t) (b[t]+a[t]*(x))
#define cp(p) (lc[++id]=lc[p],rc[id]=rc[p],s[id]=s[p],id)
void upd(int k,int l,int r,int t){
	if(l==r){if(F(l,t)<F(l,s[k]))s[k]=t;return;}
	int m=l+r>>1;
	if(F(m,t)<F(m,s[k]))swap(t,s[k]);
	F(l,t)<F(l,s[k])?upd(lc[k]=cp(lc[k]),l,m,t):upd(rc[k]=cp(rc[k]),m+1,r,t);
}
int qry(int k,int l,int r,int d){
	if(l==r||!k)return F(d,s[k]);
	int m=l+r>>1;
	return min(F(d,s[k]),d<=m?qry(lc[k],l,m,d):qry(rc[k],m+1,r,d));
}
struct H{
	deque<int>d;
	void mg(H&h){
		int t=h.d.size()-1;
		if(h.d.size()>d.size()){
			for(int x:d){
				while(t&&(g[x]-g[h.d[t]])*1ll*(h.d[t]-h.d[t-1])<=(g[h.d[t]]-g[h.d[t-1]])*1ll*(x-h.d[t]))--t,h.d.pop_back();
				++t,h.d.push_back(x);
			}
			swap(h.d,d);
		}else{
			for(int x;~t;--t){
				x=h.d[t];
				while(d.size()>1&&(g[d[0]]-g[x])*1ll*(d[1]-d[0])>=(g[d[1]]-g[d[0]])*1ll*(d[0]-x))d.pop_front();
				d.push_front(x);
			}
		}
	}
	int qry(int k){
		int l=1,r=d.size()-1,m;
		while(l<=r)if(m=l+r>>1,g[d[m]]-g[d[m-1]]<k*1ll*(d[m]-d[m-1]))l=m+1;else r=m-1;
		return g[d[l-1]]-(d[l-1]-1)*k;
	}
}h[N];
int main(){
	int i,j,k,t,n,m;
	scanf("%d%d",&n,&m),b[0]=2e9;
	for(i=1,j=0;i<=n;++i)scanf("%d",a+i),j=max(j,a[i]),f[i+1]=i*j;
	for(i=2;i<=m;++i){
		swap(f,g),id=t=0;
		for(j=i;j<=n;++j){
			h[j].d.resize(1),h[j].d[0]=j;
			while(t&&a[st[t]]<a[j])h[j].mg(h[st[t--]]);
			rt[j]=cp(rt[st[t]]),st[++t]=j,b[j]=h[j].qry(a[j]),upd(id,1,n,j),f[j+1]=qry(rt[j],1,n,j);
		}
	}
	printf("%d",f[n+1]);
	return 0;
}