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
const int N=2e5+100;
ll a[N];
void Main(){
    ll n;
    cin >> n;
    ll p1=0;
    a[0]=-1e9;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]<a[i-1]) p1=1;
    }
    if (!p1){
        cout << 0 << endl;
        return ;
    }
    if (a[n]<a[n-1]){
        cout << -1  << endl;
        return ;
    }
    for (int i=n-2;i;i--){
        if (a[i+1]-a[n]<=a[i+1]){
            cout << i << endl;
            for (int j=1;j<=i;j++){
                cout << j << " " << i+1 << " " << n << endl;
            }
            return ;
        }
        if (a[i]>a[i+1]){
            cout << -1 << endl;
            return ;
        }
    }

    cout << -1 << endl;
    return ;

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}