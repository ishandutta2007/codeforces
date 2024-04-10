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
#define mod 1000000007
#define maxn 600600
using namespace std;
typedef long long ll;

int ans[100100];

main(){

	int n;
	scanf("%d",&n);

	int t = 0;

	while(n--){
		ans[t] = 1;
		t++;
		while(t >= 2 && ans[t-1] == ans[t-2])
			ans[t-2]++ , t--;
	}

	for(int i=0;i<t;i++)
		printf("%d ",ans[i]);

	printf("\n");

}