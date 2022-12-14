#include <bits/stdc++.h>

//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e3 + 1000;
const ll M = 5001;
const ll MAXN = 1123456;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> g[MAXN];
ll us[MAXN], mt[MAXN];

bool try_kuhn(int x){
    if(us[x])return 0;
    us[x] = 1;
    for(auto to : g[x]){
        if(mt[to] == -1 || try_kuhn(mt[to])){
            mt[to] = x;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    vector <ll> p(n + 1), c(n + 1);

    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) mt[i] = -1;

    ll d;
    cin >> d;
    vector <ll> k(d + 1);
    vector <ll> f(n + 1);

    for(int i = 1; i <= d; i++){
        cin >> k[i];
        f[k[i]] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(!f[i]){
            g[p[i]].p_b(c[i]);
        }
    }

    ll ans = 0;

    vector <ll> res(d + 1);

    for(int i = d; i > 0; i--){
        for(int j = 0; j <= M + 1; j++)us[j] = 0;
        while(try_kuhn(ans)){
            ans++;
            for(int j = 0; j <= M + 1; j++)us[j] = 0;
        }
        res[i] = ans;
        g[p[k[i]]].p_b(c[k[i]]);
    }

    for(int i = 1; i <= d; i++)cout << res[i] << "\n";

    return 0;
}