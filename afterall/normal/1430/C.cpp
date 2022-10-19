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
const int N=1e3+100;
ll Main(){
    ll n;
    cin >> n;
    cout << 2 << endl;
    if (n==2){
        kill("1 2");
    }
    cout << n << " " << n-1 << endl;
    for (int i=n-2;i;i--){
        cout << i << " " << i+2 << endl;
    }
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}