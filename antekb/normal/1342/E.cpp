#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2e5+5, INF=1e9+5, MOD=998244353;
int pot(int a, int b){
    if(b==1){
        return a;
    }
    if(b==0){
        return 1;
    }
    ll c=pot(a, b/2);
    return (((c*c)%MOD)*pot(a, b&1))%MOD;
}
int odw(int a){
    return pot(a, MOD-2);
}
ll tab[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    if(k>=n){
        cout<<0;
        return 0;
    }
    int t=n-k;
    tab[0]=1;
    for(int i=1; i<=t; i++){
        tab[i]=(((tab[i-1]*(t-i+1))%MOD)*odw(i))%MOD;
    }
    ll ans=0;
    for(int i=t; i>=0; i--){
        if((t-i)&1) ans-=(pot(i, n)*tab[i])%MOD;
        else    ans+=(pot(i, n)*tab[i])%MOD;
        ans=(ans+MOD)%MOD;
    }
    ll res=1;
    for(int i=1; i<=t; i++){
        res=(((res*(n-i+1))%MOD)*odw(i))%MOD;
    }
    ans=(ans*res)%MOD;
    if(k){
        ans=(2*ans)%MOD;
    }
    cout<<ans;
}