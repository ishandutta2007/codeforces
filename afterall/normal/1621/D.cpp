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
const int N=520;
ll val[N][N];
int Main(){
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=1;i<=2*n;i++){
        for (int j=1;j<=2*n;j++){
            cin >> val[i][j];
            if (i>n && j>n) ans+=val[i][j];
        }
    }
    ll mn=(ll)1e12;
    mn=min(mn,val[1][n+1]);
    mn=min(mn,val[1][2*n]);
    mn=min(mn,val[n][n+1]);
    mn=min(mn,val[n][2*n]);
    mn=min(mn,val[n+1][1]);
    mn=min(mn,val[n+1][n]);
    mn=min(mn,val[2*n][1]);
    mn=min(mn,val[2*n][n]);
    cout << ans+mn << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}