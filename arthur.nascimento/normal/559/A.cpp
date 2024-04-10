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
#define maxn 110
#define mod 1000000007

using namespace std;

int v[10];

struct point {
	long double x,y;
	point(long double x=0, long double y=0): x(x), y(y) {}
	point operator-(point p){
		return point(x-p.x,y-p.y);
	}
	point operator+(point p){
		return point(x+p.x,y+p.y);
	}
	long double operator%(point p){
		return x*p.y-y*p.x;
	}
	point operator*(int t){
		return point(x*t,y*t);
	}
};

long double area(point a,point b,point c){
	return ((b-a)%(c-a))/2;
}

point u[10];

main(){

		for(int i=0;i<6;i++)
			scanf("%d",v+i);

		u[0] = point(0,0);
		point dir(1,0);

		long double th = acos(-1)/3;

		for(int i=1;i<6;i++){
			u[i] = u[i-1] + dir*v[i-1];
			dir = point(dir.x * cos(th) - dir.y * sin(th), dir.x * sin(th) + dir.y * cos(th));
			
		}

		long double A = 0;

		for(int i=1;i<5;i++)
			A += fabs(area(u[0],u[i],u[i+1]));

		A /= (sqrt(3)/4);
		A += eps;

		printf("%I64d\n",(long long)A);

}