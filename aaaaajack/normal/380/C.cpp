#include<cstdio>
#include<string>
#include<iostream>
#define msize (1<<21)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
struct brk{
	int l;
	int r;
	int w;
	brk():l(0),r(0),w(0){}
	brk(int l,int r,int w):l(l),r(r),w(w){}
};
brk st[msize];
string s;
brk merge(const brk& a,const brk& b){
	return brk(a.l+b.l-min(a.l,b.r),a.r+b.r-min(a.l,b.r),a.w+b.w+min(a.l,b.r));
}
void build(){
	int i,r;
	for(i=0;i<msize;i++) st[i]=brk();
	for(i=0;i<s.size();i++){
		if(s[i]=='('){
			st[2*i+1].l=1;
			st[2*i+1].r=0;
			st[2*i+1].w=0;
		}
		else{
			st[2*i+1].l=0;
			st[2*i+1].r=1;
			st[2*i+1].w=0;
		}
	}
	for(r=2;r<msize;r<<=1){
		for(i=r;i<msize;i+=(r<<1)){
			int lc=i-(r>>1),rc=i+(r>>1);
			st[i]=merge(st[lc],st[rc]);
		}
	}
}
brk query(int L,int R){
	if(R<L) return brk(0,0,0);
	int lb,lp,plb;
	while(1){
		lb=R&(-R),lp=R-lb,plb=lp&-lp;
		if(lb!=(plb>>1)) break;
		if(lp-(lp&(-lp))<L) break;
		R=lp;
	}
	return merge(query(L,lp-1),st[R]);
}
			
int main(){
	cin>>s;
	build();
	int q,l,r;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",2*query(2*l-1,2*r-1).w);
	}
	return 0;
}