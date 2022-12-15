#include <stdio.h>
#include <cmath>
#include <algorithm>

const double pi=acos(-1);
struct vec {
	double x,y;
	vec() {}
	vec(double x, double y):x(x),y(y) {}
	vec operator-(const vec &rhs) const {
		return vec(x-rhs.x, y-rhs.y);
	}
	double product(const vec &rhs) const {
		return x*rhs.y-y*rhs.x;
	}
	double dist() const {
		return sqrt(x*x+y*y);
	}
};

int n;
vec arr[1000];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%lf %lf", &arr[i].x,&arr[i].y);
	}
	double min=2e9;
	for(int i=0;i<n;i++) {
		int i1=(i-1+n)%n, i2=(i+1)%n;

		vec ov=arr[i]-arr[i1], sv=arr[i2]-arr[i1];
		double s=sv.product(ov)/(ov.dist()*sv.dist());
		min=std::min(min, ov.dist()*s);
	}
	printf("%.9lf\n",min/2.0);
	return 0;
}