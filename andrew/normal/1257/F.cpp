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

ll st[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll sp = 1;

    for(int i = 0; i < MAXN; i++){
        while(pw(sp) <= i)sp++;
        st[i] = sp;
    }

    ll ans = inf;

    ll n;
    cin >> n;

    vector <ll> a(n + 1), b(n + 1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll kek = pw(15) - 1;

    map <vector <short>, ll> mp;

    ll ra, rb, x, ct;

    for(int step = 0; step < pw(15); step++){
        for(int i = 0; i < n; i++){
            b[i] = (a[i] & kek) ^ step;
        }

        vector <short> vc;

        for(int i = 0; i < n - 1; i++){
            vc.p_b(__builtin_popcountll(b[i]) - __builtin_popcountll(b[i + 1]));
        }
        if(mp.find(vc) == mp.end())mp[vc] = step;
    }

    for(int step = 0; step < pw(15); step++){
        for(int i = 0; i < n; i++){
            b[i] = ((a[i] >> 15) & kek) ^ step;
        }

        vector <short> vc;

        for(int i = 0; i < n - 1; i++){
            vc.p_b(__builtin_popcountll(b[i + 1]) - __builtin_popcountll(b[i]));
        }

        if(mp.find(vc) != mp.end())ans = min(ans, mp[vc] | (step << 15));
    }

    if(ans == inf)ans = -1;

    cout << ans << "\n";

    return 0;
}