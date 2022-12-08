#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,m,p;
ll ans=-1e18;

struct nd{
	int val,c;
	friend bool operator < (nd a,nd b){
		return a.val<b.val;
	}
}a[N],b[N];

struct mon{
	int x,y,z;
	friend bool operator < (mon a,mon b){
		return a.x<b.x;
	}
}c[N];

struct BIT{
	int tot;
	int ls[N<<1],rs[N<<1];
	ll mx[N<<1],tag[N<<1];
	void up(int x){
		mx[x]=max(mx[ls[x]],mx[rs[x]]);
	}
	void down(int x){
		if(!tag[x])return;
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
	int build(int l,int r){
		int x=++tot;
		if(l==r){
			mx[x]=-b[l].c;
			return x;
		}
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		up(x);
		return x;
	}
	void add(int x,int l,int r,int L,int R,ll d){
		if(L<=l&&r<=R){
			mx[x]+=d;
			tag[x]+=d;
			return;
		}
		down(x);
		int mid=l+r>>1;
		if(L<=mid)add(ls[x],l,mid,L,R,d);
		if(R>mid)add(rs[x],mid+1,r,L,R,d);
		up(x);
	}
	void init(){
		mx[0]=-1e18;
		int root=build(1,m);
	}
}T;

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].val,&a[i].c);
	for(int i=1;i<=m;++i)scanf("%d%d",&b[i].val,&b[i].c);
	for(int i=1;i<=p;++i)scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+p+1);
	T.init();
	for(int i=1,R=0;i<=n;++i){
		while(R<p&&c[R+1].x<a[i].val){
			++R;
			int l=1,r=m;
			while(l!=r){
				int mid=l+r>>1;
				if(b[mid].val>c[R].y)r=mid;
				else l=mid+1;
			}
			if(b[l].val>c[R].y){
				T.add(1,1,m,l,m,c[R].z);
			}
		}
		ans=max(ans,-a[i].c+T.mx[1]);
	}
	printf("%lld\n",ans);
}