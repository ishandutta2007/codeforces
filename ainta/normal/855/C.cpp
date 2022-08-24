#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long D[101000][3][11], Mod = 1000000007, po[101000], res;
int n, T, K, M;
vector<int>E[101000];
long long S1[12], S2[12], S3[12], T1[12], T2[12], T3[12];
void DFS(int a, int pp){
    int i, j, k;
    for(i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(x==pp)continue;
        DFS(x, a);
    }
    for(i=0;i<12;i++)S1[i]=S2[i]=S3[i]=0;
    S1[0] = S3[0] = S2[1] = 1;
    for(i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(x==pp)continue;
        for(j=0;j<12;j++)T1[j]=T2[j]=T3[j]=0;
        for(j=0;j<=M;j++){
            for(k=0;j+k<=M;k++){
                T1[j+k] = (T1[j+k] + S1[j] * (D[x][0][k] + D[x][1][k] + D[x][2][k])) % Mod;
                T2[j+k] = (T2[j+k] + S2[j] * D[x][0][k]) % Mod;
                T3[j+k] = (T3[j+k] + S3[j] * (D[x][0][k]+D[x][2][k])) % Mod;
            }
        }
        for(j=0;j<=M;j++)S1[j]=T1[j],S2[j]=T2[j],S3[j]=T3[j];
    }
    for(i=0;i<=M;i++){
        D[a][0][i] = S1[i] * (K-1)% Mod;
        D[a][1][i] = S2[i];
        D[a][2][i] = S3[i] * (T-K)% Mod;
       // printf("%d %d %lld %lld %lld\n",a,i,D[a][0][i],D[a][1][i],D[a][2][i]);
    }
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&T);
    po[0] = 1;
    for(i=1;i<=n;i++){
        po[i]=po[i-1]*(T-1)%Mod;
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    scanf("%d%d",&K,&M);
    DFS(1,0);
    for(i=0;i<=M&&i<=n;i++){
        res = (res + (D[1][0][i] + D[1][1][i] + D[1][2][i])) % Mod;
    }
    printf("%lld\n",res);
}