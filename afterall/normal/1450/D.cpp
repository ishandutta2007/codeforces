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
const int N=3e5+100;
ll l[N],r[N];
ll a[N];
pii mx[N];
ll bad[N];
ll pm[N];
ll ans[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=0;i<n+10;i++){
        l[i]=0,r[i]=0,a[i]=0,mx[i]={0,0},pm[i]=1e9;
        bad[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector <int> agh;
    agh.pb(0);
    for (int i=1;i<=n;i++){
        while(a[agh.back()]>=a[i]) agh.pop_back();
        l[i]=agh.back();
        agh.pb(i);
    }
    agh.clear();
    agh.pb(n+1);
    for (int i=n;i;i--){
        while(a[agh.back()]>a[i]) agh.pop_back();
        r[i]=agh.back();
        agh.pb(i);
    }
    for (int i=1;i<=n;i++){
        if (i-l[i]>1 && r[i]-i>1){
            bad[r[i]-1-l[i]-1]=1;
        }
    }
    agh.clear();
    agh.pb(n+1);
    for (int i=n;i;i--){
        while(a[agh.back()]>a[i]) agh.pop_back();
        r[i]=agh.back();
        agh.pb(i);
    }
    for (int i=1;i<=n;i++){
        if (i-l[i]>1 && r[i]-i>1){
            bad[r[i]-1-l[i]-1]=1;
            ll z=r[i]-1-l[i];
            if (mx[a[i]].F<z){
                swap(mx[a[i]].F,mx[a[i]].S);
                mx[a[i]].F=z;
            }
            else{
                mx[a[i]].S=max(mx[a[i]].S,z);
            }
        }
        else{
           // cout << a[i] << endl;
            ll z=r[i]-1-l[i];
            if (mx[a[i]].F<z){
                swap(mx[a[i]].F,mx[a[i]].S);
                mx[a[i]].F=z;
            }
            else{
                mx[a[i]].S=max(mx[a[i]].S,z);
            }
        }
    }
    for (int i=1;i<=n;i++){
        bad[mx[i].S]=1;
    }
    for (int i=n;i>1;i--){
        bad[i]=max(bad[i],bad[i+1]);
    }
    pm[0]=1e9;
    for (int i=1;i<=n;i++){
        pm[i]=min(pm[i-1],mx[i].F);
    }
    for (int i=1;i<=n;i++){
        if (pm[i]<n-i+1 || bad[n-i+1]) ans[n-i+1]=0;
        else ans[n-i+1]=1;
    }
    for (int i=1;i<=n;i++){
        cout << ans[i];
    }
    cout << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}