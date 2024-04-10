#include<stdio.h>
#include<algorithm>
using namespace std;
int w[110], n;
int D[110][3];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]&1)D[i][1] = max(D[i-1][0], D[i-1][2]) + 1;
        if(w[i]&2)D[i][2] = max(D[i-1][0], D[i-1][1]) + 1;
        D[i][0] = max(max(D[i-1][0],D[i-1][1]),D[i-1][2]);
    }
    printf("%d\n", n - max(max(D[n][0],D[n][1]),D[n][2]));
}