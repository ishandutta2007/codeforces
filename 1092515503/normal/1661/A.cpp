#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],b[110];
void mina(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)if(a[i]>b[i])swap(a[i],b[i]);
    long long res=0;
    for(int i=1;i<n;i++)res+=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
    printf("%lld\n",res);
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}