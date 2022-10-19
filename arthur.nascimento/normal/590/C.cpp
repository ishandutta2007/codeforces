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
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 1010			
#define mod 1000000007
 
using namespace std;

int d[3][maxn][maxn];
int foi[3][maxn][maxn];
char M[maxn][maxn];

int D[3][3];

int n,m;

queue<pii> Q[3];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int ok(int x,int y,int t){
	if(x < 0 || y < 0 || x == n || y == m) return 0;
	if(foi[t][x][y] || M[x][y] == '#') return 0;
	return 1;
}

void bfs(int t){

	debug("bfs %d\n",t);
	
	while(Q[t].size()){
		pii u = Q[t].front();
		Q[t].pop();
		if(M[u.first][u.second] >= '1' && M[u.first][u.second] <= '3'){
			D[t][M[u.first][u.second]-'1'] = min(D[t][M[u.first][u.second]-'1'],d[t][u.first][u.second]);
			debug("D[%d][%d] -> %d\n",t,M[u.first][u.second]-'1',D[t][M[u.first][u.second]-'1']);
		}
		for(int i=0;i<4;i++){
			if(ok(u.first+dx[i],u.second+dy[i],t)){
				foi[t][u.first+dx[i]][u.second+dy[i]] = 1;
				Q[t].push(pii(u.first+dx[i],u.second+dy[i]));
				d[t][u.first+dx[i]][u.second+dy[i]] = 1 + d[t][u.first][u.second];
				//debug("d000 = %d\n",d[0][0][0]);
				//debug("push %d %d %d\n",u.first+dx[i],u.second+dy[i],d[t][u.first+dx[i]][u.second+dy[i]]);
			}
		}
	}

}			

main(){
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++)
        	for(int j=0;j<m;j++)
        		d[0][i][j] = d[1][i][j] = d[2][i][j] = 99999999;
        		
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){  
                scanf(" %c",&M[i][j]);
                if(M[i][j] >= '1' && M[i][j] <= '3'){
                    d[M[i][j]-'1'][i][j] = 0;
                    foi[M[i][j]-'1'][i][j] = 1;
                    Q[M[i][j]-'1'].push(pii(i,j));
                }
            }
        }
        
        
        debug("ok");
        
        D[0][1] = D[0][2] = D[1][0] = D[1][2] = D[2][0] = D[2][1] = 99999999;
        
        bfs(0);debug("oi");
        bfs(1);
        bfs(2);
        
        int ans = 999999999;
        
       ans = min(ans,D[0][1]+D[0][2]-2);
       ans = min(ans,D[1][0]+D[1][2]-2);
       ans = min(ans,D[2][0]+D[2][1]-2);
       
       for(int i=0;i<n;i++)
       		for(int j=0;j<m;j++)
       			if(M[i][j] == '.')
       				ans = min(ans,d[0][i][j]+d[1][i][j]+d[2][i][j]-2);
       
       printf("%d\n",(ans>1000000)?-1:ans);

}