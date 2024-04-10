#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3;
int w[N],t[N],g[N],u,v,s;
struct P{
	int l,r,x,v;
}p[N];
void upd(int k,int l,int r){
	if(u<=l&&r<=v)g[k]+=s;
	else{
		int m=l+r>>1;
		if(u<=m)upd(k*2,l,m);
		if(m<v)upd(k*2+1,m+1,r);
	}
	if(g[k])t[k]=w[r]^w[l-1];else t[k]=l==r?0:(t[k*2]^t[k*2+1]);
}
int main(){
	int m,k,i,a,b,c,d,o=0,ans=0;
	scanf("%*d%d%d",&m,&k);
	for(i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		w[++o]=b-1,p[o]={b-1,d,a-1,1};
		w[++o]=d,p[o]={b-1,d,c,-1};
	}
	sort(p+1,p+o+1,[](P a,P b){return a.x<b.x;}),sort(w+1,w+o+1),o=unique(w+1,w+o+1)-w-1;
	for(i=1;i<=m*2;++i){
		ans^=(p[i].x^p[i-1].x)&t[1];
		a=lower_bound(w+1,w+o+1,p[i].l)-w,b=lower_bound(w+1,w+o+1,p[i].r)-w;
		u=a+1,v=b,s=p[i].v,upd(1,1,o);
	}
	for(i=1;i<=k;i*=2);
	puts((ans&i-1)?"Hamed":"Malek");
	return 0;
}