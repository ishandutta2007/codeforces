#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int cmp(double x){if(x>eps)return 1;if(x<-eps)return -1;return 0;}
typedef long long ll;
int n;
ll T,S[150010],L[150010],R[150010];
struct dat{
	int p,t;
	friend bool operator<(const dat&u,const dat&v){return 1ll*u.t*v.p<1ll*u.p*v.t;}
}a[150010];
int ord[150010];
bool che(double c){
	auto LV=[=](int x){return a[x].p*(1-c*L[x]/T);};
	auto RV=[=](int x){return a[x].p*(1-c*R[x]/T);};
	double mx=0;
	for(int l=1,r=1;l<=n;l=r){
		while(r<=n&&a[ord[r]].p==a[ord[l]].p)if(cmp(mx-RV(ord[r++]))==1)return false;
		for(int i=l;i<r;i++)mx=max(mx,LV(ord[i]));
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].p),ord[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i].t;T=S[n];
	for(int l=1,r=1;l<=n;l=r){
		while(r<=n&&1ll*a[l].t*a[r].p==1ll*a[l].p*a[r].t)r++;
		for(int i=l;i<r;i++){
			L[i]=S[l-1]+a[i].t;
			R[i]=S[r-1];
		}
	}
//	for(int i=1;i<=n;i++)printf("%d,%d\n",a[i].p,a[i].t);
	sort(ord+1,ord+n+1,[](int x,int y){return a[x].p<a[y].p;});
//	for(int i=1;i<=n;i++)printf("%d ",ord[i]);puts("");
//	for(int i=1;i<=n;i++)printf("[%lld %lld]\n",L[i],R[i]);
	double l=0,r=1;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		if(che(mid))l=mid;else r=mid;
	}
	printf("%lf\n",l);
	return 0;
}