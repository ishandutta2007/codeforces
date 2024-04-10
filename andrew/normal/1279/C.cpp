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

void main_solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector <ll> a(n), b(m);
        for(int i = 0; i < n; i++)cin >> a[i];
        reverse(all(a));
        set <ll> s;
        ll res = 0, ans = 0;
        map <ll, bool> f;
        for(int i = 0; i < m; i++){
            cin >> b[i];
            f[b[i]] = 1;
        }
        for(int i = 0; i < m; i++){
            ans++;
            if(s.find(b[i]) != s.end()){
                s.erase(b[i]);
                continue;
            }
            ans += 2 * res;
            ans += 2 * sz(s);
            while(1){
                ll x = a.back();
                a.pop_back();
                if(x == b[i])break;
                ans += 2;
                if(f[x]){
                    s.insert(x);
                }else res++;
            }
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        while(t--){
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL

    return 0;
}