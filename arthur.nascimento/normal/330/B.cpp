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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int grau[1010];

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){

	int a,b;
	scanf("%d%d",&a,&b);

	grau[a-1]++;
	grau[b-1]++;

	}

	printf("%d\n",n-1);

	for(int i=0;i<n;i++)
		if(grau[i] == 0){
			for(int j=0;j<n;j++)
				if(i != j)
					printf("%d %d\n",i+1,j+1);
			return 0;
			}
			}