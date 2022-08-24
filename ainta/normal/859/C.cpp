#include<cstdio>
#include<algorithm>
using namespace std;
int D[52], n, w[52], Sum;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=n;i>=1;i--){
        Sum += w[i];
        if(i==n){
            D[i] = w[i];
            continue;
        }
        D[i] = max(Sum - D[i+1], D[i+1]);
    }
    printf("%d %d\n",Sum - D[1], D[1]);
}