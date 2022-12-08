#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n,Q,a[N];
set<int> in;
set<int>::iterator it,ij;

int tot;
int ls[N],rs[N],tag[N];
ll s[N];

void up(int x){
	s[x]=s[ls[x]]+s[rs[x]];
}

void down(int x,int l,int r){
	if(!tag[x])return;
	int mid=l+r>>1;
	if(ls[x]){
		tag[ls[x]]=tag[x];
		s[ls[x]]=1ll*tag[x]*(mid-l+1);
	}
	if(rs[x]){
		tag[rs[x]]=tag[x];
		s[rs[x]]=1ll*tag[x]*(r-mid);
	}
	tag[x]=0;
}

int build(int l,int r){
	int x=++tot;
	if(l==r){
		s[x]=n+1;
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
		tag[x]=d;
		s[x]=1ll*d*(r-l+1);
		return;
	}
	down(x,l,r);
	int mid=l+r>>1;
	if(L<=mid)change(ls[x],l,mid,L,R,d);
	if(R>mid)change(rs[x],mid+1,r,L,R,d);
	up(x);
}

ll sum(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return s[x];
	}
	down(x,l,r);
	int mid=l+r>>1;
	ll ret=0;
	if(L<=mid)ret+=sum(ls[x],l,mid,L,R);
	if(R>mid)ret+=sum(rs[x],mid+1,r,L,R);
	up(x);
	return ret;
}

void add(int x){
	if(a[x-1]>a[x]){
		in.erase(x);
		it=in.lower_bound(x);
		ij=it;
		--ij;
		int l=*ij,r=*it;
		if(l==0)++l;
		if(l<r)change(1,1,n,l,r-1,r);
	}
}

void dec(int x){
	if(a[x-1]>a[x]){
		in.insert(x);
		it=in.find(x);
		ij=it;
		--ij;
		int l=*ij,r=*it;
		if(l==0)++l;
		if(l<r)change(1,1,n,l,r-1,r);
	}
}

int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	in.insert(0);
	in.insert(n+1);
	int root=build(1,n);
	a[0]=2e9;
	for(int i=1;i<=n;++i){
		if(a[i-1]>a[i]){
			in.insert(i);
			it=in.find(i);
			ij=it;
			--ij;
			int l=*ij,r=*it;
			if(l==0)++l;
			if(l<r)change(1,1,n,l,r-1,r);
		}
	}
	while(Q--){
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			add(x);if(x<n)add(x+1);
			a[x]=y;
			dec(x);if(x<n)dec(x+1);
		}
		else{
			it=in.upper_bound(y);
			ij=it;
			--ij;
			int p=*ij,lim=*it;
			if(p==0)++p;
			ll cnt=min(lim,y+1)-max(x,p);
			ll res=sum(1,1,n,x,y);
			res-=1ll*(x+y)*(y-x+1)/2;
			if(cnt>0)res-=cnt*(lim-(y+1));
			printf("%lld\n",res);
		}
	}
}