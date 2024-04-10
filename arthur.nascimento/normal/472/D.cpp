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

int M[2020][2020];

vector<pii> L[2020];

int dist[2020][2020];

void dfs(int x,int p,int d,int f){

	dist[f][x] = d;

	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(it->first != p)
		dfs(it->first,x,d+it->second,f);

}

struct edge {
	int a,b,p;
	edge(int a=0,int b=0,int p=0): a(a), b(b), p(p) {}
	bool operator<(edge comp)const{
		return p < comp.p;
	}
}

E[2020*2020];

int pai[2020];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);}

main(){

		int n;
		scanf("%d",&n);
		int qnt = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&M[i][j]);
				if(i < j)
					E[qnt++] = edge(i,j,M[i][j]);
				
			}
			
		int sim = 1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(M[i][j] != M[j][i]) sim = 0;

		for(int i=0;i<n;i++)
			if(M[i][i] != 0) sim = 0;

		if(sim == 0){
			printf("NO\n");
			return 0;
		}

		sort(E,E+qnt);
		for(int i=0;i<n;i++) pai[i] = i;

		int ok = 1;
		int e = 0;

		for(int i=0;i<qnt;i++){

			int A = E[i].a;
			int B = E[i].b;
			int P = E[i].p;

			if(find(A) == find(B))
				continue;

			L[A].pb(pii(B,P));
			L[B].pb(pii(A,P));
			pai[find(A)] = find(B);
			if(P == 0) ok = 0;
			e++;

		}

		if(e != n-1) ok = 0;

		debug("oi");
		for(int i=0;i<n;i++)
			dfs(i,i,0,i);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(dist[i][j] != M[i][j]) ok = 0;

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");

}