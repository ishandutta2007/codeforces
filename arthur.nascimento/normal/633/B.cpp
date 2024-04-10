#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 3001000

typedef long long ll;
using namespace std;

int f[maxn];

main(){

	for(int i=1;i<maxn;i++){

		int u = 5;
		while(i/u){
			f[i] += i/u;
			u *= 5;
		}

	}

	int a;
	scanf("%d",&a);

	int ans = 0;

	for(int i=1;i<maxn;i++)
		if(f[i] == a)
			ans++;

	printf("%d\n",ans);

	for(int i=1;i<maxn;i++)
		if(f[i] == a)
			printf("%d ",i);
			printf("\n");

	}