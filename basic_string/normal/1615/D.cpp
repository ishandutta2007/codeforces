#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
struct E{
	int x,y,v;
}e[N];
struct P{
	int a,b,p;
}p[N];
int f[N*2];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y){
	f[gf(x)]=gf(y);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=1;i<n;++i)cin>>e[i].x>>e[i].y>>e[i].v;
		for(i=1;i<=m;++i)cin>>p[i].a>>p[i].b>>p[i].p;
		for(i=1;i<=n*2;++i)f[i]=i;
		for(i=1;i<n;++i)if(e[i].v>=0){
			if(__builtin_parity(e[i].v))mg(e[i].x,e[i].y+n),mg(e[i].x+n,e[i].y);
			else mg(e[i].x,e[i].y),mg(e[i].x+n,e[i].y+n);
		}
		for(i=1;i<=m;++i){
			if(__builtin_parity(p[i].p)){
				if(gf(p[i].a)==gf(p[i].b)){cout<<"NO\n";goto gg;}
				mg(p[i].a,p[i].b+n),mg(p[i].a+n,p[i].b);
			}else{
				if(gf(p[i].a)==gf(p[i].b+n)){cout<<"NO\n";goto gg;}
				mg(p[i].a,p[i].b),mg(p[i].a+n,p[i].b+n);
			}
		}
		for(i=1;i<n;++i)if(e[i].v==-1){
			if(gf(e[i].x)==gf(e[i].y))e[i].v=0;
			else if(gf(e[i].x)==gf(e[i].y+n))e[i].v=1;
			else e[i].v=0,mg(e[i].x,e[i].y),mg(e[i].x+n,e[i].y+n);
		}
		cout<<"YES\n";
		for(i=1;i<n;++i)cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].v<<'\n';
		gg:;
	}
	return 0;
}