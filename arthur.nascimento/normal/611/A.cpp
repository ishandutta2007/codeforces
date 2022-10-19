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
#define maxn 260

using namespace std;

int m[] = {31,29,31,30,31,30,31,31,30,31,30,31};

main(){
	int n;
	scanf("%d",&n);
	char str[20];
	scanf(" %s",str);
	scanf(" %s",str);
	if(str[0] == 'm'){
		int ans = 0;
		for(int i=0;i<12;i++)
			if(m[i] >= n)
				ans++;
		printf("%d\n",ans);
	}
	else {
		int ans = 366/7;
		if(n == 5 || n == 6) ans++;
		printf("%d\n",ans);
	}
}