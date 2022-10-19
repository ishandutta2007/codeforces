#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
ll cnt[N];
ll par[N];
void Main(){
    ll n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cnt[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++){
        par[i]=par[i-1]+cnt[i];
    }
    ll d=0;
    for (int i=0;i<=n;i++){
        if (i>=(n-i)+k){
            d=i;
            break;
        }
    }
    ll mn=1e9;
    ll X, Y;
    for (int i=1;i<=n;i++){
        ll z=upper_bound(par,par+n+1,par[i]-d)-par;
        if (z==0) continue;
        if (i-z<mn){
            X=z;
            Y=i;
            mn=Y-X;
        }
    }
    cout << X << " " << Y << endl;
    ll e=0;
    ll p=0;
    cout << 1 << " " ;
    for (int i=1;i<=n;i++){
        if (a[i]>=X && a[i]<=Y) p++;
        else p--;
        if (e!=k-1 && p==1){
            cout << i << endl;
            cout << i+1 << " ";
            p=0;
            e++;
        }
    }
    cout << n << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}