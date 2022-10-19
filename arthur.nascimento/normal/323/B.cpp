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
#define maxn 1010
#define mod 1000000007

using namespace std;

int v[maxn][maxn];

main(){

		int n;
		scanf("%d",&n);

		if(n == 4){
			printf("-1\n");
			return 0;
		}

		if(n%2 == 0){

			v[0][1] = v[0][2] = v[1][2] = v[2][3] = v[2][4] = v[2][5] = v[1][5] = v[5][0] = v[4][0] = v[3][1] = v[5][4] = v[4][3] = v[3][5] = 1;

			for(int i=6;i<n;i+=2){

				for(int j=0;j<i;j++)
					v[j][i] = v[i+1][j] = 1;

			}

		}

		else 
			for(int i=1;i<n;i+=2)
				for(int j=0;j<i;j++)
					v[j][i] = v[i+1][j] = 1;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i != j && v[i][j]+v[j][i] == 0) v[i][j] = 1;


		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",v[i][j]);
			printf("\n");
		}

}