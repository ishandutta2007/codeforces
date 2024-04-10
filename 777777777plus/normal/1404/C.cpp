#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n,Q;
int a[N];

struct ST{
	int tot;
	int ls[N<<1],rs[N<<1];
	int mn[N<<1],tag[N<<1];
	
	void down(int x){
		if(!tag[x])return;
		if(ls[x]){
			mn[ls[x]]+=tag[x];
			tag[ls[x]]+=tag[x];
		}
		if(rs[x]){
			mn[rs[x]]+=tag[x];
			tag[rs[x]]+=tag[x];
		}
		tag[x]=0;
	}
	
	void up(int x){
		mn[x]=min(mn[ls[x]],mn[rs[x]]);
	}
	
	int build(int l,int r){
		int x=++tot;
		if(l==r){
			if(a[l]<0)mn[x]=2e9;
			else mn[x]=a[l];
			return x;
		}
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		up(x);
		return x;
	}
	
	void change(int x,int l,int r,int L,int R,int d){
		if(L<=l&&r<=R){
			mn[x]+=d;
			tag[x]+=d;
			return;
		}
		down(x);
		int mid=l+r>>1;
		if(L<=mid)change(ls[x],l,mid,L,R,d);
		if(R>mid)change(rs[x],mid+1,r,L,R,d);
		up(x);
	}
	
	int getp(int x,int l,int r){
		if(l==r)return l;
		down(x);
		int mid=l+r>>1,ret;
		if(mn[rs[x]]==0)ret=getp(rs[x],mid+1,r);
		else if(mn[ls[x]]==0)ret=getp(ls[x],l,mid);
		up(x);
		return ret;
	}
	
	void init(){
		mn[0]=2e9;
		int root=build(1,n);
	}
	
	int get(){
		if(mn[1]>0)return -1;
		int p=getp(1,1,n);
		change(1,1,n,p,p,1e9);
		if(p<n){
			change(1,1,n,p+1,n,-1);
		}
		return p;
	}
}T;

struct CMT{
	int tot;
	int ls[N*20],rs[N*20];
	int w[N*20];
	void build(int &x,int y,int l,int r,int p){
		x=++tot;
		w[x]=w[y]+1;
		ls[x]=ls[y];
		rs[x]=rs[y];
		if(l==r)return;
		int mid=l+r>>1;
		if(p<=mid)build(ls[x],ls[y],l,mid,p);
		else build(rs[x],rs[y],mid+1,r,p);
	}
	
	int get(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return w[x];
		}
		int mid=l+r>>1,ret=0;
		if(L<=mid)ret+=get(ls[x],l,mid,L,R);
		if(R>mid)ret+=get(rs[x],mid+1,r,L,R);
		return ret;
	}
}T1;

int main(){
	cin>>n>>Q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)a[i]=i-a[i];
	T.init();
	vector<int> b;
	int pos;
	while(~(pos=T.get())){
		b.push_back(pos);
	}
	static int mn[N],rt[N];
	mn[1]=b[0];
	for(int i=1;i<b.size();++i)mn[i+1]=min(mn[i],b[i]);
	for(int i=1;i<=b.size();++i)T1.build(rt[i],rt[i-1],1,n,b[i-1]);
	for(int i=1,x,y;i<=Q;++i){
		cin>>x>>y;
		int l=0,r=n;
		while(l!=r){
			int mid=l+r+1>>1;
			if(mn[mid]>x)l=mid;
			else r=mid-1;
		}
		cout<<T1.get(rt[l],1,n,1,n-y)<<endl;
	}
}