#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
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
using namespace std;
const int N=2e5+100;
ll r[N][5];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<5;j++){
            cin >> r[i][j];
        }
    }
    ll id=1;
    for (int i=2;i<=n;i++){
        ll z=0;
        for (int j=0;j<5;j++){
            if (r[id][j]<r[i][j]) z++;
        }
        if (z<3) id=i;
    }
    for (int i=1;i<=n;i++){
        if (i==id) continue;
        ll z=0;
        for (int j=0;j<5;j++){
            if (r[id][j]<r[i][j]) z++;
        }
        if (z<3) kill(-1);
    }
    kill(id);
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}