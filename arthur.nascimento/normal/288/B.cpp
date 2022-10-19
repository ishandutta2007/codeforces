#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007 

using namespace std;

vector<int> L[10];

int n,k;

long long A = 0;
long long B = 0;

int foi[10];
int qnt = 0;

void dfs(int x){

	foi[x] = 1;
	qnt++;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!foi[*it])
			dfs(*it);

}

void go(int p){

	if(p == k){
		memset(foi,0,sizeof(foi));
		qnt = 0;
		dfs(0);
		if(qnt == k)
			A++;
		return;
		}

	for(int i=0;i<k;i++){
		L[i].push_back(p);
		go(p+1);
		L[i].pop_back();
		}

}

main(){

		scanf("%d%d",&n,&k);

		go(0);

		B = 1;

		for(int i=0;i<n-k;i++)
			B = (B*(n-k)) % mod;

		printf("%I64d\n",(A*B)%mod);

}