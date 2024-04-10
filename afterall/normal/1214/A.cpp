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
ll Main(){
    ll n,a,b;
    cin >> n >> a >> b;
    b*=5;
    ll mi=n;
    for (int i=0;i<=2e5;i++){
        ll z=n-i*b;
        if (z>=0){
            z%=a;
            mi=min(mi,z);
        }
    }
    cout << mi << endl;
}
int32_t main(){
    ll t;
  //  cin >> t;
  t=1;
    while(t--) Main();
}