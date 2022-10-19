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

#define inf (9999999999999999LL)
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
#define maxn 100100

using namespace std;

main(){

		int xp,yp,xv,yv;
		cin >> xp >> yp >> xv >> yv;

		int dp = xp + yp;
		int dv = max(xv,yv);

		if(dp <= dv){
			printf("Polycarp\n");
			return 0;
		}

		if(xv + yv <= dp){
			printf("Vasiliy\n");
			return 0;
		}

		int t = 0;
		while(xv > xp || yv > yp){
			xv--;
			yv--;
			t++;
		}

		if(abs(xp-xv) + abs(yp-yv) <= t){
			printf("Polycarp\n");
			return 0;
		}

		printf("Vasiliy\n");}