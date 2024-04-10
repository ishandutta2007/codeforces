#include<bits/stdc++.h>
using namespace std;
const int N=1009;
struct P{
	int x,y;
	void in(){scanf("%d%d",&x,&y);}
	P operator+(P a)const{return{x+a.x,y+a.y};}
	P operator-(P a)const{return{x-a.x,y-a.y};}
	int sqr(){return x*x+y*y;}
}p,q,u,a[N],b[N];
int dis(P a,P b){return (a-b).sqr();}
int r,d[N];
int main(){
	int n,m,i,j,k,l;
	p.in(),scanf("%d",&n);
	for(i=1;i<=n;++i)a[i].in();
	q.in(),scanf("%d",&m),r=dis(p,q);
	for(i=1;i<=m;++i)b[i].in();
	for(i=1;i<=n;++i){
		u=q+a[i]-p;
		for(j=1;j<=m;++j)d[j]=dis(b[j],u);
		for(j=1;j<=m;++j){
			k=j==m?1:j+1;
			if((d[j]<=r&&d[k]>=r)||(d[k]<=r&&d[j]>=r))return puts("YES"),0;
			if(d[j]>r&&d[k]>r){
				l=dis(b[j],b[k]);
				if((l+d[j]>=d[k])&&(l+d[k]>=d[j])&&(4ll*d[j]*l-(l+d[j]-d[k])*1ll*(l+d[j]-d[k]))<=r*4ll*l)return puts("YES"),0;
			}
		}
	}
	for(i=1;i<=m;++i){
		u=p+b[i]-q;
		for(j=1;j<=n;++j)d[j]=dis(a[j],u);
		for(j=1;j<=n;++j){
			k=j==n?1:j+1;
			if((d[j]<=r&&d[k]>=r)||(d[k]<=r&&d[j]>=r))return puts("YES"),0;
			if(d[j]>r&&d[k]>r){
				l=dis(a[j],a[k]);
				if((l+d[j]>=d[k])&&(l+d[k]>=d[j])&&(4ll*d[j]*l-(l+d[j]-d[k])*1ll*(l+d[j]-d[k]))<=r*4ll*l)return puts("YES"),0;
			}
		}
	}
	puts("NO");
	return 0;
}