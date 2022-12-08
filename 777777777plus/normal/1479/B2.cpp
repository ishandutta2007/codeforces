#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n,a[N];
 
struct ST{
	int tot;
	int ls[N<<1],rs[N<<1];
	int mn[N<<1],tag[N<<1];
	
	void down(int x){
		if(tag[x]){
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
	}
	
	void up(int x){
		mn[x]=min(mn[ls[x]],mn[rs[x]]);
	}
	
	int build(int l,int r){
		int x=++tot;
		if(l==r){
			mn[x]=1e9;
			return x;
		}
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		up(x);
		return x;
	}
	
	int getmn(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return mn[x];
		}
		down(x);
		int mid=l+r>>1,ret=1e9;
		if(L<=mid)ret=min(ret,getmn(ls[x],l,mid,L,R));
		if(R>mid)ret=min(ret,getmn(rs[x],mid+1,r,L,R));
		up(x);
		return ret;
	}
	
	void change(int x,int l,int r,int p,int val){
		if(l==r){
			mn[x]=min(mn[x],val);
			return;
		}
		down(x);
		int mid=l+r>>1;
		if(p<=mid)change(ls[x],l,mid,p,val);
		else change(rs[x],mid+1,r,p,val);
		up(x);
	}
	
	void add(int x,int l,int r,int L,int R,int val){
		if(L<=l&&r<=R){
			mn[x]+=val;
			tag[x]+=val;
			return;
		}
		down(x);
		int mid=l+r>>1;
		if(L<=mid)add(ls[x],l,mid,L,R,val);
		if(R>mid)add(rs[x],mid+1,r,L,R,val);
		up(x);
	}
}T;
 
int main(){
	T.mn[0]=1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int root=T.build(0,n);
	T.change(1,0,n,0,0);
	for(int i=1,r=1;i<=n;i=++r){
		while(r<n&&a[r+1]==a[r])++r;
		int j=a[i],last=a[i-1];
		int w=min(j==0?1e9:T.getmn(1,0,n,0,j-1),j==n?1e9:T.getmn(1,0,n,j+1,n));
		int wr=T.getmn(1,0,n,j,j);
		T.add(1,0,n,0,n,1);
		T.change(1,0,n,last,w+1);
		T.change(1,0,n,last,wr);
	}
	cout<<T.getmn(1,0,n,0,n)<<endl;
}