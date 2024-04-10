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
#define maxn 100100
#define mod 1000000007

using namespace std;

long long t[55];

main(){

		t[0] = 1;
		t[1] = 1;
		t[2] = 2;

		for(int i=3;i<=50;i++)
			t[i] = t[i-1] + t[i-2];

		long long n,k;
		cin >> n >> k;

		int N = n;
		for(int i=0;i<n;){

			if(t[N-1] < k){
				k -= t[N-1];
				printf("%d %d ",i+2,i+1);
				N -= 2;
				i += 2;
				continue;
			}
			printf("%d ",i+1);
			N--;
			i++;
		}

		printf("\n");
}