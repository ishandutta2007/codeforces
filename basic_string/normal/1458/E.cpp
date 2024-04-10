#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct P{
	int x,y,i;
	bool operator<(P a)const{return x<a.x||(x==a.x&&(y<a.y||(y==a.y&&i<a.i)));}
}p[N*2];
bool ans[N];
int a[N],t,s[N];
bool f[N];
void add(int x){for(;x<=t;x+=x&-x)++s[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=s[x];return r;}
int main(){
	int n,m,o,i,u=0,d,h=-1,y,z;
	scanf("%d%d",&n,&m),o=n+m;
	for(i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y),a[i]=p[i].y;
	for(i=1;i<=m;++i)scanf("%d%d",&p[i+n].x,&p[i+n].y),p[i+n].i=i;
	sort(p+1,p+o+1),sort(a+1,a+n+1),t=unique(a+1,a+n+1)-a-1;
	for(i=1;i<=o;++i)if(p[i].i){
		if(!p[i-1].i&&p[i-1].x==p[i].x&&p[i-1].y==p[i].y)ans[p[i].i]=1;
		else if(p[i].x!=h){
			y=upper_bound(a+1,a+t+1,p[i].y)-a-1;
			if((p[i].y!=a[y]||!f[y])&&p[i].y+u-sum(y)==p[i].x)ans[p[i].i]=1;
		}
	}else{
		y=lower_bound(a+1,a+t+1,p[i].y)-a,d=u-sum(y),z=p[i].x-p[i].y;
		if(z<d){
			if(!f[y])f[y]=1,add(y);
		}else if(z>d&&h!=p[i].x)h=p[i].x,++u;
	}
	for(i=1;i<=m;++i)puts(ans[i]?"LOSE":"WIN");
	return 0;
}