#include<stdio.h>
#include<algorithm>
using namespace std;
int w[101000], n;
int main(){
    int i, a, c1 = -1;
    scanf("%d",&n);
    long long Res = 0, tp;
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    for(i=n;i>1;i--){
        if(w[i-1]>=w[i]-1){
            if(c1 == -1)c1 = w[i-1];
            else{
                Res += (long long)c1*w[i-1];
                c1=-1;
            }
            i--;
            continue;
        }
    }
    printf("%lld\n",Res);
}