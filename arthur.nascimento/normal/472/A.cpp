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

int comp[1001000];

main(){

		for(int i=2;i<1000000;i++){
			int ok = 0;
			for(int j=2;j*j<=i && ok == 0;j++)
				if(i%j == 0) ok = 1;
			if(ok) comp[i] = 1;

		}

		int n;
		scanf("%d",&n);

		for(int i=2;i<=n;i++){
			if(comp[i] && comp[n-i]){
				printf("%d %d\n",i,n-i);
				return 0;
			}
		}

}