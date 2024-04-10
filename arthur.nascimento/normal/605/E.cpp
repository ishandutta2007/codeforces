#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1010

using namespace std;

double p[maxn][maxn];

double best[maxn];
double P[maxn];
double E[maxn];

int foi[maxn];

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int u;
			scanf("%d",&u);
			p[i][j] = (double)u/100;
	}

	foi[n-1] = 1;

	for(int i=0;i<n-1;i++){
		P[i] = p[i][n-1];
		E[i] = 0;
		best[i] = 1.0/P[i];
		if(P[i] < eps)
			best[i] = 1e15;
		debug("best[%d] = %.4lf %.4lf\n",i,best[i],P[i]);
	}

	while(!foi[0]){

		int v = -1;
		for(int i=0;i<n;i++)
			if(!foi[i])
				if(v == -1 || best[i] < best[v])
					v = i;
					
		foi[v] = 1;
		debug("foi %d %.4lf\n",v,best[v]);

		for(int i=0;i<n;i++)
			if(!foi[i]){

				double p2 = (1.0-P[i]) * p[i][v];
				E[i] = (E[i] * P[i] + best[v] * p2) / (P[i] + p2);
				if(P[i] + p2 < eps)
					E[i] = 1e15;
				P[i] += p2;
				best[i] = min(best[i], E[i] + 1.0/P[i]);
				if(P[i] < eps)
					best[i] = 1e15;

			}

	}

	printf("%.10lf\n",best[0]);

}