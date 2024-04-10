#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=4e5+100;
ll par[N];
ll rap[N];
ll a[N],b[N];
int Main(){
    ll n;
    cin >> n;

    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++){
        par[i]=par[i-1]+a[i];
        rap[i]=rap[i-1]+b[i];
    }
    for (int i=n;i<N;i++){
        ll z=i/4;
        ll ff=z-(i-n);
        ff=max(ff,(ll)0);
        if (par[i]-par[z]>=rap[n]-rap[ff]) kill(i-n);
        par[i+1]=par[i]+100;
    }
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}