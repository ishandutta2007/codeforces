#include<cstdio>
#include<algorithm>
using namespace std;
int n, A[1100], B[1010], C[1010], w[1010];
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(i=1;i<=n;i++)scanf("%d",&B[i]);
    for(i=1;i<=n;i++)scanf("%d",&C[i]);
    for(i=1;i<=n;i++){
        w[i]=A[i];
        if(i!=1 && w[i]==w[i-1])w[i]=B[i];
    }
    w[n]=A[n];
    if(w[n]==w[n-1] || w[n]==w[1])w[n]=B[n];
    if(w[n]==w[n-1] || w[n]==w[1])w[n]=C[n];
    for(i=1;i<=n;i++){
        printf("%d ",w[i]);
    }
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}