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

#define sq(x) ((x)*(x))
 
using namespace std;

main(){
	
		long double x1,x2,y1,y2,vm,t,vx1,vx2,vy1,vy2;
		cin >> x1 >> y1 >> x2 >> y2 >> vm >> t >> vx1 >> vy1 >> vx2 >> vy2;
		
		long double low = 0, up = 1000000000;
		
		for(int i=0;i<10000;i++){
			
			long double mid = (low+up)/2;
			
			long double xf = x1, yf = y1;
			long double z = 0;
			xf += vx1 * min(t,mid);
			xf += vx2 * max(z,mid-t);
			yf += vy1 * min(t,mid);
			yf += vy2 * max(z,mid-t);
			
			long double dist = sq(xf-x2) + sq(yf-y2);
			dist = sqrt(dist);
			
			if(vm * mid >= dist)
				up = mid;
			else
				low = mid;
		
		}
		
		printf("%.8lf\n",(double)low);
		
}