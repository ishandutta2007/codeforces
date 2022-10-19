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
#define maxn 200200
#define mod 1000000007

using namespace std;

char A[maxn];
char B[maxn];

int eq(char* a, char* b,int n){

	if(n%2 == 1){
		int ok = 1;
		for(int i=0;i<n && ok;i++)
			if(a[i] != b[i]) ok = 0;
		return ok;
	}

	if(eq(a,b,n/2) && eq(a+n/2,b+n/2,n/2)) return 1;
	if(eq(a+n/2,b,n/2) && eq(a,b+n/2,n/2)) return 1;
	return 0;

}

main(){

		scanf(" %s %s",A,B);

		if(eq(A,B,strlen(A)))
			printf("YES\n");
		else
			printf("NO\n");

}