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

int v[52][52];

int ans[52];

int ok[52];

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&v[i][j]);

	for(int i=1;i<=n;i++){

		int r;
		for(int j=0;j<n;j++){
			int foi = 1;

			for(int l=0;l<n;l++)
				if(v[j][l] > i || ok[j])
					foi = 0;

			if(foi)
				r = j;

		}

		ans[r] = i;
		ok[r] = 1;

	}

	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);

}