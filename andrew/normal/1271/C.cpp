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

ll r(ll x, ll y, ll x1, ll y1){
    return abs(x - x1) + abs(y - y1);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, sx, sy;
    cin >> n >> sx >> sy;

    vector <pll> mb;
    mb.p_b({sx + 1, sy});
    mb.p_b({sx - 1, sy});
    mb.p_b({sx, sy + 1});
    mb.p_b({sx, sy - 1});

    vector <pll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;

    pair <ll, pll> xe = {-1, {0, 0}};

    for(auto x : mb){
        ll sc = 0;
        for(auto i : a){
            if(r(i.fi, i.se, sx, sy) == r(x.fi, x.se, sx, sy) + r(x.fi, x.se, i.fi, i.se)){
                sc++;
            }
        }
        xe = max(xe, {sc, x});
    }

    cout << xe.fi << "\n" << xe.se.fi << " " << xe.se.se << "\n";


    return 0;
}