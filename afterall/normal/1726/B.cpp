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

void Main(){
    ll n,m;
    cin >> n >> m;
    if (m<n){
        cout << "NO" << endl;
        return ;
    }
    if (n==1){
        cout << "YES" << endl;
        cout << m << endl;
        return ;
    }
    if (n%2==1){
        cout << "YES" << endl;
        for (int i=0;i<n-1;i++) cout << 1 << " ";
        cout << m-(n-1) << endl;
        return ;
    }
    else{
        if (m%2==1){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for (int i=0;i<n-2;i++){
            cout << 1 << " ";
        }
        ll z=m-(n-2);
        cout << z/2 << " " << z/2 << endl;

    }
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}