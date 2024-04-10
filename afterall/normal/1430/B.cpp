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
ll a[N];
ll Main(){
    ll n,k;
    cin >> n >> k;
    a[n+1]=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (int i=2;i<=k+1;i++){
        a[1]+=a[i];
    }
    if (k){
        cout << a[1] << endl;
    }
    else{
        cout << a[1]-a[n] << endl;
    }

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}