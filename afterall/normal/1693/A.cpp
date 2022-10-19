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
#define kill(x) cout << x << endl;return ;
using namespace std;
void Main(){
    ll n;
    cin >> n;
    vector <int> a;
    ll cnt=0;
    ll p1=0;
    ll p2=0;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a.pb(x);
        cnt+=x;
        if (cnt<0) p1=1;
        if (p2==1 && x!=0) p1=1;
        if (cnt==0) p2=1;

    }
    if (cnt!=0) p1=1;
    if (p1) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int32_t main(){
    ll q;
    cin >> q;
    while(q--) Main();
}