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
const int N=110;
ll a[N][N];
ll t[5*N];
int Main(){
    ll n,m;
    cin >> n >> m;
    memset(t,0,sizeof t);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> a[i][j];
            t[i+j] ^= a[i][j];
        }
    }
    for (int i=0;i<N*5;i++){
        if (t[i]) kill("Ashish");
    }
    kill("Jeel");
}
int32_t main(){
    ll t;
    cin >> t;
    while(t--) Main();
}