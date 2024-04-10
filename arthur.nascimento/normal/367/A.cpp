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

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
 
using namespace std;

char str[100100];

int v[3][100100];

main(){

	int n;
	

	scanf(" %s",str);

	n = strlen(str);
	int m;
	scanf("%d",&m);

	if(str[0] == 'x')
		v[0][0]=1;
	else if(str[0]=='y')
		v[1][0] = 1;
	else
		v[2][0] = 1;

	for(int i=1;i<n;i++){

		v[0][i] = v[0][i-1];
		v[1][i] = v[1][i-1];
		v[2][i] = v[2][i-1];

		if(str[i] == 'x')
		v[0][i]++;
		else if(str[i]=='y')
		v[1][i]++;
		else
		v[2][i]++;

	}

	for(int i=0;i<m;i++){

			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;

			if(b-a <= 1){
				printf("YES\n");
				continue;
				}

			int qx = v[0][b] - (a?v[0][a-1]:0);
			int qy = v[1][b] - (a?v[1][a-1]:0);
			int qz = v[2][b] - (a?v[2][a-1]:0);

			debug("%d %d %d\n",qx,qy,qz);
			printf("%s\n",max3(qx,qy,qz) - min3(qx,qy,qz) <= 1 ? "YES" : "NO");


}
		}