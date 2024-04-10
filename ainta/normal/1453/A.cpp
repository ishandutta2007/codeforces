#include<cstdio>
#include<algorithm>
using namespace std;
int TC;
int A[110], B[110], CA[310], CB[310];
void Solve(){
    int i, j, n, m, res = 0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    for(i=0;i<m;i++)scanf("%d",&B[i]);
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(A[i]==B[j])res++;
    printf("%d\n",res);
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}