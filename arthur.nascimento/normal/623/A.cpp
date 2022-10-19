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
#define eps 1e-9


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 30300
using namespace std;
typedef long long ll;

char ans[505];
int M[505][505];

int foi[505];

int n;

void dfs(int v){
	if(foi[v])
		return;
	foi[v] = 1;
	for(int i=0;i<n;i++)
		if(i != v && M[i][v] == 0){
			if(ans[v] == 0)
				ans[v] = 'a';
			if(ans[v] == 'a')
				ans[i] = 'c';
			else
				ans[i] = 'a';
			dfs(i);
		}

}
			
main(){

	int m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		M[a][b] = M[b][a] = 1;
	}

	for(int i=0;i<n;i++)
		dfs(i);
	for(int i=0;i<n;i++)
		if(ans[i] == 0)
			ans[i] = 'b';

	int ok = 1;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(M[i][j] && abs(ans[i]-ans[j]) > 1)
				ok = 0;
			if(M[i][j] == 0 && abs(ans[i]-ans[j]) <= 1)
				ok = 0;
		}

	if(ok){
		printf("Yes\n");
		for(int i=0;i<n;i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	else
		printf("No\n");

}