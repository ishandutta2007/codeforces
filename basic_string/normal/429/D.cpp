#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct P{
	int x,y;
}p[N],o[N];
long long pf(int x){return x*1ll*x;}
long long wk(int l,int r){
	if(l==r)return 4e18;
	int m=l+r>>1,t=0,i,j,w=p[m].x;
	long long d=min(wk(l,m),wk(m+1,r));
	merge(p+l,p+m+1,p+m+1,p+r+1,o,[](P a,P b){return a.y<b.y;}),memcpy(p+l,o,sizeof(P)*(r-l+1));
	for(i=l;i<=r;++i)if(pf(p[i].x-w)<d)o[++t]=p[i];
	for(i=1;i<=t;++i)for(j=i+1;j<=t&&pf(o[j].y-o[i].y)<d;++j)d=min(d,pf(o[j].x-o[i].x)+pf(o[j].y-o[i].y));
	return d;
}
int main(){
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;++i)p[i].x=i,scanf("%d",&p[i].y),p[i].y+=p[i-1].y; 
	sort(p+1,p+n+1,[](P a,P b){return a.x<b.x;});
	cout<<wk(1,n);
	return 0;
}