#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, M[1010000];
struct point{
    int x, y;
}A[2010], B[2010];
void Solve(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d%d",&A[i].x,&A[i].y);
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&B[i].x,&B[i].y);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
//            printf("%d %d %d %d\n",A[i].x,A[i].y,B[j].x,B[j].y);
            if(B[j].x>=A[i].x && B[j].y>=A[i].y){
                M[B[j].x-A[i].x]=max(M[B[j].x-A[i].x], B[j].y-A[i].y+1);
             //   printf("%d %d\n",B[j].x-A[i].x, B[j].y-A[i].y);
            }
        }
    }
    for(i=999999;i>=0;i--)M[i]=max(M[i],M[i+1]);
    int res=1e9;
    for(i=0;i<=1000000;i++){
        res=min(res,i+M[i]);
    }
    printf("%d\n",res);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}