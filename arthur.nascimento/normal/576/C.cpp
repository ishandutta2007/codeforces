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

struct point {
	int x,y;
	int idx;
	int block;
	bool operator<(point a)const{
		if(block != a.block)
			return block < a.block;
		if(block%2 == 0)
			return x < a.x;
		else
			return x > a.x;
	}
}

p[1001000];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].idx = i;
			p[i].block = p[i].y / 1000;
	 	}

	 	sort(p,p+n);

	 	for(int i=0;i<n;i++)
	 		printf("%d ",p[i].idx+1);

}