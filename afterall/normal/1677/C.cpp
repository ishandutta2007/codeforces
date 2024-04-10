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
const int N=1e6+100;
ll mod=998244353;
ll a[N];
ll b[N];
ll p[N];
ll vis[N];
void Main(){
    ll n;
    cin >> n ;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        vis[i]=0;
    }
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        b[x]=i;
    }
    ll ans=0;
    ll t=0;
    for (int i=1;i<=n;i++) p[i]=b[a[i]];
    for (int i=1;i<=n;i++){
        if (vis[i]==1) continue;
        ll cnt=0;
        ll j=i;
        while(vis[j]==0){
            cnt++;
            vis[j]=1;
            j=p[j];
        }
        if (cnt%2==1) t++;
       // cout << i << " " << cnt << " " << p[i]   << endl;
    }
    ll z=(n-t)/2;
    for (int i=n-z+1;i<=n;i++) ans+=i;
    for (int i=1;i<=z;i++) ans-=i;
    cout << ans*2 << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}
/*
1
2 2
1100
*/