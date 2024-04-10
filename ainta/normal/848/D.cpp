/*#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n, m, w[101000], tp[101000], v[101000], B[320], cnt;
struct point{
    int ck, a, b;
}Q[101000];
set<int>Set[101000];
void Make(int b, int e){
    int i;
    cnt = 0;
    for(i=1;i<=n;i++)tp[i] = w[i], v[i] = 0;
    for(i=b;i<=e;i++){
        if(Q[i].ck == 1){
            int aa = tp[Q[i].a], bb = Q[i].b;
            if(!v[aa]){
                v[aa] = ++cnt;
                B[cnt] = aa;
            }
            if(!v[bb]){
                v[bb] = ++cnt;
                B[cnt] = bb;
            }
            tp[Q[i].a] = Q[i].b;
        }
    }
}
void Do(int b, int e){
    int i;
    for(i=b;i<=e;i++){
        if(Q[i].ck == 1){
            Set[w[Q[i].a]].erase(Q[i].a);
            w[Q[i].a] = Q[i].b;
            Set[Q[i].b].erase(Q[i].a);
            continue;
        }
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Set[w[i]].insert(i);
    }
    for(i=0;i<m;i++){
        scanf("%d%d%d",&Q[i].ck,&Q[i].a,&Q[i].b);
    }
    for(i=0;i<m;i+=100){
        Make(i,min(m-1,i+99));
        Do(i,min(m-1,i+99));
    }
}*/
#include<cstdio>
#include<algorithm>
using namespace std;
int D[60][60], DP[60][60], Mod = 1000000007;
int DD[60][60], InvF[60], F[60], TDD[60][60];
int Pow(int a, int b){
    int r = 1;
    while(b){
        if(b&1)r=1ll*r*a%Mod;
        a=1ll*a*a%Mod;b>>=1;
    }
    return r;
}
int Comb(int a, int b){
    int i, r = 1;
    for(i=a;i>a-b;i--)r = 1ll*r*i%Mod;
    r=1ll*r*InvF[b]%Mod;
    return r;
}
void Calc(int n){
    int i, j, k, ii, jj, c, l;
    for(i=0;i<=n;i++)for(j=0;j<=n;j++)DD[i][j]=0;
    DD[0][0] = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=0;k<=n;k++)for(l=0;l<=n;l++)TDD[k][l]=DD[k][l];
            for(k=1;k<=n;k++){
                int t = Comb(D[i][j+1]+k-1, k);
                for(ii=n - k*i;ii>=0;ii--){
                    for(jj=n - k*j;jj>=0;jj--){
                        TDD[ii+k*i][jj+k*j] = (TDD[ii+k*i][jj+k*j] + 1ll*t*DD[ii][jj])%Mod;
                    }
                }
            }
            for(k=0;k<=n;k++)for(l=0;l<=n;l++)DD[k][l]=TDD[k][l];
        }
    }
    for(i=1;i<=n;i++)DP[n][i+1] = DD[n][i];
}
int main(){
    int n, m;
    int i, j, k, l;
    scanf("%d%d",&n,&m);
    F[0]=1;
    for(i=1;i<=n+1;i++)F[i]=1ll*F[i-1]*i%Mod;
    for(i=0;i<=n+1;i++)InvF[i] = Pow(F[i], Mod-2);
    DP[0][1] = D[0][1] = 1;
    DP[1][2] = D[1][2] = 1;
    for(i=2;i<=n;i++){
        for(j=2;j<=i+1;j++){
            for(k=0;k<i;k++){
                for(l=j;l<=i;l++){
                    D[i][j] = (D[i][j] + 1ll*DP[k][l] * DP[i-1-k][j-1] + 1ll*DP[k][j-1] * DP[i-1-k][l]) % Mod;
                }
                D[i][j] = (D[i][j] + 1ll*DP[k][j-1] * DP[i-1-k][j-1]) % Mod;
            }
        }
        Calc(i);
    }

    printf("%d\n",DP[n][m]);
}