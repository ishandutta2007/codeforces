#include<bits/stdc++.h>
#define N 100100
using namespace std;
pair<double,double> solve(double m,double nm){
	double s=m+1-nm;
	double det;
	if(s*s-4*m<0) det=0;
	else det = sqrt(s*s-4*m);
	return make_pair((s+det)/2,(s-det)/2);
}
double mx[N],mn[N],sa[N],sb[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&mx[i]);
	for(int i=1;i<=n;i++) scanf("%lf",&mn[i]);
	for(int i=2;i<=n;i++) mx[i]+=mx[i-1];
	for(int i=n-1;i>0;i--) mn[i]+=mn[i+1];
	sa[n]=sb[n]=1;
	for(int i=1;i<n;i++){
		pair<double,double> tmp=solve(mx[i],mn[i+1]);
		sa[i]=tmp.first;
		sb[i]=tmp.second;
	}
	for(int i=n;i>1;i--){
		sa[i]-=sa[i-1];
		sb[i]-=sb[i-1];
	}
	for(int i=1;i<=n;i++) printf("%.8f ",sa[i]);
	puts("");
	for(int i=1;i<=n;i++) printf("%.8f ",sb[i]);
	puts("");
	return 0;
}