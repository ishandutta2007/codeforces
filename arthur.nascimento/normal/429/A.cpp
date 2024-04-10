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
#define pdd pair<double,double>
#define eps 1e-4
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

vector<int> L[100100];
int A[100100];
int B[100100];

vector<int> ans;

void dfs(int x,int p,int a,int b){

	if(A[x] != B[x] && (a%2==0)){
		a++;
		ans.push_back(x+1);
	}
	if(A[x] == B[x] && (a%2==1)){
		a++;
		ans.push_back(x+1);
	}

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			dfs(*it,x,b,a);


}

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;;
			L[a].push_back(b);
			L[b].push_back(a);
		}

		for(int i=0;i<n;i++)
			scanf("%d",A+i);
		for(int i=0;i<n;i++)
			scanf("%d",B+i);

		dfs(0,0,0,0);

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%d\n",ans[i]);


}