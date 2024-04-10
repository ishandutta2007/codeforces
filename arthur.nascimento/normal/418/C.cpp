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

#define inf (999999999)
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

using namespace std;

int a[110];
int b[110];

int build(int n,int *v){
	if(n == 1)
		v[0] = 1;
	else if(n == 2)
		v[0] = 3, v[1] = 4;
	else {
		for(int i=0;i<n;i++)
			v[i] = 1;
		if(n%2 == 1)
			v[n-2] = 2;
		int sum = n-1;
		if(n%2 == 1)
			sum += 3;
		v[n-1] = (sum-1)/2;
	}
}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		build(n,a);
		build(m,b);

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				printf("%d ",a[i]*b[j]);
			printf("\n");
		}

}