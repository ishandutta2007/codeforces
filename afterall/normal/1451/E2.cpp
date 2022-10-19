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
const int N=1e5;
ll a[N];
vector <int> id[N];
int32_t main(){
    ll n;
    cin >> n;
    id[0].pb(1);
    for (int i=2;i<=n;i++){
        cout << "XOR " << 1 << " " << i << endl;
        cin >> a[i];
        id[a[i]].pb(i);
    }
    for (int i=0;i<N;i++){
        if (id[i].size()>1){
            ll x=id[i][0],y=id[i][1];
            cout << "AND " << x << " " << y << endl;
            ll d;
            cin >> d;
            ll c=d ^ a[x];
            for (int i=1;i<=n;i++){
                a[i] ^= c;

            }
            cout << "! ";
            for (int i=1;i<=n;i++){
                cout  << a[i] << " ";
            }
            cout << endl;
            return 0;

        }
    }
    ll x=id[0][0],y=id[1][0];
    cout << "AND " << x << " " << y << endl;
    ll d;
    cin >> d;
    d ^= a[x];
    if (d%2==1) d--;
    for (int i=1;i<=n;i++){
        a[i] ^= d;
    }
    y=id[2][0];
    cout << "AND " << x << " " << y << endl;
    cin >> d;
    d ^= a[x];
    if (d%2==1) d=1;
    else d=0;
    for (int i=1;i<=n;i++){
        a[i] ^= d;
    }
    cout << "! ";
    for (int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}