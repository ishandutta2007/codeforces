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

int Main(){
    ll a,b;
    cin >> a >> b;
    if (a==0 && b==0) kill(0);
    if (a==b) kill(1);

    if ((a+b)%2==1) kill(-1);

    if (a+b==0) kill(1);
    kill(2);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}