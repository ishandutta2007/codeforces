#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
long long ans;
long a[100001],b[100001],l,r;
long long fii1(int x){
	long long s=0;
	for(int i=0;i<x;i++)s+=a[x]-a[i];
	for(int i=0;i<m;i++)if(b[i]>a[x])s+=b[i]-a[x];
	return s;
}
long long fii2(int x){
	long long s=0;
	for(int i=m-1;i>x;i--)s+=b[i]-b[x];
	for(int i=0;i<n;i++)if(a[i]<b[x])s+=b[x]-a[i];
	return s;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	l=0,r=n-1;
	while(l<r){
		int m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(fii1(m1)>fii1(m2))l=m1+1;
		else r=m2-1;
	}
	ans=fii1(r);
	l=0,r=m-1;
	while(l<r){
		int m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(fii2(m1)>fii2(m2))l=m1+1;
		else r=m2-1;
	}
	ans=min(ans,fii2(r));
	cout<<ans;
	return 0;
}