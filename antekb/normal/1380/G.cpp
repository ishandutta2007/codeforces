#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int pot(int a, int b){
    if(b==0)return 1;
    if(b==1)return a;
    long long c=pot(a, b/2);
    return (((c*c)%mod)*(long long)pot(a, b&1))%mod;
}
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    vector<long long> pref(n+1);
    for(int i=0; i<n; ++i){
        cin>>V[i];
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    for(int i=1; i<=n; i++){
        pref[i]=pref[i-1]+V[i-1];
    }
    for(int i=1; i<=n; i++){
        long long ans=0;
        for(int j=0; j<=n/i; j++){
            ans+=(pref[min(n, (j+1)*i)]-pref[j*i])*j;
            ans=ans%mod;
        }
        //cout<<ans<<" ";
        ans=(ans*pot(n, mod-2))%mod;
        cout<<ans<<" ";
    }
}