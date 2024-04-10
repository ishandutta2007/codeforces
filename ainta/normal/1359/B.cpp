#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, A, B;
char p[1010][1010];
void Solve(){
    int i, j;
    long long res=0;
    scanf("%d%d%d%d",&n,&m,&A,&B);
    B=min(B,A*2);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
        int c=0;
        for(j=1;j<=m;j++){
            if(p[i][j]=='.')c++;
            if(j==m || p[i][j+1]=='*'){
                res+=c/2*B+c%2*A;
                c=0;
            }
        }
    }
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}