#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define maxn 500500
#define mod 1000000007

using namespace std;

int v[110][110];

char str[110];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++){
			scanf(" %s",str);
			for(int j=0;j<m;j++){
				if(str[j] == 'B') v[i][j] = 1;
				else v[i][j] = -1;
			}
		}

		int ans = 0;

		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--){

				if(v[i][j] == 0) continue;
				int u = v[i][j];

				for(int a=0;a<=i;a++)for(int b=0;b<=j;b++) v[a][b] -= u;

				ans++;

			}

		cout << ans << endl;

}