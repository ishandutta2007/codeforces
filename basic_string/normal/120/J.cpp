#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3;
struct P{
	int x,y,i,k;
}p[N],o[N];
int ans=1e9,I,K1,J,K2;
int pf(int x){return x*x;}
int wk(int l,int r){
	if(l==r)return 1e9;
	int m=l+r>>1,t=0,i,j,w=p[m].x,d=min(wk(l,m),wk(m+1,r));
	merge(p+l,p+m+1,p+m+1,p+r+1,o,[](P a,P b){return a.y<b.y;}),memcpy(p+l,o,sizeof(P)*(r-l+1));
	for(i=l;i<=r;++i)if(pf(p[i].x-w)<d)o[++t]=p[i];
	for(i=1;i<=t;++i)for(j=i+1;j<=t&&pf(o[j].y-o[i].y)<d;++j)if(o[i].i!=o[j].i){
		d=min(d,pf(o[j].x-o[i].x)+pf(o[j].y-o[i].y));
		if(ans>d)ans=d,I=o[i].i,J=o[j].i,K1=o[i].k,K2=o[j].k;
	}
	return d;
}
int main(){freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	int n,i,x,y,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		p[++t]={x,y,i,1};
		p[++t]={-x,y,i,2};
		p[++t]={x,-y,i,3};
		p[++t]={-x,-y,i,4};
	}
	sort(p+1,p+t+1,[](P a,P b){return a.x<b.x;});
	wk(1,t);
	printf("%d %d %d %d",I,5-K1,J,K2);
	return 0;
}