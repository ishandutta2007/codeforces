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

int v[2002000];
int sum[2002000];

int get(int a,int b){
	return sum[b]-(a?sum[a-1]:0);
}

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		int b = 1<<30;

		for(int i=0;i<n;i++){
			int y;
			scanf("%d",&y);
			b = min(b,y);
			v[y]++;
		}

		sum[0] = v[0];

		for(int i=1;i<=2000000;i++)
			sum[i] = sum[i-1] + v[i];

		int ans = 1;
		
		for(int i=2;i<=b;i++){

			int qnt = 0;
			
			for(int j=1;i*j<=1000000;j++)
				qnt += get(i*j,min(i*j+k,i*(j+1)-1));

			if(qnt == n)
				ans = i;

		}

		printf("%d\n",ans);

	}