#include<stdio.h>
#include<algorithm>
using namespace std;
int S[510][510], Num[510][510], C[250100], SS, CC[250100], Res;
char p[510][510];
int n, K, cnt;
void DFS(int x, int y){
    Num[x][y]=cnt;
    CC[cnt]++;
    if(!Num[x+1][y] && p[x+1][y] == '.')DFS(x+1,y);
    if(!Num[x-1][y] && p[x-1][y] == '.')DFS(x-1,y);
    if(!Num[x][y+1] && p[x][y+1] == '.')DFS(x,y+1);
    if(!Num[x][y-1] && p[x][y-1] == '.')DFS(x,y-1);
}
void Ins(int x, int y){
    int t = Num[x][y];
    if(!t)return;
    if(!C[t])SS += CC[t];
    C[t]++;
}
void Del(int x, int y){
    int t = Num[x][y];
    if(!t)return;
    C[t]--;
    if(!C[t])SS -= CC[t];
}
int Calc(int x, int y){
    return S[x+K-1][y+K-1] - S[x-1][y+K-1] - S[x+K-1][y-1] + S[x-1][y-1];
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
        for(j=1;j<=n;j++){
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
            if(p[i][j]=='.')S[i][j]++;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(!Num[i][j] && p[i][j]=='.'){
                cnt++;
                DFS(i,j);
            }
        }
    }
    for(i=1;i<=n-K+1;i++){
        SS = 0;
        for(j=1;j<=cnt;j++)C[j]=0;
        for(j=i-1;j<=i+K;j++){
            for(k=1;k<=K;k++){
                Ins(j,k);
            }
        }
        for(j=i;j<i+K;j++){
            Ins(j,K+1);
        }
        Res = max(Res,SS + K*K - Calc(i,1));
        for(j=2;j<=n-K+1;j++){
            for(k=i;k<i+K;k++){
                Del(k,j-2);
                Ins(k,j+K);
            }
            Del(i-1,j-1);
            Del(i+K,j-1);
            Ins(i-1,j+K-1);
            Ins(i+K,j+K-1);
            Res = max(Res,SS + K*K - Calc(i,j));
        }
    }
    printf("%d\n",Res);
}