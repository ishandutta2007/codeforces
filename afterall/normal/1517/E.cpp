#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef complex<double> point;
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
const int N=2e5+100;
ll mod=998244353;
ll a[N];
ll par[N];
ll par2[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        par[i]=par[i-1]+a[i];
        if (i>1)
            par2[i]=a[i]+par2[i-2];
    }
    ll ans=0;
    ll zz=0;
    for (int i=0;i<n;i++){
        if (par[i]*2>=par[n]) continue;
        ll l=i,r=n+2;
        if (r%2!=l%2) r--;
        if (r==l) cout << 1/0;
        while(r-l>2){
            ll mid=(r+l)/2;
            if (mid%2!=l%2) mid++;
            if (mid==r) cout << 1/0 << endl;
            if ((par[i]+par2[mid]-par2[i])*2>=par[n]) r=mid;
            else l=mid;
        }
        ans+=(l-i)/2+1;
      //  cout << i << "  ff " << l << endl;
        if (par[i]*2+a[n]*2>=par[n] || i>=n-2) continue;
        l=i,r=n-1;
        if (r%2!=l%2) r--;
        if (r==l) cout << 1/0;
        while(r-l>2){
            ll mid=(r+l)/2;
            if (mid%2!=l%2) mid++;
            if (mid==r) cout << 1/0 << endl;
            if ((par[i]+par2[mid]-par2[i]+a[n])*2>=par[n]) r=mid;
            else l=mid;
        }
      //  cout << i << " gg " << l << endl;
        ans+=(l-i)/2+1;
    }

    for (int i=3;i<n;i++){
        if (par[i]*2-a[1]*2>=par[n]) continue;
        ll l=i,r=n+2;
        if (r%2!=l%2) r--;
        if (r==l) cout << 1/0;
        while(r-l>2){
            ll mid=(r+l)/2;
            if (mid%2!=l%2) mid++;
            if (mid==r) cout << 1/0 << endl;
            if ((par[i]+par2[mid]-par2[i]-a[1])*2>=par[n]) r=mid;
            else l=mid;
        }
        ans+=(l-i)/2+1;
      //  sss+=(l-i)/2+1;
        if (par[i]*2+a[n]*2-a[1]*2>=par[n] || i>=n-2) continue;
        l=i,r=n-1;
        if (r%2!=l%2) r--;
        if (r==l) cout << 1/0;
        while(r-l>2){
            ll mid=(r+l)/2;
            if (mid%2!=l%2) mid++;
            if (mid==r) cout << 1/0 << endl;
            if ((par[i]+par2[mid]-par2[i]+a[n]-a[1])*2>=par[n]) r=mid;
            else l=mid;
        }
        ans+=(l-i)/2+1;
    }
    for (int i=0;i<=n-2;i++){
        if (par[i]*2>par[n]) ans++;
    }
    cout << ans%mod << endl;
    return 0;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}
/*
1
6
8 5 1 10 5 9
*/