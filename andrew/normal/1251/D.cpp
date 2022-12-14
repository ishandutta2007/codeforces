#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

void sol(){
    ll n, S;
    cin >> n >> S;
    vector <pll> a(n);

    for(auto &i : a)cin >> i.fi >> i.se;

    sort(a.rbegin(), a.rend());

    ll l = 1, r = inf;

    while(l < r){
        ll c = (l + r + 1) >> 1;
        ll sc = 0, kol = 0;

        vector <ll> b;

        for(auto i : a){
            sc += i.fi;
            if(i.fi >= c)kol++;
            else if(i.se >= c)b.p_b(i.fi);
        }

        if(kol + b.size() < n / 2 + 1){
            r = c - 1;
            continue;
        }

        int uk = 0;

        while(kol < n / 2 + 1){
            sc += c - b[uk++];
            kol++;
        }

        if(sc <= S)l = c;
        else r = c - 1;

    }

    cout << l << "\n";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;

    while(t--){
        sol();
    }

    return 0;
}