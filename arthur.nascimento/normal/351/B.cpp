#include <iostream>
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

#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int T[3030];

void update(int idx){
	while(idx < 3030){
		T[idx]++;
		idx += idx&-idx;}
	}

int query(int idx){
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;}
	return ret;}
	
main(){

		int n;
		scanf("%d",&n);

		int k = 0;

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			k += query(n) - query(a);
			update(a);
		}

		printf("%d.000000\n",2*k-k%2);

	}