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
#define pff pair<long double,long double>
#define eps 1e-6
 
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

		int n,k;
		scanf("%d%d",&n,&k);


		int foi = 0;
		int low = 1;
		int up = n;
		while(foi < n){
			printf("%d ",low);
			foi++;
			if(low != 1) k--;
			if(k == 1){
				for(int i=low+1;i<=up;i++)printf("%d ",i), foi++;
				continue;
			}
			if(low != up) printf("%d ",up);
			//debug("! %d %d\n",low,up);
			k--;
			foi++;

			if(k == 1){
				for(int i=up-1;i>low;i--)printf("%d ",i), foi++;
				continue;
			}

			low++;
			up--;

		}

		printf("\n");

}