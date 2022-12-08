#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n,a[N];
 
struct ST{
	int tot;
	int ls[N<<1],rs[N<<1];
	int mx[N<<1],tag[N<<1];
	
	void down(int x){
		if(tag[x]){
			if(ls[x]){
				mx[ls[x]]+=tag[x];
				tag[ls[x]]+=tag[x];
			}
			if(rs[x]){
				mx[rs[x]]+=tag[x];
				tag[rs[x]]+=tag[x];
			}
			tag[x]=0;
		}
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
	
	int getmx(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return mx[x];
		}
		down(x);
		int mid=l+r>>1,ret=0;
		if(L<=mid)ret=max(ret,getmx(ls[x],l,mid,L,R));
		if(R>mid)ret=max(ret,getmx(rs[x],mid+1,r,L,R));
		up(x);
		return ret;
	}
	
	void change(int x,int l,int r,int p,int val){
		if(l==r){
			mx[x]=max(mx[x],val);
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
			mx[x]+=val;
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
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int root=T.build(0,n);
	for(int i=1,r=1;i<=n;i=++r){
		while(r<n&&a[r+1]==a[r])++r;
		int j=a[i],last=a[i-1];
		int w=max(j==1?0:T.getmx(1,0,n,0,j-1),j==n?0:T.getmx(1,0,n,j+1,n));
		T.add(1,0,n,0,n,1);
		T.change(1,0,n,last,w+1);
		if(i!=r)T.change(1,0,n,j,w+2);
	}
	cout<<T.getmx(1,0,n,0,n)<<endl;
}