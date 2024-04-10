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

ll p[MAXN];

set <ll> st[MAXN];

ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        p[i] = i;
        string s;
        cin >> s;
        for(auto j : s)st[j - 'a'].insert(i);
    }

    for(int i = 0; i < 26; i++)if(sz(st[i]) > 1){
        ll last = *st[i].begin();
        st[i].erase(st[i].begin());
        for(auto j : st[i]){
            ll ra = get(j), rb = get(last);
            if(ra != rb){
                p[ra] = rb;
            }
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++)if(p[i] == i)ans++;

    cout << ans << "\n";

    return 0;
}