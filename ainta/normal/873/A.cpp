#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, x, w[110], res;
int main(){
    int i;
    scanf("%d%d%d",&n,&K,&x);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        if(i>n-K)res += x;
        else res += w[i];
    }
    printf("%d\n",res);
}