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
#define maxn 200200
#define mod 1000000007

using namespace std;

long double v[110];
long double f[110];

main(){

		int n;
		scanf("%d",&n);

		if(n <= 4){
			printf("No solution\n");
			return 0;
		}

		for(int i=0;i<n;i++)
			v[i] = 500;

		srand(time(0));

		long double theta = (acos(-1)*(n-2))/n;

		while(1){
		
			for(int i=0;i<n;i++){

				int a = (i-1+n)%n;
				int b = (i+1)%n;

				long double r = (long double)(rand()%1200+800)/100;

				v[i] -= 2.0*r;
				v[a] -= r/cos(theta);
				v[b] -= r/cos(theta);

			}

			int ok = 1;
			for(int i=0;i<n;i++) f[i] = v[i];
			sort(f,f+n);
			for(int i=1;i<n;i++) if(f[i]-f[i-1] < .002) ok = 0;
			if(ok) break;

		}
			

		long double x=0, y=0;
		long double dx=1, dy=0;

		for(int i=0;i<n;i++){
			printf("%.8lf %.8lf\n",(double)x,(double)y);
			x += dx*v[i];
			y += dy*v[i];
			long double aux = dx;
			dx = -dx * cos(theta) - dy * sin(theta);
			dy = aux * sin(theta) - dy * cos(theta);
		}

		debug("%.8lf %.8lf\n",(double)x,(double)y);

}