#include<bits/stdc++.h>
#define N 300100
#define X first
#define Y second
using namespace std;
const double PI=acos(-1);
int ang[N*4];
double sx[N*4],sy[N*4];
void push(int u){
	ang[u<<1]+=ang[u];
	ang[u<<1|1]+=ang[u];
	ang[u]=0;
}
inline double get_tx(int a){
	return sx[a]*cos(ang[a]*PI/180)-sy[a]*sin(ang[a]*PI/180);
}
inline double get_ty(int a){
	return sx[a]*sin(ang[a]*PI/180)+sy[a]*cos(ang[a]*PI/180);
}
void pull(int u){
	sx[u]=get_tx(u<<1)+get_tx(u<<1|1);
	sy[u]=get_ty(u<<1)+get_ty(u<<1|1);
}
void add_ang(int u,int ql,int qr,int l,int r,int a){
	if(l==ql&&r==qr){
		ang[u]-=a;
		ang[u]%=360;
		return;
	}
	push(u);
	int m=(l+r)/2;
	if(qr<=m) add_ang(u<<1,ql,qr,l,m,a);
	else if(ql>=m) add_ang(u<<1|1,ql,qr,m,r,a);
	else{
		add_ang(u<<1,ql,m,l,m,a);
		add_ang(u<<1|1,m,qr,m,r,a);
	}
	pull(u);
}
void add_len(int u,int ql,int l,int r,double len){
	if(l+1==r){
		sx[u]+=len;
		return;
	}
	push(u);
	int m=(l+r)/2;
	if(ql<m) add_len(u<<1,ql,l,m,len);
	else add_len(u<<1|1,ql,m,r,len);
	pull(u);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		add_len(1,i,1,n+1,1);
	}
	while(m--){
		int tp,a,b;
		scanf("%d%d%d",&tp,&a,&b);
		if(tp==1){
			add_len(1,a,1,n+1,b);
		}
		else{
			add_ang(1,a,n+1,1,n+1,b);
		}
		double nx,ny;
		nx=get_tx(1);
		ny=get_ty(1);
		printf("%.12f %.12f\n",nx,ny);
	}
	return 0;
}