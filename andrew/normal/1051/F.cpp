#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define pil pair<int, ll>

using namespace std;
typedef long long ll;
const ll MAXN = 100101;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

vector <pair <int, ll> > v[MAXN];
char cc;
string s;

pair <int, ll> p[100001][19];
ll stn, bb[MAXN], a1, b1, c1, i, j, n, m, k, ans, sc, x, a[MAXN];
int tin[MAXN], tout[MAXN], color[MAXN], r;
bool f[MAXN];
void dfs(ll x, ll pr, ll val){
    if(f[x])return;
    color[x] = r;
    f[x] = 1;
    p[x][0] = m_p(pr, val);
    stn++;
    ll i;
    sc++;
    bb[x] = sc;
    tin[x] = stn;
    ll nn = v[x].size();
    for(i = 0; i < nn; i++)dfs(v[x][i].fi, x, v[x][i].se);
    tout[x] = stn;
    sc--;
}

bool Is_Less(ll a, ll b){
    if(tin[a] <= tin[b] && tout[b] <= tout[a] || !a)return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(Is_Less(a, b))return a;
    if(Is_Less(b, a))return b;
    if(bb[a] > bb[b])swap(a, b);
    ll i;
    for(i = 18; i >= 0; i--)if(!Is_Less(p[a][i].fi, b))a = p[a][i].fi;
    return p[a][0].fi;
}
ll kek(ll l, ll r){
    ll sosat = 1e18;
    if(color[l] != color[r])return sosat;
    ll k = lca(l, r);
    ll res = 0, i;

    for(i = 18; i >= 0; i--)if(Is_Less(k, p[l][i].fi)){
        res += p[l][i].se;
        l = p[l][i].fi;
    }

    for(i = 18; i >= 0; i--)if(Is_Less(k, p[r][i].fi)){
        res += p[r][i].se;
        r = p[r][i].fi;
    }
    return res;
}

pair <ll, pair <int, int> > reb[MAXN];

vector <pil> lev[MAXN], new_lev[MAXN];

ll snm[MAXN];

ll get(ll x){
    if(snm[x] != x)snm[x] = get(snm[x]);
    return snm[x];
}

ll where[MAXN], what[MAXN];
ll dp[101][100001];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    ll j, i;
    for(i = 0; i < m; i++){
        cin >> reb[i].se.fi >> reb[i].se.se >> reb[i].fi;
    }
    sort(reb, reb + m);
    set <ll> slev;
    vector <ll> kk;
    for(i = 1; i <= n; i++)snm[i] = i;
    for(i = 0; i < m; i++){
        ll a1 = reb[i].se.fi, b1 = reb[i].se.se, c1 = reb[i].fi;
        if(get(a1) != get(b1)){
            snm[get(b1)] = get(a1);
            v[a1].p_b({b1, c1});
            v[b1].p_b({a1, c1});
        }else{
            lev[a1].p_b({b1, c1});
            lev[b1].p_b({a1, c1});
            slev.insert(a1);
            slev.insert(b1);
        }
    }
    for(int i = 1; i <= n; i++)if(!color[i]){
        r++;
        dfs(i, 0, 0);
    }
    p[1][0] = m_p(0, 0);
    for(j = 1; j <= 18; j++)
        for(i = 1; i <= n; i++)p[i][j] = m_p(p[p[i][j - 1].fi][j - 1].fi, p[p[i][j - 1].fi][j - 1].se + p[i][j - 1].se);

    for(auto i : slev)kk.p_b(i);

    set <pll> st;
    for(int i = 0; i < kk.size(); i++){
        for(int j = 1; j <= n; j++)dp[i][j] = 1e18;
        ll x = kk[i];
        dp[i][x] = 0;
        st.insert({0ll, x});
        while(!st.empty()){
            pll xe = *st.begin();
            st.erase(st.begin());
            ll x = xe.se, val = xe.fi;
            for(auto j : v[x]){
                ll to = j.fi, val1 = val + j.se;
                if(dp[i][to] > val1){
                    st.erase({dp[i][to], to});
                    dp[i][to] = val1;
                    st.insert({dp[i][to], to});
                }
            }
            for(auto j : lev[x]){
                ll to = j.fi, val1 = val + j.se;
                if(dp[i][to] > val1){
                    st.erase({dp[i][to], to});
                    dp[i][to] = val1;
                    st.insert({dp[i][to], to});
                }
            }
        }
    }

    ll q;
    cin >> q;
    vector <ll> vt;
    set <ll> :: iterator it;
    while(q--){
        cin >> a1 >> b1;
        ll res = kek(a1, b1);
        for(int i = 0; i < kk.size(); i++)res = min(res, dp[i][a1] + dp[i][b1]);
        cout << res << "\n";
    }
    return 0;
}
/*
    8 13
    1 2 4
    2 3 6
    3 4 1
    4 5 12
    5 6 3
    6 7 8
    7 8 7
    1 4 1
    1 8 3
    2 6 9
    2 7 1
    4 6 3
    6 8 2
    1
    1 5
*/