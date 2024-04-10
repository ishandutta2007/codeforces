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

#define inf (1LL<<60)
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
#define mod 1000000009LL
#define maxn 300300

#define X second.first
#define Y second.second

using namespace std;

struct point {
	double x,y;
	bool operator<(point comp)const{
		return x < comp.x;}
}

p[100100];

double xmin[2][100100];
double xmax[2][100100];

main(){

		int n;
		scanf("%d",&n);
		
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
			double a = p[i].x * sqrt(2)/2 - p[i].y * sqrt(2)/2;
			p[i].y = p[i].x * sqrt(2)/2 + p[i].y * sqrt(2)/2;
			p[i].x = a; 
		}

		sort(p,p+n);

		xmin[0][0] = xmax[0][0] = p[0].y;

		for(int i=1;i<n;i++)
			xmin[0][i] = min(xmin[0][i-1],p[i].y),
			xmax[0][i] = max(xmax[0][i-1],p[i].y);

		xmin[1][n-1] = xmax[1][n-1] = p[n-1].y;

		for(int i=n-2;i>=0;i--)
			xmin[1][i] = min(xmin[1][i+1],p[i].y),
			xmax[1][i] = max(xmax[1][i+1],p[i].y);

		double low = 0, up = 4000000000.0f;

		for(int i=0;i<80;i++){

			double mid = (low+up)/2;

			int ptr = 0;
			int ok = 0;

			for(int j=0;j<n;j++){

				while(ptr+1 < n && p[ptr+1].x <= p[j].x + 2*mid) ptr++;

				double a,b;
				if(j == 0 && ptr == n-1){ok=1;continue;}

				debug("j = %d ptr = %d\n",j,ptr);

				if(j) {a = xmax[0][j-1]; if(ptr!=n-1) a = max(a,xmax[1][ptr+1]);
						b = xmin[0][j-1]; if(ptr!=n-1) b = min(b,xmin[1][ptr+1]);}
				else { a = xmax[1][ptr+1]; b = xmin[1][ptr+1];}

				if(a-b <= 2*mid) ok = 1;

			}

			if(ok)
				up = mid;
			else
				low = mid;

		}

		printf("%.8lf\n",low*sqrt(2));

}