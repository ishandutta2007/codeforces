#include<stdio.h>
#include<algorithm>
using namespace std;
int n, D[4][4];
long long P[100][4][4], R[4][4], TR[4][4], Res;
char p[101000];
bool v[4200000];
void Do(int L){
    int i, s = 0, G = 1<< (2*L);
    for(i=0;i<n;i++){
        s *= 4;
        s += p[i]-'A';
        if(i >= L){
            s -= (p[i-L]-'A') * G;
        }
        if(i >= L - 1){
            v[s] = true;
        }
    }
    for(i=0;i<G;i++){
        if(!v[i]){
            if(D[i >> (2*L-2)][i&3] == 0)D[i >> (2*L-2)][i&3] = L-1;
        }
        v[i]=false;
    }
}
int main(){
    long long L;
    int i, j, k, cnt, ii;
    bool chk[4];
    scanf("%lld",&L);
    scanf("%s",p);
    for(i=0;p[i];i++){
        chk[p[i]-'A'] = true;
    }
    n = i;
    for(i=0;i<4;i++)if(!chk[i])break;
    if(i!=4){
        printf("%lld\n",L);
        return 0;
    }
    for(i=2;i<=11;i++){
        Do(i);
    }
    L--;
    for(i=0;i<4;i++)for(j=0;j<4;j++)P[0][i][j] = D[i][j];
    cnt = 0;
    while(1){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(P[cnt][i][j] <= L)break;
            }
            if(j!=4)break;
        }
        if(i==4)break;
        cnt++;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                P[cnt][i][j] = L+1;
                for(k=0;k<4;k++){
                    P[cnt][i][j] = min(P[cnt-1][i][k]+P[cnt-1][k][j], P[cnt][i][j]);
                }
            }
        }
    }
    for(i=0;i<4;i++)for(j=0;j<4;j++)if(i!=j)R[i][j]=L+1;
    int ck = 0;
    for(ii=cnt;ii>=0;ii--){
        ck = 0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                TR[i][j] = L+1;
                for(k=0;k<4;k++){
                    TR[i][j] = min(R[i][k]+P[ii][k][j], TR[i][j]);
                }
                if(TR[i][j] <= L)ck = 1;
            }
        }
        if(ck){
            Res += 1ll << ii;
            for(i=0;i<4;i++)for(j=0;j<4;j++)R[i][j]=TR[i][j];
        }
    }
    printf("%lld\n",Res+1);
    return 0;
}