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

set<int> S;

int last[300300];
char str[300300];
long long ans[30];

main(){

		scanf("%s",str);

		int n = strlen(str);

		memset(last,-1,sizeof(last));

		for(int i=0;i<n;i++){

			S.erase(last[str[i]]);
			S.insert(-1);
			last[str[i]] = i;


			int k = 1;
			int u = i;

			set<int> :: iterator it;
			for(it = --S.end(); it != S.begin(); it--){
				ans[k++] += u-*it;
				u = *it;
				}

			ans[k] += u+1;
			
			S.insert(i);
			
			}

		printf("%d\n",S.size()-1);

		for(int i=1;i<=S.size()-1;i++)
			printf("%I64d\n",ans[i]);

		}