#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<510>A1[62][510], A2[62][510], B1[62][510], B2[62][510], R[510], TA[510];
int n, m;
int main(){
    int i, j, k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!c){
            A1[0][a][b] = 1;
            A2[0][b][a] = 1;
        }
        else{
            B1[0][a][b] = 1;
            B2[0][b][a] = 1;
        }
    }
    int c = -1;
    for(i=0;i<=60;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(A1[i][j][k])c = i;
                if((A1[i][j] & B2[i][k]).any()) A1[i+1][j][k] = A2[i+1][k][j] = 1;
                if((B1[i][j] & A2[i][k]).any()) B1[i+1][j][k] = B2[i+1][k][j] = 1;
            }
        }
    }
    if(c==60){
        printf("-1\n");
        return 0;
    }
    if(c==-1){
        printf("0\n");
        return 0;
    }
    for(i=1;i<=n;i++)R[i] = A1[c][i];
    long long res = (1ll << c);
    int pv = 0;
    for(i=c-1;i>=0;i--){
        for(j=1;j<=n;j++)TA[j].reset();
        int ck = 0;
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(!pv){
                    if((R[j] & B2[i][k]).any()) TA[j][k] = 1, ck = 1;
                }
                else{
                    if((R[j] & A2[i][k]).any()) TA[j][k] = 1, ck = 1;
                }
            }
        }
        if(ck){
            pv = !pv;
            res += (1ll<<i);
            for(j=1;j<=n;j++)R[j] = TA[j];
        }
    }
    printf("%lld\n",res > 1e18 ? -1 : res);
}