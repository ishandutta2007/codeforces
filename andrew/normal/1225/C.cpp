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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, p;

    cin >> n >> p;

    for(int kol = 1; kol <= 100; kol++){
        ll x = n - kol * p;
        if(x < 1)break;
        multiset <ll> s;
        for(int step = 62; step >= 0; step--)if((pw(step) & x))s.insert(step);
        while(sz(s) < kol){
            ll x = *--s.end();
            if(!x)break;
            s.erase(--s.end());
            s.insert(x - 1);
            s.insert(x - 1);
        }
        if(sz(s) != kol)continue;
        vout(kol);
    }

    vout(-1);

    return 0;
}