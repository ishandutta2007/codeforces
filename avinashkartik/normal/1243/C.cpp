#include "bits/stdc++.h" 
using namespace std; 
typedef long long int ll;
#define MAXN (int)1e12

vector <ll> p;
ll x;

int main(int argc, char const *argv[]) { 

    cin>>x;
    ll ans = x;
    for (ll i=2; i*i<=x; i++){
        if(x%i == 0){
            ans = __gcd(ans,i);
            ans = __gcd(ans,x/i);
        }
    }

    cout<<ans<<endl; 
    return 0; 
}