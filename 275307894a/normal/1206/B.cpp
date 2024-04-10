#include<bits/stdc++.h>
using namespace std;
int flag,tot1,tot2,n,f[1000001];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        if(f[i]==0) flag=1;
        if(f[i]<0) tot1++;
        if(f[i]>0) tot2++;
    }
        for(int i=1;i<=n;i++){
            if(f[i]==0) ans++;
            else ans+=abs(f[i])-1;
        }
    if(!flag&&tot1%2) ans+=2;
    cout<<ans;
    return 0;
}