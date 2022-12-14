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
#define ifn(x) if(!(x))
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];
ll ans[MAXN];
bool f[MAXN];

void main_solve(){
    ll n;
    cin >> n;
    ll mb_ans = 0;
    #ifdef LOCAL
        for(int i = 0; i <= n; i++){
            v[i].clear();
            f[i] = 0;
            ans[i] = 0;
        }
    #endif // LOCAL
    ll m = n - 1;
    vector <pll> c(m);
    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        c[i] = {a, b};
        v[a].p_b(b);
        v[b].p_b(a);
    }
    ll step = 0;
    for(auto i : c){
        if(sz(v[i.fi]) == 1 || sz(v[i.se]) == 1){
            f[step] = 1;
            ans[step] = mb_ans++;
        }
        step++;
    }
    for(int i = 0; i < m; i++)if(!f[i]){
        ans[i] = mb_ans++;
    }
    for(int i = 0; i < m; i++)cout << ans[i] << "\n";
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
        main_solve();
    #endif // LOCAL



    return 0;
}