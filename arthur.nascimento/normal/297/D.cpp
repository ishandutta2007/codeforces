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
#define maxn 2020
#define mod 1000000007

typedef long long ll;
using namespace std;

char v[maxn][maxn];

int ans[maxn][maxn]; 

main(){

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);

	for(int i=0;i<2*n-1;i++)
		scanf(" %s",v[i]);

	for(int j=0;j<m;j++){

		ans[0][j] = 1;

		for(int i=1;i<n;i++){
			ans[i][j] = ans[i-1][j];
			if(v[2*i-1][j] == 'N')
				ans[i][j] = 3 - ans[i-1][j];
		}

		if(j == 0)
			continue;

		int match = 0;

		for(int i=0;i<n;i++)
			if((ans[i][j] == ans[i][j-1]) ^ (v[2*i][j-1] == 'N'))
				match++;

		if(2*match < n)
			for(int i=0;i<n;i++)
				ans[i][j] = 3 - ans[i][j];

	}

	if(m > n){

		for(int i=0;i<n;i++){

			ans[i][0] = 1;

			for(int j=1;j<m;j++){
				ans[i][j] = ans[i][j-1];
				if(v[2*i][j-1] == 'N')
					ans[i][j] = 3 - ans[i][j];
			}

			if(i == 0)
				continue;

			int match = 0;

			for(int j=0;j<m;j++)
				if((ans[i][j] == ans[i-1][j]) ^ (v[2*i-1][j] == 'N'))
					match++;

			if(2*match < m)
				for(int j=0;j<m;j++)
					ans[i][j] = 3 - ans[i][j];

		}

	}

	if(k == 1){
		int cnt = 0, tot = 0;
		for(int i=0;i<2*n-1;i++){
			int t = strlen(v[i]);
			tot += t;
			for(int j=0;j<t;j++)
				if(v[i][j] == 'E')
					cnt++;
		}
		if(4*cnt >= 3*tot){
			printf("YES\n");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)
					printf("1 ");
				printf("\n");
			}
		}
		else
			printf("NO\n");
		return 0;
	}

	printf("YES\n");

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}

}