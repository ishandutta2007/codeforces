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
#define maxn 100100
using namespace std;
typedef long long ll;

int get(int n,int k){
	if(k%2 == 0){
		if(n <= 2)
			return n;
		if(n%2 == 1)
			return 0;
		return 1;
	}
	if(n <= 3)
		return n%2;
	if(n == 4)
		return 2;
	if(n%2 == 1)
		return 0;
	if(get(n/2,k) == 1)
		return 2;
	return 1;
}

main(){

	int n,k;
	scanf("%d%d",&n,&k);

	int ans = 0;

	while(n--){
		int u;
		scanf("%d",&u);
		ans ^= get(u,k);
	}

	printf("%s\n",ans ? "Kevin" : "Nicky");

}