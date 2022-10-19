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
#define maxn 1001000
#define max3(a,b,c) max(max(a,b),c)

typedef long long ll;
using namespace std;

int ans[maxn];

main(){

	int p1 = 0, p2 = 1;

	int n,q;
	scanf("%d%d",&n,&q);

	while(q--){

		int t;
		scanf("%d",&t);

		if(t == 1){
			int x;
			scanf("%d",&x);
			p1 = (p1+x+n)%n;
			p2 = (p2+x+n)%n;
		}
		else {
			if(p1%2 == 0)p1++;
			else p1--;
			if(p2%2 == 0)p2++;
			else p2--;
		}

	}

	ans[p1] = 1;
	for(int i=(p1+2)%n, u=3; i != p1; i = (i+2)%n, u += 2)
		ans[i] = u;
	ans[p2] = 2;
	for(int i=(p2+2)%n, u=4; i != p2; i = (i+2)%n, u += 2)
		ans[i] = u;

	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);

}