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
#define maxn 220

using namespace std;

queue<int> A,B;

main(){

		int n;
		scanf("%d",&n);

		int a;
		scanf("%d",&a);
		for(int i=0;i<a;i++){
			int u;
			scanf("%d",&u);
			A.push(u);
		}
		int b;
		scanf("%d",&b);
		for(int i=0;i<b;i++){
			int u;
			scanf("%d",&u);
			B.push(u);
		}

		int ans = 0;

		while(1){

			ans++;

			int x = A.front();
			A.pop();
			int y = B.front();
			B.pop();
			if(x > y){
				A.push(y);
				A.push(x);
			}
			else{
				B.push(x);
				B.push(y);
			}

			if(A.size() == 0){
				printf("%d 2\n",ans);
				return 0;
			}
			if(B.size() == 0){
				printf("%d 1\n",ans);
				return 0;
			}
			if(clock() > 1.9 * CLOCKS_PER_SEC){
				printf("-1\n");
				return 0;
			}

		}

}