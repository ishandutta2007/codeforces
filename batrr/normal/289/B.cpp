#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n,m,a[10000],d,ans=0,ansm,l=0,r;
void check(){
	for(int i=1;i<n;i++)if((a[i]-a[i-1])%d!=0)ans=-1;
	return ;}
int fii(int x){
	int sum=0;
	for(int i=0;i<n;i++)sum+=abs(a[i]-a[x]);
	sum/=d;
	return sum;
}
int main(){
	cin>>n>>m>>d;
	n*=m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	check();
	if(ans==-1){
		cout<<-1;
		return 0;
	}
	r=n;
	while(l<r){
		int m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(fii(m1)>fii(m2))l=m1+1;
		else r=m2-1;
		}
	cout<<fii(r);
	return 0;
}