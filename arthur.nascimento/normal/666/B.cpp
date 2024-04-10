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
#define maxn 3030

typedef long long ll;
using namespace std;

int dist[maxn][maxn];

int block[maxn];

vector<int> L[maxn];
vector<int> L2[maxn];

int dist2[maxn][maxn];

int foi[maxn];

int close[3][maxn];

int reach[3][maxn];

main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L2[b].pb(a);
	}
	
	for(int i=0;i<n;i++){
		
		memset(foi,0,sizeof(foi));
		
		for(int j=0;j<n;j++)
			dist[i][j] = -1;
		
		queue<int> Q;	
		foi[i] = 1;
		dist[i][i] = 0;
		Q.push(i);
		
		debug("bfs %d\n",i);
		
		while(Q.size()){
			int u = Q.front();
			Q.pop();
			for(int j=0;j<L[u].size();j++)
				if(!foi[L[u][j]]){
					dist[i][L[u][j]] = 1 + dist[i][u];
					Q.push(L[u][j]);
					foi[L[u][j]] = 1;
				}
		}
		
		memset(block,0,sizeof(block));
		
	
		for(int j=0;j<3;j++){
			int best = 0;
			for(int k=0;k<n;k++){
				if(!block[k])
					if((block[best] || dist[i][k] > dist[i][best]) && dist[i][k] != -1)
						best = k;
			}
			debug("-> %d\n",best);
			close[j][i] = best;
			if(block[best]) close[j][i] = -1;
			block[best] = 1;
			
		}
		
		////
		memset(foi,0,sizeof(foi));
		
		for(int j=0;j<n;j++)
			dist2[i][j] = -1;
		
		while(Q.size()) Q.pop();
			
		foi[i] = 1;
		dist2[i][i] = 0;
		Q.push(i);
		
		debug("bfs %d\n",i);
		
		while(Q.size()){
			int u = Q.front();
			Q.pop();
			for(int j=0;j<L2[u].size();j++)
				if(!foi[L2[u][j]]){
					dist2[i][L2[u][j]] = 1 + dist2[i][u];
					Q.push(L2[u][j]);
					foi[L2[u][j]] = 1;
				}
		}
		
		memset(block,0,sizeof(block));
		
	
		for(int j=0;j<3;j++){
			int best = 0;
			for(int k=0;k<n;k++){
				if(!block[k])
					if((block[best] || dist2[i][k] > dist2[i][best]) && dist2[i][k] != -1)
						best = k;
			}
			debug("-> %d\n",best);
			reach[j][i] = best;
			if(block[best]) reach[j][i] = -1;
			block[best] = 1;
			
		}
		
	
	}
	
	debug("ok\n");
	
	int A, B, C, D;
	int ans = -1;
	
	for(int b=0;b<n;b++)
		for(int c=0;c<n;c++){
			
			if(b == c)
				continue;
				
			//debug("bc %d %d dist %d\n",b,c,dist[b][c]);
				
			 for(int i=0;i<3;i++)
			 	for(int j=0;j<3;j++){
			 		int a = reach[i][b];
			 		int d = close[j][c];
			 		//debug("a %d d %d\n",a,d);
			 		if(a == -1 || d == -1) continue;
			 		
			 		if(a == b || a == c || a == d || b == c || b == d || c == d)continue;
			 		
			 		if(dist[a][b] == -1 || dist[b][c] == -1 || dist[c][d] == -1) continue;
			 		
			 		
			 		if(dist[a][b] + dist[b][c] + dist[c][d] > ans){
			 			ans = dist[a][b] + dist[b][c] + dist[c][d];
			 			A = a;
			 			B = b;
			 			C = c;
			 			D = d;
			 		}
			 		
			 	}
			 	
		}
	
	
	//debug("ans %d !! %d\n",ans,dist[1][0]+dist[0][7]+dist[7][6]);
	//debug("%d %d %d\n",dist[1]
	printf("%d %d %d %d\n",A+1,B+1,C+1,D+1);
	
}