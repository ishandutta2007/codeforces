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
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <pll> v[MAXN];
ll kol[MAXN];

ll a[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        ll l, r;
        cin >> l >> r;
        v[l].p_b({r, i});
        a[l]++;
        a[r + 1]--;
    }

    ll S = 0;

    set <pll> s;

    vector <ll> ans;

    for(int i = 1; i <= N; i++){
        S += a[i];
        while(!s.empty() && s.begin() -> fi < i)s.erase(s.begin());
        for(auto j : v[i])s.insert(j);

        while(S > k){
            pll xe = *--s.end();
            s.erase(--s.end());
            a[xe.fi + 1]++;
            ans.p_b(xe.se);
            S--;
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";

    return 0;
}