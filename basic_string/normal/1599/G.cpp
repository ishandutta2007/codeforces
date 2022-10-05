#include<bits/stdc++.h>
    using namespace std;
    const int N=2e5+3;
    const double inf=1e18;
    struct P{
	int x,y;
	int i;
}p[N];
    double ans=inf;
    using pp=pair<double,double>;
    pp get(int i,int j){
	if(p[i].x==p[j].x)return{inf,p[i].x};
	double k=(p[i].y-p[j].y)*1./(p[i].x-p[j].x),b=p[i].y-k*p[i].x;
	return{k,b};
}
    bool eq(const pp&a,const pp&b){
	if(fabs(a.first-b.first)<1e-9&&fabs(a.second-b.second)<1e-9)return 1;
	return 0;
}
    double dis(int i,int j){
	return hypot(p[i].x-p[j].x,p[i].y-p[j].y);
}
    int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,n,st,x;
	cin>>n>>st;
	for(i=1;i<=n;++i)cin>>p[i].x>>p[i].y,p[i].i=i;
	if(n==3)x=1;
	else{
		if(eq(get(1,2),get(1,3))){
			pp p=get(1,2);
			for(i=4;i<=n;++i)if(!eq(get(1,i),p)){x=i;goto gg;}
			x=1;gg:;
		}else{
			if(eq(get(2,3),get(3,4)))x=1;
			else if(eq(get(1,3),get(3,4)))x=2;
			else x=3;
		}
	}
	swap(p[x],p[n]);
	sort(p+1,p+n,[](P a,P b){return a.x<b.x||(a.x==b.x&&a.y<b.y);});
	for(i=1;i<=n;++i)if(p[i].i==st){st=i;break;}
	if(st==n){
		ans=min(dis(st,1),dis(st,n-1))+dis(1,n-1);
	}else{
		ans=min(ans,dis(1,n-1)+min(dis(st,1)+dis(n-1,n),dis(st,n-1)+dis(1,n)));
		ans=min(ans,dis(1,n-1)+dis(st,n)+min(dis(n,n-1),dis(n,1)));
			for(i=2;i<=st;++i){
				ans=min(ans,min(dis(st,i)+dis(i,n-1)+dis(n-1,n),dis(st,n-1)+dis(n-1,i)+dis(i,n))+dis(n,i-1)+dis(i-1,1));
				}
				for(i=st;i<n-1;++i){
					ans=min(ans,min(dis(st,i)+dis(i,1)+dis(1,n),dis(st,1)+dis(1,i)+dis(i,n))+dis(n,i+1)+dis(i+1,n-1));
				}
	}
	cout<<fixed<<setprecision(9)<<ans;exit(0);
	return 0;
}