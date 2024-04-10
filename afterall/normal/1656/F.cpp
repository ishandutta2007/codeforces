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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
void Main(){
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    for (auto u : a){
      //  cout << u << " ";
    }
    //cout << " kejrgn " << endl;
    if (a[0]==0 && a.back()==0){
        cout << 0 << endl;
        return ;
    }
    if (a[0]>=0 || a.back()<=0){
        cout << "INF" << endl;
        return ;
    }
    ll ans=-(ll)1e18;
    ll p1=0;
    ll p2=0;
    for (int i=1;i<n;i++){
        p1+=a[i]+a[0];
        p2+=a[i]*a[0];
    }
    if (p1>0){
        cout << "INF" << endl;
        return;
    }
    if (p1==0) ans=p2;
    p1=0;
    p2=0;
    for (int i=0;i<n-1;i++){
        p1+=a[i]+a[n-1];
        p2+=a[i]*a[n-1];
    }
    if (p1<0){
        cout << "INF" << endl;
        return ;
    }
    if (p1==0) ans=max(ans,p2);
    for (int i=n-2;i>0;i--){
        p1-=a[i]+a[n-1];
        p2-=a[i]*a[n-1];
        p1+=a[i]+a[0];
        p2+=a[i]*a[0];
        ans=max(ans,-a[i]*p1+p2);
       
    }
    cout << ans << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}