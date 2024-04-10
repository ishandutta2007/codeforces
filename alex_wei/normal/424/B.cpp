#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct city{
	int x,y,v;
	double dis;
}c[N];
bool cmp(city a,city b){
	return a.dis<b.dis;
}
int n,s;
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++)cin>>c[i].x>>c[i].y>>c[i].v,c[i].dis=sqrt(c[i].x*c[i].x+c[i].y*c[i].y);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		c[i].v+=c[i-1].v;
		if(c[i].v+s>=1e6)printf("%.10lf\n",c[i].dis),exit(0);
	}
	puts("-1");
	return 0;
}