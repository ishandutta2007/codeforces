/// Black lives matter
#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef int ll;
typedef complex<double> point;
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
const int N=2e2;

vector <pii> a,b;
int32_t main(){
    sync;
    ll t1=0,t2=0;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            if ((i+j)%2==0) a.pb({i,j});
            else b.pb({i,j});
        }
    }
    while(a.size() && b.size()){
        ll x;
        cin >> x;
        if (x!=1){
            pii p=a.back();
            a.pop_back();
            cout << 1 << " " << p.F << " " << p.S << endl;
        }
        else{
            pii p=b.back();
            b.pop_back();
            cout << 2 << " " << p.F << " " << p.S << endl;
        }
    }
    if (a.size()){
        while(a.size()){
            ll x;
            cin >> x;
            if (x!=1){
                pii p=a.back();
                a.pop_back();
                cout << 1 << " " << p.F << " " << p.S << endl;
            }
            else{
                pii p=a.back();
                a.pop_back();
                cout << 3 << " " << p.F << " " << p.S << endl;
            }
        }
    }
    if (b.size()){
        while(b.size()){
            ll x;
            cin >> x;
            if (x!=2){
                pii p=b.back();
                b.pop_back();
                cout << 2 << " " << p.F << " " << p.S << endl;
            }
            else{
                pii p=b.back();
                b.pop_back();
                cout << 3 << " " << p.F << " " << p.S << endl;
            }
        }
    }
}