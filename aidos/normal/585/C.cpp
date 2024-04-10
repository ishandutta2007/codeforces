#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

ll a, b;

vector < pll > ans;
ll gcd(ll x, ll y){
    if( y == 0 || x == 0) return x + y;
    if(x == 1 && y ==1) return 1;
    if(x == 1) {
        ans.pb( mp(0, y-1));
        return 1;
    }
    if(y == 1) {
        ans.pb( mp(1, x-1));
        return 1;
    }
    if(x > y){
        ans.pb( mp(1, x/y));
        return gcd(x % y, y);
    }else {
        ans.pb( mp(0, y/x));
        return gcd(x, y % x);
    }
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b;
    ll g = gcd(a, b);
    if( g == 1){
        //reverse(all(ans));
        for(pll it : ans){
            cout << it.s;
            if(it.f == 1) cout << "A";
            else cout << "B";
        }
        cout << endl;
    }
    else cout << "Impossible" << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}