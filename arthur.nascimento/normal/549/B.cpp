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

char str[110];

using namespace std;

int a[110];
int b[110];

int mrk[110];

int v[110][110];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++) {
			scanf(" %s",str);
			for(int j=0;j<n;j++) v[i][j] = (str[j]=='1') ? 1 : 0;
		}
		
		for(int i=0;i<n;i++)
			scanf("%d",a+i);

		for(int t=0;t<2*n;t++){

			for(int i=0;i<n;i++) if(a[i] == b[i]){
				mrk[i] = 1;
				for(int j=0;j<n;j++) if(v[i][j]) b[j]++;
				break;
			}

		}


		for(int i=0;i<n;i++) if(a[i] == b[i]){
			printf("-1\n");
			return 0;
		}

		int ans = 0;
		for(int i=0;i<n;i++) if(mrk[i])ans++;
		printf("%d\n",ans);
		for(int i=0;i<n;i++) if(mrk[i])
			printf("%d ",i+1);
		printf("\n");
}