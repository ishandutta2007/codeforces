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
#define maxn 200200
#define mod 1000000007

typedef long long ll;
using namespace std;

char str[maxn];
int ps[maxn];

int get(int a,int b){
	int r = ps[b];
	if(a) r -= ps[a-1];
	return r;

}
main(){

	int n,k;
	scanf("%d%d",&n,&k);

	scanf(" %s",str);

	for(int i=0;i<n;i++){
		if(str[i] == '0') str[i] = '1';
		else str[i] = '0';
	}

	ps[0] = str[0]-'0';

	for(int i=1;i<n;i++)
		ps[i] = str[i]-'0' + ps[i-1];

	int low = 0, up = n-1;

	while(low != up){
		int mid = (low+up)/2;

		int ok = 0;
		for(int i=0;i<n;i++)
			if(str[i] == '1'){
				int x = max(0,i-mid);
				int y = min(n-1,i+mid);
				if(get(x,y) > k)
					ok = 1;
			}
		if(ok)
			up = mid;
		else
			low = mid+1;
	}

	printf("%d\n",low);

}