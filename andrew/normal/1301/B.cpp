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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void main_solve(){
    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll l = 0, r = 1e9;

    pll ans = {inf, inf};

    while(r - l > 10){
        ll c1 = l + (r - l + 1) / 3, c2 = r - (r - l + 1) / 3, a1, a2;
        a1 = a2 = 0;
        for(int i = 1; i <= n; i++){
            b[i] = a[i];
            if(b[i] == -1)b[i] = c1;
            if(i > 1)a1 = max(a1, abs(b[i] - b[i - 1]));
        }
        for(int i = 1; i <= n; i++){
            b[i] = a[i];
            if(b[i] == -1)b[i] = c2;
            if(i > 1)a2 = max(a2, abs(b[i] - b[i - 1]));
        }
        if(a1 < a2)r = c2;
        else l = c1;
    }
    for(int c = l; c <= r; c++){
        ll sc = 0;
        for(int i = 1; i <= n; i++){
            b[i] = a[i];
            if(b[i] == -1)b[i] = c;
            if(i > 1)sc = max(sc, abs(b[i] - b[i - 1]));
        }
        ans = min(ans, {sc, c});
    }
    cout << ans.fi << " " << ans.se << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #endif // LOCAL



    return 0;
}