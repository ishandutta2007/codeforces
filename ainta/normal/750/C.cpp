#include<stdio.h>
#include<algorithm>
using namespace std;
int Mn = -(2e9), Mx = 2e9, n, s;
int main(){
    int i, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(b == 1){
            Mn = max(Mn, 1900 - s);
        }
        else{
            Mx = min(Mx, 1899 - s);
        }
        s += a;
    }
    if(Mx < Mn){
        printf("Impossible\n");
        return 0;
    }
    if(Mx > 1e9){
        printf("Infinity\n");
        return 0;
    }
    printf("%d\n",Mx + s);
}