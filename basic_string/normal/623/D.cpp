#include<bits/stdc++.h>
using namespace std;
double p[109],d[109];
priority_queue<pair<double,int>>q;
int main(){
	int n,i,j;
	double s,w=1,l,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lf",p+i),w*=(d[i]=(p[i]/=100)),q.push({1-p[i],i});
	for(i=n+1,s=n*w;i<200000;++i)j=q.top().second,q.pop(),l=d[j],d[j]=l+(1-l)*p[j],t=w,s+=((w=w/l*d[j])-t)*i,q.push({p[j]/d[j]-p[j],j});
	printf("%.8lf",s);
	return 0;
}