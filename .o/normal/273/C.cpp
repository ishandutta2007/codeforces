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
typedef set<int> si;
typedef si::iterator sii;
const int INF = 987654321;
const int N_ = 330005;

int N, M;
int Gph[N_][5], Dg[N_];
bool Res[N_];
int Que[N_ * 10], Qf, Qr;

bool check (int nd){
    int cnt = 0, i;
    for(i=1; i <= Dg[nd]; i++) cnt += (Res[Gph[nd][i]] == Res[nd]);
    return cnt >= 2;
}
int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= M; i++){
        int u, v; scanf("%d%d", &u, &v);
        Gph[u][ ++Dg[u] ] = v;
        Gph[v][ ++Dg[v] ] = u;
    }
    
    for(i = 1; i <= N; i++){
        if(Dg[i] > 1) Que[++Qr] = i;
    }   
    
    while(Qf < Qr){
        int t = Que[++Qf]; 
        if(!check(t)) continue;
        
        Res[t] = !Res[t];
        for(i = 1; i <= Dg[t]; i++){
            if(check(Gph[t][i])) Que[++Qr] = Gph[t][i];
        }
    }
    
    for(i = 1; i <= N; i++){
        putchar( Res[i] ? '1' : '0' );
    }
    
    return 0;
}