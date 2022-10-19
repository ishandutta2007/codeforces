#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[101][50000],a[101],n,m;

long long gao(long long s, int i){
    if(!s || !i) return s;
    if(s<50000 && ~dp[i][s]) return dp[i][s];
    long long ret=gao(s,i-1)-gao(s/a[i],i-1);
    if(s<50000) dp[i][s]=ret;
    return ret;
}

int main(){
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%I64d",a+i);
    memset(dp,255,sizeof(dp));
    sort(a,a+m);
    printf("%I64d\n",gao(n,m));
}