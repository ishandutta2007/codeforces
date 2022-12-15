#include<stdio.h>
#include<stdlib.h>

#define N_ 205
#define Z 40000
int N, A, B;
short H[N_];
int T[2][Z+5][2];
bool Chk[2][Z+5][2];

int main(){
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);

    int i, j, k;

    scanf("%d%d%d",&N,&A,&B);
    for(i=1; i<=N; i++) scanf("%d",H+i);

    Chk[1][H[1]][0] = Chk[1][0][1] = true;
    int sum = 0;
    for(i=1; i<N; i++){
        sum += H[i]; int c = i&1; int u = (H[i] < H[i+1] ? H[i] : H[i+1]);
        for(int r=0; r<=A; r++) for(k=0; k<2; k++) if(Chk[c][r][k]){
            int g = sum - r; if(g < 0) break; if(g > B) continue;
            if(r + H[i+1] <= A){
                bool &ck = Chk[!c][r+H[i+1]][0];
                int &tv = T[!c][r+H[i+1]][0], val = T[c][r][k] + (k == 1 ? u : 0);
                if(!ck){ ck = true; tv = val; }
                else if(tv > val) tv = val;
            }
            if(g + H[i+1] <= B){
                bool &ck = Chk[!c][r][1];
                int &tv = T[!c][r][1], val = T[c][r][k] + (k == 0 ? u : 0);
                if(!ck){ ck = true; tv = val; }
                else if(tv > val) tv = val;
            }
            Chk[c][r][k] = false; T[c][r][k] = 0;
        }
    }

    int res = 2147483647; sum += H[N];
    for(int r=0; r<=A; r++) for(k=0; k<2; k++) if(Chk[N&1][r][k]){
        int g = sum - r; if(g < 0) break; if(g > B) continue;
        if(res > T[N&1][r][k]) res = T[N&1][r][k];
    }
    if(res == 2147483647) res = -1;
    printf("%d\n",res);
    return 0;
}