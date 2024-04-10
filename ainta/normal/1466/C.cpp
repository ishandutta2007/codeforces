#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int n, D[101000][4];
char p[101000];
void Solve(){
    int i;
    scanf("%s",p+1);
    for(i=1;p[i];i++);
    n=i-1;
    for(i=0;i<4;i++){
        D[1][i]=1e9;
    }
    D[1][0]=0,D[1][1]=1;
    for(i=2;i<=n;i++){
        D[i][0] = D[i][1]=D[i][2]=D[i][3]=1e9;
        if(p[i]!=p[i-1] && p[i]!=p[i-2]){
            D[i][0] = min(D[i][0],D[i-1][0]);
        }
        if(p[i]!=p[i-1]){
            D[i][0] = min(D[i][0],D[i-1][2]);
        }
        D[i][1] = min(D[i-1][0],D[i-1][2]) + 1;
        D[i][2] = D[i-1][3];
        if(p[i]!=p[i-2]){
            D[i][2]=min(D[i][2],D[i-1][1]);
        }
        D[i][3] = min(D[i-1][1],D[i-1][3]) + 1;
    }
    printf("%d\n",min({D[n][0],D[n][1],D[n][2],D[n][3]}));
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}