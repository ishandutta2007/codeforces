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
const int N=1e3+199;
ll a[N][N];
ll vis[N][N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            vis[i][j]=3;
        }
    }
    //cout << n << endl;
    ll cnt=-1;
    for (int I=n;I;I-=2){
        cnt+=2;
        ll w=0;
        for (int i=cnt;i<=n-cnt;i++){
            vis[i][n-cnt+1]=w;
            w++;
        }
        for (int j=n-cnt+1;j>cnt;j--){
            vis[n-cnt+1][j]=w;
            w++;
        }
        for (int i=n-cnt+1;i>cnt;i--){
            vis[i][cnt]=w;
            w++;
        }
        for (int j=cnt;j<n-cnt+1;j++){
            vis[cnt][j]=w;
            w++;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
           // cout << vis[i][j] << " ";
            if (vis[i][j]%4==0 || vis[i][j]%4==1) ans ^= a[i][j];
        }
        //cout << endl;
    }

    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}