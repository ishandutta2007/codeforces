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

#define pb push_back
 
using namespace std;

char M[1010][15][15];

struct edge{
	int a,b,val;
	edge(int a=0,int b=0,int val=0): a(a), b(b), val(val) {}
	bool operator<(edge comp)const{
		return val > comp.val;
	}
};

edge E[1010*1010];

vector<int> L[1010];

int pai[1010];
int liga[1010];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);}

int mrk1[1010];
int mrk2[1010];

int dfs(int x,int p){

	mrk1[x] = 1;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!mrk1[*it])
			return dfs(*it,x);
	return x;

}

void dfs2(int x,int p){
	
	mrk2[x] = mrk1[x] = 1;
	printf("%d %d\n",x+1,p+1);
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!mrk2[*it])
			dfs2(*it,x);
	

}

main(){

		int n,m,k,w;
		scanf("%d%d%d%d",&n,&m,&k,&w);

		for(int i=0;i<k;i++)
			for(int a=0;a<n;a++)
				scanf(" %s",M[i][a]);

		int cont = 0;
		for(int i=0;i<k;i++)
			for(int j=i+1;j<k;j++){
				int d = 0;
				for(int a=0;a<n;a++)
					for(int b=0;b<m;b++)
						if(M[i][a][b] != M[j][a][b])
							d++;
				E[cont++] = edge(i,j,n*m-w*d);

			}

		sort(E,E+cont);

		for(int i=0;i<k;i++)
			pai[i] = i;

		int ans = k * n * m;

		for(int i=0;i<cont;i++){

			int A = find(E[i].a);
			int B = find(E[i].b);

			if(E[i].val < 0)
				continue;

			if(A == B)
				continue;

			ans -= E[i].val;
			debug("%d-%d val = %d\n",E[i].a, E[i].b, E[i].val);
			pai[A] = B;

			L[E[i].a].pb(E[i].b);
			L[E[i].b].pb(E[i].a);

		}

		printf("%d\n",ans);

		for(int i=0;i<k;i++)
			if(mrk1[i] == 0){
				if(L[i].size() == 0){
					printf("%d 0\n",i+1);
					mrk1[i] = 1;
					continue;
				}
			debug("dfs %d\n",i);
			int u = dfs(i,i);
			dfs2(u,-1);
			}

}