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

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;}

main(){

		int n,maior=0,mdc=0;

		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			maior = max(maior,a);
			mdc = gcd(a,mdc);}

		printf("%s\n",(((maior/mdc)-n) % 2) ? "Alice" : "Bob");

	}