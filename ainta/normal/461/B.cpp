#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
long long Mod = 1000000007, D[101000][2];
int C[101000], n;
void DFS(int a){
    int i, j, x, l;
    long long T[2];
    if(E[a].size() == 0){
        if(C[a])D[a][1] = 1;
        else D[a][0] = 1;
        return;
    }
    for(j=0;j<2;j++)T[j]=0;
    T[C[a]] = 1;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        DFS(x);
        for(j=1;j>=0;j--){
            T[j] = (T[j] * D[x][1] + T[j]*D[x][0]) % Mod;
            for(l=1;l<=j;l++){
                T[j] = (T[j] + T[j-l] * D[x][l])%Mod;
            }
        }
    }
    for(j=0;j<2;j++)D[a][j] = (D[a][j] + T[j]) % Mod;
}
int main(){
    int i, a;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d",&a);
        E[a].push_back(i);
    }
    for(i=0;i<n;i++)scanf("%d",&C[i]);
    DFS(0);
    printf("%lld\n",D[0][1]%Mod);
}