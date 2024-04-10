#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
char p[5010], q[5010];
int D[5010][5010];
void Solve(){
    int i, j;
    scanf("%d%d",&n,&m);
    scanf("%s",p+1);
    scanf("%s",q+1);
    int res=0;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0){
                D[i][j] = 0;
                continue;
            }
            D[i][j]=max(max(D[i-1][j],D[i][j-1])-1,0);
            if(p[i]==q[j]){
                D[i][j]=max(D[i][j],D[i-1][j-1] + 2);
            }
            res=max(res,D[i][j]);
        }
    }
    printf("%d\n",res);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}