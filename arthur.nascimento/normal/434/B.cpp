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
#include <vector>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
 
using namespace std;


int T[2][1010][1010];
int v[1010][1010];

void update(int qual,int idx,int val,int rc){
	idx++;
	while(idx < 1010){
		T[qual][rc][idx] += val;
		idx += idx&-idx;
	}
}

int query(int qual,int idx,int rc){
	int ret=0;
	idx++;
	while(idx){
		ret += T[qual][rc][idx];
		idx -= idx&-idx;
	}
	return ret;
}

main(){

		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&v[i][j]);
				update(0,i,v[i][j],j);
				update(1,j,v[i][j],i);
			}

		while(q--){

			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			x--,y--;

			if(t == 1){
				update(0,x,v[x][y]?-1:1,y);
				update(1,y,v[x][y]?-1:1,x);
				v[x][y] = v[x][y] ? 0 : 1;
				continue;
			}

			int ans = 0;

			int down = 0, up = n-1;

			debug("a");
			for(int i=y;i<m;i++){
				while(query(0,up,i) - query(0,x-1,i) < up-x+1)
					up--;
				while(query(0,x,i) - query(0,down-1,i) < x-down+1)
					down++;	
				ans = max(ans, (up-down+1) * (i-y+1));
			}

			down = 0, up = n-1;
			debug("b");

			for(int i=y;i>=0;i--){
				while(query(0,up,i) - query(0,x-1,i) < up-x+1)
					up--;
				while(query(0,x,i) - query(0,down-1,i) < x-down+1)
					down++;	
				ans = max(ans, (up-down+1) * (y-i+1));
			}

			down = 0, up = m-1;
			debug("c");

			for(int i=x;i<n;i++){
				while(query(1,up,i) - query(1,y-1,i) < up-y+1)
					up--;
				while(query(1,y,i) - query(1,down-1,i) < y-down+1)
					down++;	
				ans = max(ans, (up-down+1) * (i-x+1));

			}

			down = 0, up = m-1;
			debug("d");

			for(int i=x;i>=0;i--){
				while(query(1,up,i) - query(1,y-1,i) < up-y+1)
					up--;
				while(query(1,y,i) - query(1,down-1,i) < y-down+1)
					down++;	
				ans = max(ans, (up-down+1) * (x-i+1));
			}

			debug("e");
			printf("%d\n",ans);

		}

}