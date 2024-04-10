#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
    int x, y;
}w[101000];
int T[101000], D[101000], M[101000];
int n, K;
void Solve(){
    int i, j;
    scanf("%d%d",&K,&n);
    w[0]={1,1};
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&T[i],&w[i].x,&w[i].y);
    }
    for(i=0;i<=n;i++)M[i]=D[i]=-1e9;
    M[0]=D[0]=0;
    for(i=1;i<=n;i++){
        for(j=i-1;j>=i-1000&&j>=0;j--){
            if(abs(w[j].x-w[i].x) + abs(w[j].y-w[i].y) <= T[i]-T[j]){
                D[i]=max(D[i],D[j]+1);
            }
        }
        if(i>1000)D[i]=max(D[i],M[i-1001]+1);
        M[i]=max(M[i-1],D[i]);
    }
    printf("%d\n",M[n]);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}