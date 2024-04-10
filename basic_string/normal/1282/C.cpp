#include<cstdio>
#include<algorithm>
struct ggg{
	bool f;
	int t;
	inline bool operator<(ggg x)const{return t<x.t;}
}s[200009];
int get(int w,int x,int y,int a,int b){
	if(x*a>=w)return w/a;
	return x+(w-x*a)/b;
}//
int main(){
	register int m,n,t,a,b,i,w,u,v,p,q;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d%d",&n,&t,&a,&b),q=u=0;
		for(i=1;i<=n;++i)scanf("%d",&s[i].f),q+=s[i].f;
		for(i=1;i<=n;++i)scanf("%d",&s[i].t);
		p=n-q;
		std::sort(s+1,s+n+1),s[n+1].t=2e9;
		if(s[1].t)w=get(s[1].t-1,p,q,a,b);else w=0;
		for(i=1;i<=n;++i){
			u+=s[i].f?b:a;
			if(s[i].f)--q;else --p;
			if(u>t)break;
			if(s[i].t==s[i+1].t)continue;
			if(s[i+1].t>u)v=i+get(s[i+1].t-1-u,p,q,a,b),w=w>v?w:v;
		}
		if(w>n)w=n;
		printf("%d\n",w);
	}
	return 0;
}