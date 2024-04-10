#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define maxn 100100
#define mod 1000000007

using namespace std;

struct point {

	long long x,y;
	point(long long x=0,long long y=0): x(x), y(y) {}
	point operator-(point p){
		return point(x-p.x,y-p.y);
	}
	long long operator%(point p){
		return x*p.y - y*p.x;
	}

}

v[maxn];

long double ccw(point a,point b,point c){
	return (b-a)%(c-a);
}

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

int calc(point a,point b){
	return gcd((int)(abs(a.x-b.x)+eps),(int)(abs(a.y-b.y)+eps));
}

main(){

		long long n;
		scanf("%I64d",&n);

		for(int i=0;i<n;i++)
			scanf("%I64d%I64d",&v[i].x,&v[i].y);

		long double eAc = 0, eB = 0, area = 0;

		for(int i=1;i<n-1;i++)
			area += abs(ccw(v[0],v[i],v[i+1]))/2;

		debug("area %lf\n",(double)area);

		for(int i=0;i<n;i++){
		
			long double p = 0.25;
			long double cur = 0;

			for(int j=1;j<min(40LL,n);j++){

				debug("i %d j %d\n",i,j);
				eAc += p * cur;
				eB += p * calc(v[i],v[(i+j)%n]);
				debug("eAc + %lf eB + %lf\n",(double)(p * cur),(double)(p * calc(v[i],v[(i+j)%n])));
				cur += abs(ccw(v[i],v[(i+j)%n],v[(i+j+1)%n]))/2;
				p /= 2;

			}

		}


		long double u = 1;
		for(int i=0;i<n;i++) u /= 2;

		eAc -= area*u*n*(n-1)/2;
		
		if(n < 200)
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++){
					eB -= u * (calc(v[i],v[j])-1);
					eB -= u * (calc(v[i],v[j])+1);
					debug("i %d j %d eB - %lf\n",i,j,(double)(u * (calc(v[i],v[j])-1)));
				}

		debug("eA %lf eB %lf\n",(double)eAc,(double)eB);
	
		long double y = 1 - u - u*n - u*(n*n-n)/2;

		eAc /= y;
		eB /= y;

		long double ans = (area - eAc - eB/2 + 1);
		
		printf("%.12lf\n",(double)ans);

}