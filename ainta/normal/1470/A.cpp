#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int A[301000], B[301000];
int n, m;
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d",&B[i]);
    }
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    reverse(A+1,A+n+1);
    int ck=0;
    long long res=0;
    for(i=1;i<=n;i++){
        if(B[A[i]] <= B[i]){
            ck=1;
        }
        if(ck || i > m)res += B[A[i]];
        else res += B[i];
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