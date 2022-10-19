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
#define maxn 550

using namespace std;

char M[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
int pa[maxn][maxn];
int pb[maxn][maxn];

int geta(int r,int x,int y){
	int s = pa[r][y];
	if(x)
		s -= pa[r][x-1];
	return s;
}
int getb(int r,int x,int y){
	int s = pb[r][y];
	if(x)
		s -= pb[r][x-1];
	return s;
}

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %c",&M[i][j]);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(i != n-1){
				if(M[i][j] == '.' && M[i+1][j] == '.')
					a[i][j] = 1;
			}
			if(j != m-1){
				if(M[i][j] == '.' && M[i][j+1] == '.')
					b[i][j] = 1;
			}
		}

	for(int i=0;i<n;i++){
		pa[i][0] = a[i][0];
		pb[i][0] = b[i][0];
		for(int j=1;j<m;j++)
			pa[i][j] = pa[i][j-1] + a[i][j], pb[i][j] = pb[i][j-1] + b[i][j];
	}
	
	int q;
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2), x1--, x2--, y1--, y2--;
		int ans = 0;
		for(int i=x1;i<=x2-1;i++)
			ans += geta(i,y1,y2);
		for(int i=x1;i<=x2;i++)
			ans += getb(i,y1,y2-1);
		printf("%d\n",ans);
	}

}