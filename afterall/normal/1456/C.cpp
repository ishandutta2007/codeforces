#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e5+100;
ll par[N];
ll p[N];
int Main(){
    vector <int> a,b;
    ll n,k;
    cin >> n >> k;
    k++;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if (x>=0) a.pb(x);
        else a.pb(x);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll ans=0;
    ll sum=0;
    for (int i=0;i<a.size();i++){
        ans+=sum;
        sum+=a[i];
        par[i+1]=ans;
        p[i+1]=p[i]+a[i];
    }
    //cout << par[2] << endl;
    ll mx=ans;
    if (k==0) kill(ans);
    ll p1=0,t=0;
    ll z=0;
    for (int i=a.size()-1;i>-1;i--){
        z+=p1*a[i];
        t++;
        if (t==k){
            t=0,p1++;
        }
        mx=max(mx,par[i]+p[i]*p1+z);
    }
    cout << mx << endl;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    //cin >> t;
    while(t--){
        Main();
    }
}