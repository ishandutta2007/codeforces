#include <cstdio>
#include <algorithm>
#include <vector>

#define double long double

using namespace std;
typedef long long lli;

int n,arr[200001];
double sum[200001];

inline double _abs(double a) {return a<0 ? -a : a;}
double check(double val) {
	for(int i=1;i<=n;i++) sum[i] = sum[i-1] + (arr[i]-val);
	
	double ans=0,mx=0,mn=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans,_abs(sum[i]-mx));
		ans=max(ans,_abs(sum[i]-mn));
		mx=max(mx,sum[i]);
		mn=min(mn,sum[i]);
	}
	return ans;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	
	double lo=-1e5,up=1e5;
	for(int it=0;it<100;it++) {
		double m1=(lo*2+up)/3,m2=(lo+up*2)/3;
		double v1=check(m1),v2=check(m2);
		if(v1<v2) up=m2;
		else lo=m1;
	}
	printf("%.7Lf\n",check(lo));

	return 0;
}