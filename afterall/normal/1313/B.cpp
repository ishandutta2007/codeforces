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
const int N=2e5+100;

int Main(){
    ll n,x,y;
    cin >> n >> x >> y;
    ll ma=x+y-1;
    ma=min(ma,n);
    ll mi=max((ll)0,x+y-n);
    mi=min(mi,n-1);
    cout << mi+1 << " " << ma << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}