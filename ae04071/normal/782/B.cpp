#include <stdio.h>
#include <algorithm>
#include <utility>
int n;
std::pair<double, double> arr[60000];

double abs(double a) {
	if(a<0) return -a;
	else return a;
}
double Check(double pos) {
	double max=0;
	for(int i=0;i<n;i++) {
		double tmp=abs(pos-arr[i].first)/arr[i].second;
		if(max<tmp) max=tmp;
	}
	return max;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",&arr[i].first);
	for(int i=0;i<n;i++)
		scanf("%lf",&arr[i].second);

	std::sort(arr, arr+n);
	double lo=arr[0].first, up=arr[n-1].first;

	for(int iter=0; iter<100;iter++) {
		double le=(2*lo+up)/3.0, ri=(lo+up*2)/3.0;
		double let=Check(le), rit=Check(ri);
		//printf("%lf %lf %lf %lf\n", le, ri, let, rit);
		if(let>rit)
			lo=le;
		else
			up=ri;
	}

	printf("%.8lf\n",Check(lo));

	return 0;
}