#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int t;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> t;
    for (int iter = 0; iter < t; iter++){
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        if (p == 0){
            if (x == 0)
                cout << 0 << '\n';
            else
                cout << -1 << '\n';
            continue;
        }
        if (q == p){
            if (x == y)
                cout << 0 << '\n';
            else
                cout << -1 << '\n';
        }
        else{
            ll b = max(0ll, max((q * x - p * y + p - 1) / p, (p * y - q * x + (q - p - 1)) / (q - p)));
            ll z = q - y % q;
            if (b % q == 0 && z == q){

            }
            else
            if (b % q <= z)
                b += z - b % q;
            else
                b += z + q - b % q;
            cout << b << '\n';
        }
    }
}