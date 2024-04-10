#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[201000], C[201000], U[401000];
int S[201000];
void Solve(){
    int i, j;
    scanf("%d",&n);
    int pv, M=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        C[w[i]]++;
    }
    for(i=1;i<=n;i++){
        if(M<C[i]){
            M=C[i];
            pv = i;
        }
    }
    int res=0;
    for(i=1;i<=100;i++){
        if(C[i] && i!=pv){
            for(j=0;j<=2*n;j++)U[j]=-1;
            for(j=1;j<=n;j++){
                S[j]=S[j-1];
                if(w[j]==i)S[j]++;
                if(w[j]==pv)S[j]--;
            }
            for(j=n;j>=0;j--){
                if(U[S[j]+n]==-1)U[S[j]+n]=j;
            }
            for(j=0;j<=n;j++){
                res=max(res,U[S[j]+n]-j);
            }
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