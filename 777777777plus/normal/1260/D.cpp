#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int m,n,k,t;
int a[N];
struct nd{
	int l,r,d;
	nd(int _l=0,int _r=0,int _d=0){
		l=_l;r=_r;d=_d;
	}
	friend bool operator < (nd a,nd b){
		return a.l<b.l||(a.l==b.l&&a.r<b.r);
	}
}b[N];

int can(int val){
	int Rlast=0,L=0,ret=0;
	for(int i=1;i<=k;++i)
	if(b[i].d>val){
		if(!Rlast||b[i].l>Rlast){
			if(Rlast)ret+=(Rlast-L+1)*2;
			L=b[i].l;
			Rlast=b[i].r;
		}
		else Rlast=max(Rlast,b[i].r);
	}
	if(Rlast)ret+=(Rlast-L+1)*2;
	return ret;
}

int main(){
	scanf("%d%d%d%d",&m,&n,&k,&t);
	t-=n+1;
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	for(int i=1,l,r,d;i<=k;++i){
		scanf("%d%d%d",&l,&r,&d);
		b[i]=nd(l,r,d);
	}
	sort(b+1,b+k+1);
	int l=0,r=m;
	while(l!=r){
		int mid=l+r+1>>1;
		if(can(a[m-mid+1])<=t)l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	
}