#include<cstdio>
#include<algorithm>
using namespace std;
int C[1030], n, K, x, TC[1030];
int main(){
    int i, a;
    scanf("%d%d%d",&n,&K,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        C[a]++;
    }
    while(K--){
        int ck = 0;
        for(i=0;i<=1023;i++){
            TC[i] += (C[i]+ck)/2;
            TC[i^x] += (C[i]+1-ck)/2;
            ck ^= (C[i]&1);
        }
        for(i=0;i<=1023;i++){
            C[i] = TC[i];
            TC[i] = 0;
        }
    }
    int Mn = 1e9, Mx = -1;
    for(i=0;i<=1023;i++){
        if(C[i]){
            Mn = min(Mn,i);
            Mx = max(Mx,i);
        }
    }
    printf("%d %d\n",Mx,Mn);
}