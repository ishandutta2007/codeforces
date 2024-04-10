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
#define maxn 300300
#define max3(a,b,c) max(max(a,b),c)

typedef long long ll;
using namespace std;

int M[110][110];

int val[110*110];

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	int u = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			M[i][j] = u++;

	int q;
	scanf("%d",&q);

	for(int i=0;i<q;i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int r;
			scanf("%d",&r), r--;
			for(int j=0;j<m-1;j++)
				swap(M[r][j],M[r][j+1]);
		}
		if(t == 2){
			int c;
			scanf("%d",&c), c--;
			for(int j=0;j<n-1;j++)
				swap(M[j][c],M[j+1][c]);
		}
		if(t == 3){
			int x,y,p;
			scanf("%d%d%d",&x,&y,&p), x--, y--;
			val[M[x][y]] = p;
		}
	}

	u = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",val[u]);
			u++;
		}
		printf("\n");
	}

}