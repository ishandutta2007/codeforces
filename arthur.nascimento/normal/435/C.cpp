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
#define eps 1e-12
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int M[2020][2020];

int v[1010];

main(){

		int x0 = 0;
		int y0 = 1010;
		int x=x0, y=y0;

		int n;
		scanf("%d",&n);	

		int up = y0, low = y0;	

		for(int i=0;i<n;i++)
			scanf("%d",v+i);		

		for(int i=0;i<n;i++){

			for(int j=0;j<v[i];j++)
				M[x][y] = '/', x++, y++;
			y--;

			up = max(up,y);

			i++;
		
			if(i == n)continue;

			for(int j=0;j<v[i];j++)
				M[x][y] = '\\', x++, y--;
			y++;

			low = min(low,y);

		}

		for(int i=up;i>=low;i--){
			for(int j=0;j<x;j++)
				printf("%c",M[j][i] ? M[j][i] : ' ');
			printf("\n");
		}


	}