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

int blockx[1010];
int blocky[1010];

int bad[10][10];

int foi[10];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			blockx[x] = blocky[y] = 1;
		}

		int ans = 0;

		for(int i=1;i<=n/2;i++){

			if(i == n/2 && n%2 == 0)
				break;

			int v = 8;

			memset(bad,0,sizeof(bad));

			int i_ = n - i - 1;

			bad[1][4] = bad[0][5] = bad[2][7] = bad[3][6] = 1;

			bad[1][2] = bad[3][4] = bad[5][6] = bad[7][0] = 1;

			bad[1][6] = bad[0][3] = bad[4][7] = bad[2][5] = 1;

			if(blockx[i])
				bad[1][1] = bad[4][4] = 1;
			if(blockx[i_])
				bad[0][0] = bad[5][5] = 1;
			if(blocky[i])
				bad[2][2] = bad[7][7] = 1;
			if(blocky[i_])
				bad[3][3] = bad[6][6] = 1;

			if(i == n/2 && n%2 == 1){

				v = 4;
				memset(bad,0,sizeof(bad));

				bad[0][2] = bad[1][3] = 1;

				bad[0][1] = bad[0][3] = bad[2][1] = bad[2][3] = 1;

				if(blockx[i])
					bad[0][0] = bad[2][2] = 1;
				if(blocky[i])
					bad[1][1] = bad[3][3] = 1;
					
				}

			int add = 0;

			for(int j=0;j<1<<v;j++){

				int qnt = 0;
				int ok = 1;
				memset(foi,0,sizeof(foi));

				for(int k=0;k<v;k++)
					if(j & (1<<k))
						foi[k]++, qnt++;

				for(int k=0;k<v;k++)
					for(int l=0;l<v;l++)
						if(foi[k] && foi[l])
							if(bad[k][l] || bad[l][k])
								ok = 0;

				if(ok && qnt == 3 && add != 3)	
					for(int k=0;k<v;k++)
						if(foi[k])
							debug("+ %d ",k);
				


				if(ok)
					add = max(add, qnt);

				

				}

			ans += add;

		}

		printf("%d\n",ans);
			
	}