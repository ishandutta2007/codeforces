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

char str[4040];
int V[4040];

map<int,int> mp;

main(){

		int a;
		scanf("%d",&a);

		scanf(" %s",str);

		int size = strlen(str);

		for(int i=0;i<size;i++)
			V[i] = str[i] - '0';

		for(int i=0;i<size;i++){
			int sum = 0;
			for(int j=i;j<size;j++){
				
				sum += V[j];
				//debug("add %d\n",sum);
				mp[sum]++;
				}	
			}		

		long long ans = 0;

		for(int i=0;i<size;i++){
			int sum = 0;
			for(int j=i;j<size;j++){
				sum += V[j];

				if(sum != 0)
					if(a % sum == 0)
						ans += mp[a/sum];

				if(sum == 0 && a == 0)
					ans += (size*(size+1))/2;
				
				}	
			}	

		printf("%I64d\n",ans);

	}