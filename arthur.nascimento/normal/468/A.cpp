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
#define pll pair<unsigned long long,unsigned long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

main(){

		int n;
		scanf("%d",&n);

		if(n <= 3){
			printf("NO\n");
			return 0;
		}
		printf("YES\n");

		int q1 = 0;
		while(n > 5){

			printf("%d - %d = 1\n",n,n-1);
			q1++;
			n -= 2;

		}

		if(n == 4)
			printf("1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
		if(n == 5)
			printf("5 - 2 = 3\n3 - 1 = 2\n2 * 3 = 6\n4 * 6 = 24\n");

		while(q1--)
			printf("1 * 24 = 24\n");

}