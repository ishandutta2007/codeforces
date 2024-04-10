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
const int N=1e6+100;
pii W[N];
ll a[N];
ll b[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
        b[i]+=b[i-1];
    }
    //if (a[1]==647399 ){
      //  cout << a[1] << " " << a[2] << endl;
        //cout << b[1] << " " << b[2] << endl;
        //return 0;
    //}
    ll rev=0;
    /// havaset be reev bashe
    if (b[n]>a[n]){
        for (int i=1;i<=n;i++){
            swap(a[i],b[i]);
        }
        rev=1;
    }
    ll cnt=0;
    vector <int> ans,jav;
    ll p1=0;
    for (int i=1;i<=n;i++){
        while(cnt<=n && a[i]-b[cnt]>=n) cnt++;
        cnt--;
        while(cnt<n && a[i]-b[cnt+1]>=0){
            cnt++;
          // cout << i << " " << cnt << " " << a[i]-b[cnt] << endl;
            if (a[i]-b[cnt]==0){
                for (int j=1;j<=i;j++) ans.pb(j);
                for (int j=1;j<=cnt;j++) jav.pb(j);
                p1=1;
                break;
            }
            if (W[a[i]-b[cnt]].F || W[a[i]-b[cnt]].S){
                for (int j=W[a[i]-b[cnt]].F+1;j<=i;j++) ans.pb(j);
                for (int j=W[a[i]-b[cnt]].S+1;j<=cnt;j++) jav.pb(j);
                p1=1;
                break;
            }
            W[a[i]-b[cnt]]={i,cnt};
        }
        if (p1) break;
    }
    if (rev) swap(ans,jav);
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
    cout << jav.size() << endl;
    for (auto u : jav){
        cout << u << " ";
    }
}
/*
1000000
647398 991633
107542 470995
*/