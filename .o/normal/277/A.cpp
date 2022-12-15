#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;
const int N_ = 305, M_ = 305;
const int INF = 987654321;

int N, M;
int G[N_][M_], Chk[N_];
int T[N_], used[N_];
int res;

int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N + M; i++) {
        for(j = 1; j <= N + M; j++) G[i][j] = INF;
    }
    
    bool stop = true;
    for(i = 1; i <= N; i++){
        int cc; scanf("%d", &cc);
        if(cc > 0) stop = false;
        while(cc--){
            int lg; scanf("%d", &lg);
            G[N + lg][i] = G[i][N + lg] = 0;
            Chk[lg] = 1;
        }
    }
    
    if(stop) return 0 & printf("%d\n", N);
    
    int cclg = 0;
    for(i = 1; i <= M; i++) if(Chk[i]){
        for(j = 1; j <= N; j++){
            if(G[j][i + N]) G[j][i + N] = G[i + N][j] = 1;
            ++cclg;
        }
    }
    
    for(i = 2; i <= N + M; i++) T[i] = INF;
    for(i = 1; i <= cclg + N; i++){
        int mnv = INF, mnj = -1;
        for(j = 1; j <= N + M; j++){
            if(mnv > T[j] && !used[j]) mnv = T[j], mnj = j;
        }
        if(mnj < 0) break;
        res += T[mnj]; used[mnj] = true;
        for(j = 1; j <= N + M; j++){
            if(!used[j] && T[j] > G[mnj][j]) T[j] = G[mnj][j];
        }
    }
    
    printf("%d\n", res);
    return 0;
}