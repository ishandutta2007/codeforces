#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, CK[10100];
long long w[1010000], R[1010000], sum;
int main(){
    int i;
    scanf("%d",&n);
    long long s=0;
    for(i=0;i<n;i++){
        scanf("%lld",&w[i]);
        sum+=w[i];
        s+=w[i]-i;
    }
    for(i=0;i<n;i++){
        R[i]=s/n+i;
        sum-=R[i];
    }
    for(i=0;i<sum;i++)R[i]++;
    for(i=0;i<n;i++)printf("%lld ",R[i]);
}