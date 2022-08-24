#include<stdio.h>
#include<algorithm>
using namespace std;
bool v[4], vv[4];
int w[101000];
int main(){
    int i, n, j, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        while(w[i]%2==0)w[i]/=2;
        while(w[i]%3==0)w[i]/=3;
        if(i > 1 && w[i] != w[i-1])break;
    }
    if(i == n+1)printf("Yes\n");
    else printf("No\n");
}