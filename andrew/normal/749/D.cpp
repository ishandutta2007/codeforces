#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

vector <bool> fl;
vector <ll> v[MAXN];


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;

    fl.resize(n + 1);

    vector <pll> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i].fi >> b[i].se;
        v[b[i].fi].p_b(b[i].se);
    }

    vector <ll> c;

    for(int i = 1; i <= n; i++)if(b[i].se == v[b[i].fi].back())c.p_b(b[i].fi);

    ll q;
    cin >> q;

    while(q--){
        ll k;
        cin >> k;
        vector <ll> d;
        while(k--){
            ll x;
            cin >> x;
            d.p_b(x);
            fl[x] = 1;
        }

        ll uk = c.size() - 1;
        while(uk >= 0 && fl[c[uk]])uk--;

        if(uk == -1){
            cout << "0 0\n";
        }else{
            ll Number = c[uk];
            uk--;
            while(uk >= 0 && fl[c[uk]])uk--;
            ll pos = 0;
            if(uk > -1)pos = v[c[uk]].back();
            ll Val = *lower_bound(all(v[Number]), pos);
            cout << Number << " " << Val << "\n";
        }

        for(auto i : d)fl[i] = 0;
        d.clear();
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}