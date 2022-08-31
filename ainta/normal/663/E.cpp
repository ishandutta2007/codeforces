#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>D[21][21];
int n, m, w[101000], Res;
char p[101000];
void Do(int a, int b){
    if(a==n){
        int i, S = 0;
        for(i=0;i<=n;i++){
            if(i<n-i)S += D[a][i][0]*i;
            else S += D[a][i][0]*(n-i);
        }
        Res=min(Res,S);
        return;
    }
    int i, j;
    for(i=0;i<=a+1;i++){
        for(j=0;j<(1<<b);j++){
            D[a+1][i][j]=0;
            if(i!=a+1)D[a+1][i][j] += D[a][i][j];
            if(i)D[a+1][i][j] += D[a][i-1][j|(1<<b)];
        }
    }
    Do(a+1,b-1);
    for(i=0;i<=a+1;i++){
        for(j=0;j<(1<<b);j++){
            D[a+1][i][j]=0;
            if(i!=a+1)D[a+1][i][j] += D[a][i][j|(1<<b)];
            if(i)D[a+1][i][j] += D[a][i-1][j];
        }
    }
    Do(a+1,b-1);
}
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",p);
        for(j=0;j<m;j++){
            w[j] += (1<<i)*(p[j]-'0');
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=i;j++){
            D[i][j].resize(1<<(n-i));
        }
    }
    for(i=0;i<m;i++){
        D[0][0][w[i]]++;
    }
    Res = n*m;
    Do(0,n-1);
    printf("%d\n",Res);
}