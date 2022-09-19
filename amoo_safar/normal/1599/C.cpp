#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e3+100;

ll e3(ll n){
    return n*(n-1)*(n-2)/3/2;
}
ll e2(ll n){
    return n*(n-1)/2;
}
int32_t main(){
    sync;
    ll n;
    ld p;
    cin >> n >> p;
    if (p==0) kill(0);
    for (int i=1;i<=n;i++){
        ld kol=e3(n);
        ld t3=e3(i);
        ld t2=e2(i)*(n-i);
        ld t1=i*e2(n-i);
        ld t0=e3(n-i);
        ld ans=0;
        ans+=t3/kol;
        ans+=t2/kol;
        ans+=(ld)1/(ld)2 * t1/kol;
        if (ans>=p) {
            kill(i);
        }
    }
}