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
#define mod 1000000007
#define maxn 2002000

using namespace std;

main(){

		long long m,h1,a1,x1,y1,h2,a2,x2,y2;
		cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

		long long f1 = 0;
		int imp = 0;
		
		while(h1 != a1){
			f1++;
			h1 = (x1*h1+y1)%m;
			if(f1 > maxn) { imp = 1; break;}
		}

		long long f2 = 0;

		while(h2 != a2){
			f2++;
			h2 = (x2*h2+y2)%m;
			if(f2 > maxn){ imp = 1; break;}
		}

		long long t1 = 0, t2 = 0;

		while(1){
			t1++;
			h1 = (x1*h1+y1)%m;
			if(h1 == a1) break;
			if(t1 > maxn) { t1 = -1; break;}
		}

		while(1){
			t2++;
			h2 = (x2*h2+y2)%m;
			if(h2 == a2) break;
			if(t2 > maxn) { t2 = -1; break;}
		}

		if(imp){
			printf("-1\n");
			return 0;
		}

		if(f1 == f2){
			printf("%I64d\n",f1);
			return 0;
		}

		if(t1 == -1 && t2 == -1){
			printf("-1\n");
			return 0;
		}

		if(t1 == -1){
			if(f1 > f2 && ( (f1-f2)%t2 == 0))
				printf("%I64d\n",f1);
			else
				printf("-1\n");
			return 0;
		}

		if(t2 == -1){
			if(f2 > f1 && ( (f2-f1)%t1 == 0))
				printf("%I64d\n",f2);
			else
				printf("-1\n");
			return 0;
		}

		if(f1 > f2){
			swap(f1,f2);
			swap(t1,t2);
		}

		int u = 0;
		long long t;
		for(t = f2; ((t-f1)%t1) != 0; t += t2){
			u++;
			if(u > maxn) {imp = 1; break; }
		}

		if(imp)
			printf("-1\n");
		else
			printf("%I64d\n",t);

}