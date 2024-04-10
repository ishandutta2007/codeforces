#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const ll MxE = (int)1e6 + 9;
const ll mod = (int)1e9 + 7;
bool tooBig;

ll modPow(ll &res, ll n, ll k) {
    assert(res > 0 && n > 0 && k > 0);
    if(res >= (int)1e6 || n >= (int)1e6) {
        tooBig = true;
        res %= mod;
        n %= mod;
    }
    for (; k; k >>= 1) {
        if (k & 1) {
            res = res * n;
            k ^= 1;
        }
        if(res >= (ll)1e6) {
            tooBig = true;
            res %= mod;
        }
        if(!k) {
            break;
        }
        n = n * n;
        if(n >= (ll)1e6) {
            tooBig = true;
            n %= mod;
        }
    }
}

ll f() {
    ll n, p;
    cin >> n >> p;

    map<ll, ll> occ;
    occ[0] = 0; /// !!!!

    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++occ[x];
    }

    if(p == 1)
        return n%2;


    ll curr = 0;
    tooBig = false;
    for(auto it = occ.rbegin(); it != occ.rend(); ++it) {

        if(curr) {
            modPow(curr, p, prev(it)->first - it->first);
        }

        if(tooBig) {
            curr -= it->second;
            curr %= mod;
            if(curr < 0)
                curr += mod;
        } else {
            if (it->second >= curr)
                curr = (it->second - curr) % 2;
            else
                curr -= it->second;
        }
    }

    return (curr%mod+mod)%mod;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        cout << f() << '\n';
    }


    return 0;
}