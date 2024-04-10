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
set <ll> s;
bool used[MAXN], f[MAXN];
ll p[MAXN], mn[MAXN], mx[MAXN];

ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

void unite(ll a, ll b){
    a = get(a), b = get(b);
    if(a == b)return;
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
    p[b] = a;
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

    ll ans = 0;


    for(int i = 1; i <= n; i++){
        s.insert(i);
    }

    for(int i = 1; i <= n; i++)mn[i] = mx[i] = p[i] = i;

    while(m--){
        ll a, b;
        cin >> a >> b;
        unite(a, b);
        v[a].p_b(b);
        v[b].p_b(a);
    }

    set <ll> s, st;


    for(int i = 1; i <= n; i++){
        s.insert(i);
        if(p[i] == i)st.insert(i);
    }

    while(!st.empty()){
        ll x = *st.begin();
        st.erase(st.begin());
        ll l = mn[x], r = mx[x];
        vector <ll> c;
        while(!s.empty() && s.lower_bound(l) != s.end()){
            ll val = *s.lower_bound(l);
            if(val > r)break;
            s.erase(val);
            c.p_b(val);
            if(get(val) == x)continue;
            l = min(l, mn[get(val)]);
            r = max(r, mx[get(val)]);
            st.erase(get(val));
            ans++;
            unite(x, get(val));
        }
        for(auto i : c)s.insert(i);
    }

    cout << ans << "\n";

    return 0;
}