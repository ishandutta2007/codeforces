#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <assert.h>
 
typedef long long lld;
using namespace std;
typedef vector<int> vi;
typedef vi::iterator vii;
const int N_ = 200005;
const int INF = 987654321;

int N, M;
struct Edge{
    int v, c, e; bool d;
    Edge(): v(0), c(0), e(0), d(0){ }
    Edge(int v, int c, int e, bool d): v(v), c(c), e(e), d(d){ }
};

vector< vector<Edge> > G;
int Flow[N_];
int Que[N_], Qf, Qr;
bool Visited[N_];
bool Dir[N_];

int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    G.resize (N + 1);
    for(i = 1; i <= M; i++){
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        G[u].push_back ( Edge(v, c, i, 0) );
        G[v].push_back ( Edge(u, c, i, 1) );
        if(u > 1) Flow[u] += c;
        if(v > 1) Flow[v] += c;
    }
    
    for(i = 1; i < N; i++) Flow[i] >>= 1;
    Que[++Qr] = 1; Visited[1] = 1;
    while(Qf < Qr){
        int f = Que[++Qf], sz = G[f].size();
        for(i = 0; i < sz; i++){
            Edge g = G[f][i]; if( !Visited[g.v] ){
                Dir[g.e] = g.d; Flow[g.v] -= g.c;
                if(Flow[g.v] == 0) Visited[g.v] = 1, Que[++Qr] = g.v;
            }
        }
    }
    
    for(i = 1; i <= M; i++) printf("%d\n", Dir[i]);
    return 0;
}