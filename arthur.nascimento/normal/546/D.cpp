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
#define mod 1000000007
#define maxn 5000000

using namespace std;

int sieve[maxn+100];
int f[maxn+100];
long long sum[maxn+100];

main(){

		f[1] = 0;
		for(int i=2;i<=maxn;i++){

			if(sieve[i]){
				f[i] = 1 + f[i/sieve[i]];
				continue;
			}

			f[i] = 1;
			sieve[i] = i;

			for(int j=i;j<=maxn;j+=i)
				sieve[j] = i;

		}

		sum[0] = 0;
		sum[1] = 0;
		for(int i=2;i<=maxn;i++)
			sum[i] = sum[i-1] + f[i];

		int t;
		scanf("%d",&t);

		while(t--){

			int a,b;
			scanf("%d%d",&b,&a);
			printf("%d\n",sum[b]-sum[a]);

		}

}