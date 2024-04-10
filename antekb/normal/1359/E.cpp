#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=5e5+5, INF=1e9+5, P=998244353;
int pot(int a, int b){
    if(!b) return 1;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=c*c%P;
    return c*pot(a, b&1)%P;
}
int fact[N];
int main(){
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=fact[i-1]*1ll*i%P;
    }
    int n, k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1; i<=n; i++){
        if(n/i<k) break;
        ans+=((fact[n/i-1]*1ll*pot(fact[n/i-k], P-2))%P)*1ll*pot(fact[k-1], P-2)%P;
        ans=ans%P;
        //cout<<ans<<"\n";
    }
    cout<<ans<<" ";
}