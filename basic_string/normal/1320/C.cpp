#include<bits/stdc++.h>
using namespace std;
const int N=200009,M=1000009,P=1000001;
struct WP{
	int a,c;
	inline bool operator<(WP x)const{return a<x.a;}
}wp[N];
struct AM{
	int b,c;
	inline bool operator<(AM x)const{return b<x.b;}
}am[N];
struct MS{
	int a,b,c;
	inline bool operator<(MS x)const{return b<x.b;}
}ms[N];
int s[M<<2],t[M<<2],u,v,w;
inline void psd(int k,int a,int b){
	s[a]+=t[k],s[b]+=t[k],t[a]+=t[k],t[b]+=t[k],t[k]=0;
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		s[k]+=w,t[k]+=w;
		return;
	}
	int m=l+r>>1,a=k<<1,b=a|1;
	psd(k,a,b);
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k]=max(s[a],s[b]);
}
int main(){
	int la=0,n,m,p,i,j,ans=-2e9;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;++i)scanf("%d%d",&wp[i].a,&wp[i].c);
	for(i=1;i<=m;++i)scanf("%d%d",&am[i].b,&am[i].c);
	sort(wp+1,wp+n+1),sort(am+1,am+m+1);
	for(i=2;i<=n;++i)if(wp[i].a==wp[i-1].a)wp[i].c=min(wp[i].c,wp[i-1].c);
	for(i=1,wp[n+1].a=-1;i<=n;++i){
		if(wp[i].a==wp[i+1].a)continue;
		u=la,v=wp[i].a-1,w=-wp[i].c,upd(1,0,P),la=wp[i].a;
	}
	u=la,v=P,w=-2e9,upd(1,0,P);
	for(i=1;i<=p;++i){
		scanf("%d%d%d",&ms[i].a,&ms[i].b,&ms[i].c);
	}
	sort(ms+1,ms+p+1),ms[p+1].b=2e9,p=1;
	for(i=1;i<=m;++i){
		while(ms[p].b<am[i].b){
			u=ms[p].a,v=P,w=ms[p].c;
			upd(1,0,P);
			++p;
		}
		ans=max(ans,-am[i].c+s[1]);
	}
	printf("%d",ans);
	return 0;
}//