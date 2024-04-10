#include<bits/stdc++.h>
using namespace std;
enum{N=2009};
double ans,p[N],u[N];
int n,a,b;
struct T{
	double x;
	int a0,a1;
}t[N];
bool chk(double k){
	int i,c=0;
	ans=0;
	for(i=1;i<=n;++i){
		if(p[i]>p[i]+u[i]-p[i]*u[i]-k)t[i].a1=0,t[i].x=p[i];
		else t[i].a1=1,t[i].x=p[i]+u[i]-p[i]*u[i]-k;
		if(0>u[i]-k)t[i].a0=0;
		else t[i].a0=1,t[i].x-=u[i]-k,ans+=u[i]-k;
	}
	sort(t+1,t+n+1,[](T a,T b){return a.x>b.x;});
	for(i=1;i<=a;++i)c+=t[i].a1,ans+=t[i].x;
	for(;i<=n;++i)c+=t[i].a0;
	return c<b;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	double l=0,r=1,m;
	int i;
	cin>>n>>a>>b;
	for(i=1;i<=n;++i)cin>>p[i];
	for(i=1;i<=n;++i)cin>>u[i];
	for(i=1;i<77;++i){
		m=(l+r)/2;
		if(chk(m))r=m;else l=m;
	}
	cout<<fixed<<setprecision(9)<<ans+b*m;
}