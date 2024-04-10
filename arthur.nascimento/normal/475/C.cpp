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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

char str[1010][1010];
char aux[1010][1010];
int ans = 999999;

int v[1010][1010];
int M[1010][1010];

void go(int n,int m){

	int x=n, y=m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) if(str[i][j] == 'X')
			if(i <= x && j <= y)
				x = i, y = j;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) if(str[i][j] == 'X')
			if((i<x) ^ (j<y))
				return;
				
	memset(M,0,sizeof(M));
	memset(v,0,sizeof(v));

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) if(str[i][j] == 'X')
			v[i][j] = 1;

	debug("xy = %d %d\n",x,y);

	int t = 1;
	while(y+t < m && v[x][y+t]) t++;

	debug("t = %d\n",t);

	int x0 = x;
	while(x+1 < n && v[x+1][y]) x++;
	for(int i=x0;i<=x;i++) for(int j=y;j<y+t;j++) M[i][j] = 1;

	int u = 1;
	debug("xy = %d %d\n",x,y);
	if(y+t == m || v[x][y+t] == 0) goto fim;		
	
	while(x-u >= 0 && v[x-u][y+t] == 1) u++;
	y += t-1;

	debug("u = %d\n",u);

	while(1){

		int X=x, Y=y;
		int y0 = y;
		while(y+1 < m && v[x-u+1][y+1]) y++;
		debug("xy = %d %d\n",x,y);
		for(int i=x-u+1;i<=x;i++) for(int j=y0;j<=y;j++) M[i][j] = 1;
		int x0 = x;
		while(x+1 < n && v[x+1][y-t+1]) x++;
		debug("xy = %d %d\n",x,y);
		for(int i=x0;i<=x;i++) for(int j=y-t+1;j<=y;j++) M[i][j] = 1;
		if(X==x && Y==y) break;
		
	}

	fim:
	int ok = 1;

	debug("M:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			debug("%c",M[i][j]?'X':'.');
		debug("\n");
	}
	
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j] != M[i][j]) ok = 0;
	if(ok)
		ans = min(ans,u*t);
	
}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf(" %s",str[i]);

		go(n,m);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				aux[j][i] = str[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				str[j][i] = aux[j][i];

		go(m,n);

		if(ans == 999999)
			printf("-1\n");
		else
			printf("%d\n",ans);

}