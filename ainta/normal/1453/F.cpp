#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, n, w[3010], D[3010][3010], MM[3010][3010], Z[3010][3010];
void Solve(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)D[i][j]=1e9;
    for(i=n;i>=1;i--){
        int c=0;
        for(j=i-1;j>=1;j--){
            Z[i][j]=c;
            if(w[j]+j>=i)c++;
        }
    }
    for(i=n-1;i>=1;i--){
        if(w[i]+i >= n){
            int c=0;
            for(j=i+1;j<n;j++)if(w[j]+j>=n)c++;
            D[i][n]=c;
        }
        else{
            for(j=i+1;j<=i+w[i] && j<n;j++){
                D[i][j] = MM[j][i+w[i]+1] + Z[j][i];
            }
        }
        MM[i][n+1]=1e9;
        for(j=n;j>=1;j--)MM[i][j]=min(MM[i][j+1],D[i][j]);
    }
    printf("%d\n",MM[1][1]);
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}