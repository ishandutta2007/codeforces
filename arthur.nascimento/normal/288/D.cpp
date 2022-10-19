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
 
using namespace std;

vector<int> L[80800];
unsigned long long ans = 0;
unsigned long long n;

unsigned long long st[80800];
unsigned long long sum[80800];

int dfs2(int x,int p){

	st[x] = 1;
	unsigned long long S = 0;

	unsigned long long S2 = 0;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			st[x] += dfs2(*it,x),
			S2 += st[*it] * st[*it];
			
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			S += st[*it] * (n-st[x]+1);

	S += n - st[x];

	S += ((st[x]-1)*(st[x]-1) - S2)/2;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			sum[*it] = S - st[*it] * (n-st[*it]);
	
	return st[x];
}

int dfs(int x,int p,int h,long long pp){

	long long* a = (long long*)malloc(sizeof(long long) * L[x].size());

	debug("dfs %d pp=%I64d\n",x,pp);
	int dg = 0;
	if(L[x].size() == 1 && x != p)
		return 1;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			a[dg++] = dfs(*it,x,h+1,pp+sum[*it]);
			if(x == 0)
				debug("a[%d] = %I64d\n",dg-1,a[dg-1]);
			}

	long long ic2 = 0;
	long long ic2_ic2 = 0;
	long long ic2_jc2 = 0;
	long long ij = 0;
	long long i_i = 0;
	long long sum = 0;
	long long i_ic2 = 0;
	long long i_i_ic2 = 0;
	long long ic3 = 0;

	for(int i=0;i<dg;i++){
		
		ic2 += (a[i] * a[i] - a[i])/2;
		ic2_ic2 += ((a[i] * a[i] - a[i])/2) * ((a[i] * a[i] - a[i])/2);
		i_i += a[i] * a[i];
		sum += a[i];
		i_ic2 += a[i] * ((a[i] * a[i] - a[i])/2);
		i_i_ic2 += a[i] * a[i] * ((a[i] * a[i] - a[i])/2);
		ic3 += (a[i] * (a[i]-1) * (a[i]-2))/6;
		}

	ij = (sum*sum - i_i)/2;
	ic2_jc2 = (ic2*ic2 - ic2_ic2)/2;

	long long A = ic2_jc2;
	long long aux = i_ic2 * sum - i_i_ic2;
	long long B = ic2 * ij - aux;
	long long C = sum * ic2 - i_ic2;

	ans += A;

	debug("x=%d h=%d sum=%I64d ij=%I64d A=%I64d B=%I64d\n",x,h,sum,ij,A,B);
	debug("ic2 = %I64d ic2_ic2 = %I64d\n",ic2,ic2_ic2);

//	ans += (sum + ij) * (((n-sum-1)*(n-sum-2))/2 - (n-sum-h-1)*(n-sum-h-2)/2);
	ans += (sum + ij) * pp;
	
	free(a);
	return sum + 1;
	
}

main(){

		scanf("%I64u",&n);

		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;
			L[a].push_back(b);
			L[b].push_back(a);
		}

		dfs2(0,0);
		dfs(0,0,0,0);

		printf("%I64u\n",2*ans);

}