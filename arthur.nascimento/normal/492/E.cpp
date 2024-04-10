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
#define maxn 100100

using namespace std;

int qnt[1001000];

int py[1001000];

main(){

		int n,m,dx,dy;
		scanf("%d%d%d%d",&n,&m,&dx,&dy);

		int x=0, y=0;
		for(int i=0;i<n;i++){
			py[x] = y;
			x = (x+dx)%n;
			y = (y+dy)%n;
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int sobe = (b+n-py[a])%n;
			qnt[sobe]++;
		}

		int best = 0;

		for(int i=1;i<n;i++)
			if(qnt[i] > qnt[best])
				best = i;

		printf("0 %d\n",best);

}