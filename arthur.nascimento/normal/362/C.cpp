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

int m[5050][5050];
int v[5050];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);


		for(int i=0;i<n;i++){
			m[i][0] = (v[0] > v[i]) ? 1 : 0;
			for(int j=1;j<n;j++)
				m[i][j] = m[i][j-1] + ((v[j] > v[i]) ? 1 : 0);
			}

		int inv = 0;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(v[i] > v[j])
					inv++;


		int ans = 0,
		best = inv;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){

				int k = 2*(m[i][j] - (i?m[i][i-1]:0)) - (j-i);
				k -= 2*(m[j][j] - (i?m[j][i-1]:0)) - (j-i);
				if(v[i] < v[j])
					k--;
				else k++;
				debug("%d %d %d\n",i,j,k);
				k += inv;

				
				if(k == best)
					ans++;
				if(k < best){
						ans = 1;
						best = k;
						}

			}

		printf("%d %d\n",best,ans);

	}