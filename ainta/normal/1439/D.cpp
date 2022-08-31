#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define SZ 262144
#define pii pair<int,int>
using namespace std;
int n, m, Q;
long long D[510], Mod, C[510], Comb[1010][1010], InvF[510];
long long DD[1010][1010], CC[1010][1010];
long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
int ww[100], dir[100], sum = 0, nn = 3, ccc = 0;
void DFS(int pv){
    if(pv==nn+1){
        int i, j, T[100]={0}, s = 0;
        for(i=1;i<=nn;i++){
            for(j=ww[i];j>=1&&j<=nn;){
                if(!T[j]){
                    T[j]=i;
                    break;
                }
                s++;
                if(dir[i]==0)j++;
                else j--;
            }
            if(j<=0||j>nn)break;
        }
        if(i==nn+1){
            ccc++;
            sum+=s;
        }
        return;
    }
    for(int i=0;i<nn*2;i++){
        ww[pv]=i%nn+1;
        dir[pv]=i/nn;
        DFS(pv+1);
    }
}
int main(){
    int i, j, k;
    scanf("%d%d%lld",&n,&m,&Mod);
    for(i=0;i<=n;i++){
        Comb[i][0]=1;
        for(j=1;j<=i;j++)Comb[i][j]=(Comb[i-1][j-1]+Comb[i-1][j])%Mod;
    }
    C[0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            long long c = C[j-1]*C[i-j]%Mod*Comb[i-1][j-1]%Mod;
            C[i] = (C[i]+c*(i+1))%Mod;
            int tt = j*(j-1)/2 + (i-j)*(i-j+1)/2;
            D[i] = (D[i] + D[j-1] * C[i-j]%Mod*Comb[i-1][j-1]%Mod*(i+1) + D[i-j] * C[j-1]%Mod * Comb[i-1][j-1]%Mod*(i+1) + c*tt)%Mod;
        }
//        printf("%d %lld %lld\n",i,D[i],C[i]);
    }
//    DFS(1);
//    printf("%d %d\n",sum,ccc);

    DD[0][0]=0;
    CC[0][0]=1;

    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            DD[i+1][j]=(DD[i+1][j]+DD[i][j])%Mod;
            CC[i+1][j]=(CC[i+1][j]+CC[i][j])%Mod;
            for(k=1;k<=m-j && i+k<=n;k++){
                int nx = i+k+1, ny = j+k;
                long long nd = (DD[i][j] * C[k]%Mod + CC[i][j] * D[k]%Mod)* Comb[m-j][k] %Mod;
                long long nc = CC[i][j] * C[k]%Mod * Comb[m-j][k]%Mod;
               // printf("%d %d %d %lld %lld %lld\n",i,j,k,nd,C[k],D[k]);
                DD[nx][ny]=(DD[nx][ny]+nd)%Mod;
                CC[nx][ny]=(CC[nx][ny]+nc)%Mod;
            }
        }
    }
    //printf("%lld\n",CC[n+1][m]);
    printf("%lld\n",DD[n+1][m]);
}