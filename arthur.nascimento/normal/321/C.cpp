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

#define eps 1e-9



#ifdef ONLINE_JUDGE

#define debug(args...)

#else

#define debug(args...) fprintf(stderr,args)

#endif



using namespace std;



vector<int> L[100100];
int lista[100100];
int resp[100100];
int block[100100];
int dist[100100][3];
int achou[100100][3];
int maior_dist;
int v;
int size;
int cont = 1;


int dfs(int x,int k){

    debug("achou %d dist = %d\n",x+1,dist[x][k]);
    achou[x][k] = cont;
    if(dist[x][k] > dist[v][k])
        v = x;
        
    lista[size++] = x;

    int visit = 1;
    
    for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
        if(cont != achou[*it][k] && !block[*it]){
            dist[*it][k] = dist[x][k] + 1;
            debug("-> %d %d\n",*it+1,x+1);
            visit += dfs(*it,k);
            
            }
    return visit;
}


void go(int x,char dg){

    cont++;
    getchar();
    debug("go %d\n",x+1);
//  memset(achou,0,sizeof(achou));


    v = 0;
    dist[v][0] = dist[x][0] = 0;

    size = 0;
    if(dfs(x,0) == 1){
        resp[x] = dg;
        return;
        }
    debug("v1 = %d\n",v+1);

    int v1 = v;

    size = 0;
    dist[v1][1] = 0;
    dfs(v1,1);

    debug("v2 = %d\n",v+1);
    int v2 = v;

    int raio = dist[v][1];

    size = 0;
    dist[v2][2] = 0;
    dfs(v2,2);

    int centro = -1;

    debug("lista: ");
    for(int i=0;i<size;i++)
        debug("%d ",lista[i]);
    debug("raio = %d\n",raio);

    for(int i=0;i<size;i++)
        if(dist[lista[i]][2] + dist[lista[i]][1] == raio
           &&
           abs(dist[lista[i]][2] - dist[lista[i]][1]) <= 1)
            centro = lista[i];

    debug("centro = %d\n",centro+1);
    resp[centro] = dg;
    block[centro] = 1;

    for(vector<int> :: iterator it = L[centro].begin(); it < L[centro].end(); it++)
        if(!block[*it])
            go(*it,dg+1);
            


}


main(){

    

   int n;
   scanf("%d",&n);

   for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    L[a-1].push_back(b-1);
    L[b-1].push_back(a-1);
    }

   go(0,'A');

   
   for(int i=0;i<n;i++)

    printf("%c ",resp[i]);

    

}