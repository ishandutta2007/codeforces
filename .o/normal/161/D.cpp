#include <stdio.h>
#include <algorithm>
#include <vector>

const int N_ = 50005;
const int K_ = 505;
using namespace std;

int N, K;
vector< vector<int> > G;

int Que[N_], Qf, Qr;
bool Chk[N_];
int Parent[N_];

int Table[N_][K_];
int Tmp[K_];
/*
 T[i, j] = i    (i, k) = j  
 * = T[c1, k] * T[c2, j - k - 2] + T[c1, j - 1] + T[c2, j - 1]
 */

typedef long long lld;
lld res;

int main(){
    int i, j, k;
    
    scanf("%d%d", &N, &K);
    G.resize (N + 1);
    for(i = 1; i < N; i++){
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back (v);
        G[v].push_back (u);
    }
    
    Qf = Qr = 0; Que[++Qr] = 1;
    Chk[1] = 1;
    
    while(Qf < Qr){
        int t = Que[++Qf];
        for(i = 0; i < G[t].size(); i++){
            int g = G[t][i];
            if(!Chk[g]){
                Chk[g] = 1; Que[++Qr] = g; 
                Parent[g] = t;
            }
        }
    }
    
    for(i = Qr; i > 1; i--){
        int t = Que[i], p = Parent[t];
        Table[t][0] = 1; res += Table[t][K];
        for(j = 0; j < K; j++) res += Table[t][j] * Table[p][K - j - 1];
        for(j = 1; j <= K; j++) Table[p][j] += Table[t][j - 1];
    }
    
    res += Table[1][K];
    printf("%lld\n", res);
    return 0;
}