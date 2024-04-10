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
#define maxn 1001000
#define mod 1000000007

using namespace std;

struct point {
	long long x,y,cor;
	point(long long x=0,long long y=0,int cor=0): x(x), y(y), cor(cor) {}
	long long operator%(point p){
		return x*p.y - y*p.x;
	}
	point operator-(point p){
		return point(x-p.x,y-p.y);
	}
	bool operator<(point p)const{
		if(y*p.x == x*p.y)
			return x > p.x;
		return y*p.x < x*p.y; 
	}
}

p[2*maxn];

long long ccw(point a,point b,point c){
	return (b-a)%(c-a);
}

main(){

		int n,m,x,y;
		scanf("%d%d%d%d",&n,&m,&x,&y);

		int mx=0, my=0;

		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			mx = max(mx,a);
			my = max(my,b);
			p[i] = point(a,b,1);
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			mx = max(mx,a);
			my = max(my,b);
			p[n+i] = point(a,b,0);
		}

		p[n+m] = point(mx,0,2);
		p[n+m+1] = point(0,my,3);

		n += m + 2;

		sort(p,p+n);

		assert(p[0].cor == 2 && p[n-1].cor == 3);

		vector<point> hull;

		for(int i=0;i<n;i++){

			if(hull.size() && hull[hull.size()-1].x == p[i].x && hull[hull.size()-1].y == p[i].y){
				hull[hull.size()-1].cor |= p[i].cor;
				continue;
			}

			hull.pb(p[i]);

			while(hull.size() >= 3){
				int t = hull.size();
				if(ccw(hull[t-3],hull[t-2],hull[t-1]) < 0){
					swap(hull[t-2],hull[t-1]);
					hull.pop_back();
				}
				else break;
			}

		}

		for(int i=0;i<hull.size();i++)
			if(hull[i].cor == 1){
				printf("Max\n");
				return 0;
			}

		printf("Min\n");

}