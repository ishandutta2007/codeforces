#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, D[4010][4010], S[4010][4010];
int w[4010];
void Solve(){
    int i, j;
    scanf("%d",&n);
    n*=2;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=0;i<=n;i++)for(j=0;j<=n;j++)S[i][j]=D[i][j]=0;
    D[0][0]=1;
    S[0][0]=1;
    w[n+1] = 1e9;
    for(i=1;i<=n;i++){
        for(j=i;j>=1;j--)if(w[j]>w[i+1])break;
        int b = j;
        //printf("%d %d\n",b,i);
        for(j=0;j<=i;j++){
            int t = S[i-1][j];
            if(b)t -= S[b-1][j];
            if(t)D[i][i-j] = 1;
        }
        for(j=0;j<=i;j++){
            S[i][j]=S[i-1][j]+D[i][j];
        }
    }
    if(D[n][n/2])puts("YES");
    else puts("NO");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}