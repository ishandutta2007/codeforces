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

int a[100100];
int b[100100];

int dp[300][100100];

vector<int> pos[100100];

main(){

		int n,m,s,e;
		scanf("%d%d%d%d",&n,&m,&s,&e);

		for(int i=0;i<n;i++)
			scanf("%d",a+i);

		for(int i=0;i<m;i++){
			scanf("%d",b+i);
			pos[b[i]].push_back(i);
		}

		int ans = 0;

		for(int i=1;i<=300;i++){
			int l = (i == 1) ? 0 : 999999;
			for(int j=0;j<n;j++){

				if(l == 999999)
					dp[i][j] = 999999;
				else {
					if(pos[a[j]].size() == 0 || pos[a[j]][pos[a[j]].size()-1] < l)
						dp[i][j] = 999999;
					else
						dp[i][j] = *lower_bound(pos[a[j]].begin(), pos[a[j]].end(), l) + 1;
					
					}

				l = min(l,dp[i-1][j]);

				debug("dp[%d][%d] = %d\n",i,j,dp[i][j]);

				if(s >= i*e + j + 1 + dp[i][j])
					ans = i;
				
			}

		}

		printf("%d\n",ans);

	}