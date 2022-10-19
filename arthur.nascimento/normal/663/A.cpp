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
#define maxn 400400

typedef long long ll;
using namespace std;

main(){

	char ch = 1;
	vector<int> v;
	v.pb(1);

	while(ch != '='){
		scanf(" %c",&ch);
		if(ch == '?') continue;
		if(ch == '+') v.pb(1);
		if(ch == '-') v.pb(-1);
	}

	int n;
	scanf("%d",&n);

	int men = 0, mai = 0;

	for(int i=0;i<v.size();i++){
		if(v[i] == 1)
			men++, mai += n;
		else
			men -= n, mai--;
	}

	debug("%d %d\n",men,mai);
	if(men > n || mai < n){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");

	for(int i=0;i<v.size();i++){

		if(i){
			if(v[i] == 1)
				printf(" + ");
			else
				printf(" - ");
		}

		int dif = mai - n;
		int u = min(dif, n-1);
		mai -= u;
		if(v[i] == 1)
			printf("%d",n-u);
		else
			printf("%d",1+u);

	}

	printf(" = %d\n",n);

}