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
#include <complex>

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 300300

using namespace std;

int A[maxn];
int B[maxn];
int has[440][440];
int dist[440];
int foi[440];

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	int rev = 0;

	for(int i=0;i<m;i++){
		scanf("%d%d",A+i,B+i), A[i]--, B[i]--;
		has[A[i]][B[i]] = has[B[i]][A[i]] = 1;
		if(A[i] == 0 && B[i] == n-1 || A[i] == n-1 && B[i] == 0)
			rev = 1;
	}

	queue<int> Q;
	Q.push(0);
	foi[0] = 1;
	while(Q.size()){
		int u = Q.front();
		Q.pop();
		for(int i=0;i<n;i++)
			if(has[u][i]^rev && !foi[i]){
				dist[i] = 1 + dist[u];
				foi[i] = 1;
				Q.push(i);
			}
	}
	if(!foi[n-1])
		printf("-1\n");
	else
		printf("%d\n",dist[n-1]);

}