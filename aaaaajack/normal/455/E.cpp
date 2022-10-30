#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define N 100100
#define inf 0x3f3f3f3f
using namespace std;
int a[N],sum[N],b[N];
vector<int> treex[N<<2],treeh[N<<2];
inline int intersect(int i,int j){
	return a[i]==a[j]?-1:(int)ceil(1.0*(b[i]-b[j])/(a[i]-a[j])-1e-6);
}
inline int cal(int i,int x){
	return b[i]-x*a[i];
}
void merge(int u){
	vector<int> &lx=treex[u*2],&lh=treeh[u*2];
	vector<int> &rx=treex[u*2+1],&rh=treeh[u*2+1];
	vector<int> &mx=treex[u],&mh=treeh[u];
	int i=0,j=0,tnxt,lnxt,rnxt,now=-1,nh;
	while(1){
		lnxt=(i==lx.size())?inf:lx[i];
		rnxt=(j==rx.size())?inf:rx[j];
		if(i&&j&&intersect(lh[i-1],rh[j-1])>now) tnxt=intersect(lh[i-1],rh[j-1]);
		else tnxt=inf;
		now=min(min(lnxt,rnxt),tnxt);
		if(now==inf) break;
		while(i<lx.size()&&lx[i]<=now) i++;
		while(j<rx.size()&&rx[j]<=now) j++;
		if(cal(lh[i-1],now)<cal(rh[j-1],now)) nh=lh[i-1];
		else nh=rh[j-1];
		if(mh.empty()||nh!=mh.back()){
			mx.push_back(now);
			mh.push_back(nh);
		}
		
	}		
}
void build(int u,int l,int r){
	int m=(l+r)/2;
	if(m==l){
		treex[u].push_back(0);
		treeh[u].push_back(l);
	}
	else{
		build(u*2,l,m);
		build(u*2+1,m,r);
		merge(u);
	}
}
int query(int u,int l,int r,int L,int R,int x,int y){
	if(l>=R||r<=L) return inf;
	if(l==L&&r==R){
		int idx=--upper_bound(treex[u].begin(),treex[u].end(),x)-treex[u].begin();
		return sum[y]+cal(treeh[u][idx],x);
	}
	int m=(L+R)/2;
	return min(query(u*2,l,min(m,r),L,m,x,y), query(u*2+1,max(m,l),r,m,R,x,y));
}	
int main(){
	int i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=a[i]+sum[i-1];
		b[i]=a[i]*i-sum[i];
	}
	build(1,1,n+1);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&i,&j);
		printf("%d\n",query(1,j-i+1,j+1,1,n+1,j-i,j));
	}
	return 0;
}