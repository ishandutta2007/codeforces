#include<bits/stdc++.h>
#define N 300100
using namespace std;
int mx[N+N],add[N+N];
int p[N],q[N],pos[N],ans[N];
int stk[N];
inline int get_mx(int u){
	return mx[u]+add[u];
}
inline void pull(int u){
	while(u){
		mx[u]=max(get_mx(u<<1),get_mx(u<<1|1));
		u>>=1;
	}	
}
inline void push(int u){
	int cnt=0;
	while(u){
		stk[cnt++]=u;
		u>>=1;
	}
	for(int i=cnt-1;i>=0;i--){
		u=stk[i];
		mx[u]+=add[u];
		add[u<<1|1]+=add[u];
		add[u<<1]+=add[u];
		add[u]=0;
	}
}
void upd(int l,int r,int n,int v){
	l+=n,r+=n;
	int tl=l,tr=r-1;
	while(l<r){
		if(l&1) add[l++]+=v;
		if(r&1) add[--r]+=v;
		l>>=1;
		r>>=1;
	}
	pull(tl>>1);
	pull(tr>>1);
}
int qry(int l,int r,int n){
	l+=n,r+=n;
	push(l);
	push(r-1);
	int tmp=-1023456789;
	while(l<r){
		if(l&1) tmp=max(tmp,get_mx(l++));
		if(r&1) tmp=max(tmp,get_mx(--r));
		l>>=1;
		r>>=1;
	}
	return tmp;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&q[i]);
	}
	int cur=n+1;
	for(int i=0;i<n;i++){
		while(qry(0,n,n)<=0){
			cur--;
			upd(0,pos[cur],n,1);
		}
		printf("%d ",cur);
		upd(0,q[i],n,-1);
	}
	return 0;
}