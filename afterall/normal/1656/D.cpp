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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
ll choose(ll n){
    return n*(n-1)/(ll)2;
}
void Main(){
    ll n;
    cin >> n;
    ll a=n;
    ll z=1;
    while(a%2==0){
        a/=2;
        z*=2;
    }
    if (a==1){
        cout << -1 << endl;
        return ;
    }
    if (z<a){
        if (choose(2*z)<n){
            cout << 2*z << endl;
            return ;
        }
        if (choose(a)<n){
            cout << a << endl;
            return ;
        }
        cout << 1/0 << endl;
    }
    else cout << a << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}