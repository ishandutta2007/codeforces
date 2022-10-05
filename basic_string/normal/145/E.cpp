#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct T{
	bool t;
	int sa,sb,ta,tb;
}t[N<<2];
char s[N],o[9];
int u,v;
inline void rev(T&k){
	k.t^=1,swap(k.sa,k.sb),swap(k.ta,k.tb);
}
inline void up(T&k,T a,T b){
	k.ta=a.ta+b.ta,k.tb=a.tb+b.tb;
	k.sa=max(a.sa+b.tb,a.ta+b.sa);
	k.sb=max(a.sb+b.ta,a.tb+b.sb);
}
void build(int k,int l,int r){
	if(l==r){
		t[k].sa=t[k].sb=1;
		if(s[l]=='4')t[k].ta=1;
		else t[k].tb=1;
		return;
	}
	int m=l+r>>1,a=k<<1,b=a|1;
	build(a,l,m),build(b,m+1,r),up(t[k],t[a],t[b]);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return rev(t[k]);
	int m=l+r>>1,a=k<<1,b=a|1;
	if(t[k].t)t[k].t=0,rev(t[a]),rev(t[b]);
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	up(t[k],t[a],t[b]);
}
int main(){
	int n,m;
	scanf("%d%d%s",&n,&m,s+1),build(1,1,n);
	while(m--){
		scanf("%s",o);
		if(o[0]=='s')scanf("%d%d",&u,&v),upd(1,1,n);
		else printf("%d\n",t[1].sa);
	}
	return 0;
}