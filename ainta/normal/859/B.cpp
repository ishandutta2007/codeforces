#include<cstdio>
#include<algorithm>
using namespace std;
int res = 1e9;
int main(){
    int n, i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        res = min(res, ((n+i-1)/i + i) * 2);
    }
    printf("%d\n",res);
}