#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=4e5+3;
struct T{
	double x,y;
}s[M];
double g[N];
int u,v;
T up(T a,T b){
	return(T){a.x*b.x,a.y+a.x*b.y};
}
void build(int k,int l,int r){
	if(l==r){
		s[k].x=s[k].y=g[l];
		return;
	}
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r);
	s[k]=up(s[k*2],s[k*2+1]);
}
void upd(int k,int l,int r){
	if(l==r){
		s[k].x=s[k].y=g[l];
		return;
	}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);else upd(k*2+1,m+1,r);
	s[k]=up(s[k*2],s[k*2+1]);
}
T qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k];
	int m=l+r>>1;
	if(u<=m&&m<v)return up(qry(k*2,l,m),qry(k*2+1,m+1,r));
	if(u<=m)return qry(k*2,l,m);
	return qry(k*2+1,m+1,r);
}
int main(){
	int n,q,i,j,k;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i){
		scanf("%d%d",&j,&k);
		g[i]=(k-j)*1.0/j;
	}
	build(1,1,n);
	while(q--){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1){
			scanf("%d",&i);
			g[j]=(i-k)*1.0/k,u=j;
			upd(1,1,n);
		}else{
			u=j,v=k;
			printf("%lf\n",1/(1+qry(1,1,n).y));
		}
	}
	return 0;
}