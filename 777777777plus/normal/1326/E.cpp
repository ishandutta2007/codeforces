#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n;
int p[N],q[N],pos[N];
int ans[N];

struct ST{
	int tot;
	int ls[N<<1],rs[N<<1];
	int mx[N<<1],tag[N<<1];
	
	void down(int x){
		if(!tag[x])return;
		if(ls[x]){
			mx[ls[x]]+=tag[x];
			tag[ls[x]]+=tag[x];
		}
		if(ls[x]){
			mx[rs[x]]+=tag[x];
			tag[rs[x]]+=tag[x];
		}
		tag[x]=0;
	}
	
	void up(int x){
		mx[x]=max(mx[ls[x]],mx[rs[x]]);
	}
	
	int build(int l,int r){
		int x=++tot;
		if(l==r){
			mx[x]=0;
			return x;
		}
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		up(x);
		return x;
	}
	
	void change(int x,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){
			mx[x]+=val;
			tag[x]+=val;
			return;
		}
		down(x);
		int mid=l+r>>1;
		if(L<=mid)change(ls[x],l,mid,L,R,val);
		if(R>mid)change(rs[x],mid+1,r,L,R,val);
		up(x);
	}
	
	void init(){
		mx[0]=-1e9;
		int root=build(1,n);
	}
}T;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	for(int i=1;i<=n;++i)scanf("%d",&q[i]);
	ans[1]=n;
	int ansnow=n;
	T.init();
	T.change(1,1,n,1,pos[n],1);
	for(int i=1;i<n;++i){
		T.change(1,1,n,1,q[i],-1);
		while(T.mx[1]<=0){
			ansnow--;
			T.change(1,1,n,1,pos[ansnow],1);
		}
		ans[i+1]=ansnow;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	printf("\n");
}