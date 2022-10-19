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

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

typedef long long ll;
using namespace std;

bool pr(int a){
	for(int i=2;i<a;i++)
		if(a%i == 0)
			return 0;

	return 1;
}	

main(){

	int ans = 0;
	int u = 1;
	int foi = 0;
	int ii = 1;
	for(int i=2;i<=10;i++){
		printf("%d\n",i);
		foi++;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "yes"){
			u = i;
			ii = i;
			break;
		}
	}

	if(u != 1){
		foi++;
		printf("%d\n",u*u);
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "yes"){
			printf("composite\n");
			return 0;
		}
	}

		
	if(u == 1){
		printf("prime\n");
		return 0;
	}

	for(int j=ii+1;j<=100 && foi < 20;j++){
		if(!pr(j)) continue;
		printf("%d\n",j);
		foi++;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "yes"){
			printf("composite\n");
			return 0;
		}
	}

		printf("prime\n");
	
}