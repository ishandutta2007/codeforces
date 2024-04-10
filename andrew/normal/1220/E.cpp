#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct edge{
    ll a, b;
};

vector <edge> G;

bool is_bridge[MAXN];

vector <pll> v[MAXN];
vector <ll> V[MAXN];

bool fl[MAXN];

int timer, Tin[MAXN], fup[MAXN];

map <pll, ll> mp;

void dfs(ll x, ll p = -1) {
	fl[x] = 1;
	Tin[x] = fup[x] = timer++;
	for (auto to : v[x]){
		if (to.fi == p)continue;
		if (fl[to.fi])
			fup[x] = min(fup[x], Tin[to.fi]);
		else {
			dfs(to.fi, x);
			fup[x] = min(fup[x], fup[to.fi]);
			if (fup[to.fi] > Tin[x]){
                is_bridge[to.se] = 1;
			}
		}
	}
}

ll comp[MAXN], r;
ll kol1[MAXN];

ll KOL[MAXN], fkol[MAXN];

ll w[MAXN], ans = 0;

void paint(ll x){
    comp[x] = r;
    KOL[r] += w[x];
    fkol[r]++;
    for(auto to : v[x])if(!is_bridge[to.se] && !comp[to.fi])paint(to.fi);
}

ll stn, Comp[MAXN], R, dp[MAXN], dp1[MAXN];

bool F[MAXN];

void fufel(ll x, ll pr){
    ll sc = 0;
    ll res = 0;

    for(auto to : V[x])if(to != pr){
        fufel(to, x);
        sc += dp1[to];
        dp[x] = max(dp[x], dp[to]);
        F[x] |= F[to];
    }

    dp[x] += KOL[x];

    for(auto to : V[x])if(to != pr){
        dp[x] = max(dp[x], KOL[x] + dp[to] + sc - dp1[to]);
    }

    if(fkol[x] > 1){
        F[x] = 1;
    }

    if(F[x])dp1[x] = sc + KOL[x];

    dp[x] = max(dp[x], dp1[x]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> w[i];
    G.resize(m);
    for(int i = 0; i < m; i++){
        cin >> G[i].a >> G[i].b;
        if(G[i].a > G[i].b)swap(G[i].a, G[i].b);
        v[G[i].a].p_b({G[i].b, i});
        v[G[i].b].p_b({G[i].a, i});
    }

    for(int i = 1; i <= n; i++)if(!fl[i]){
        fl[i] = 1;
        dfs(i);
    }


    for(int i = 1; i <= n; i++)if(!comp[i]){
        r++;
        paint(i);
    }

    set <pll> kek;

    for(int i = 0; i < m; i++)if(is_bridge[i]){
        ll a, b;
        a = comp[G[i].a], b = comp[G[i].b];
        if(a > b)swap(a, b);
        kek.insert({a, b});
    }

    for(auto i : kek){
        V[i.fi].p_b(i.se);
        V[i.se].p_b(i.fi);
    }

    ll s;
    cin >> s;

    fufel(comp[s], 0ll);

    cout << max(dp1[comp[s]], dp[comp[s]]) << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}