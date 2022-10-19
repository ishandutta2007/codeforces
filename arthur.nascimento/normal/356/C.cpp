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

int a[5];

main(){

	int n;
	int s = 0;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		int b;
		scanf("%d",&b);
		a[b]++;
		s += b;
	}

	int ans = 2*s;

	a[0] = n-a[1]-a[2]-a[3]-a[4];

	if(s < 3 || s == 5){
		printf("-1\n");
		return 0;
	}
	
	for(int q3=0;3*q3<=s;q3++)
		if((s-3*q3) % 4 == 0){

			int q4 = (s-3*q3)/4;

			if(q3 + q4 > n)
				continue;

			int b[5];
			
			for(int i=0;i<5;i++)
				b[i] = a[i];

			int s4 = q4;
			int s3 = q3;

			int sc = 0;

			for(int i=4;i>=0;i--){
				int t = min(b[i],s4);
				b[i] -= t;
				s4 -= t;
				sc += i*t;
			}

			for(int i=4;i>=0;i--){
				int t = min(b[i],s3);
				b[i] -= t;
				s3 -= t;
				sc += min(3,i)*t;
			}

			if(s-sc == 1)
				debug("%d %d\n",q3,q4);
			ans = min(ans,s-sc);

		}

	if(ans == 2*s)
		printf("-1\n");
	else
		printf("%d\n",ans);

}