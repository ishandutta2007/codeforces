#include<cstdio>
#include<algorithm>
using namespace std;
int n, a, w[301000], res, SZ[301000], UF[301000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
int main(){
    int i;
    printf("%d ",1);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        UF[a] = a;
        SZ[a] = 1;
        if(UF[a+1]){
            UF[a] = Find(a+1);
            SZ[Find(a+1)]+= SZ[a];
        }
        if(UF[a-1]){
            UF[a-1] = Find(a);
            SZ[Find(a)] += SZ[a-1];
        }
        printf("%d\n",i+1-SZ[n]);
    }
}