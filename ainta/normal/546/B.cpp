#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[3010];
int main(){
    int i, Res = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&w[i]);
    sort(w,w+n);
    for(i=1;i<n;i++){
        if(w[i]<=w[i-1]){
            Res += w[i-1]+1-w[i];
            w[i] = w[i-1]+1;
        }
    }
    printf("%d\n",Res);
}