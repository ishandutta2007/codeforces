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

void paint(ll x){
    comp[x] = r;
    for(auto to : v[x])if(!is_bridge[to.se] && !comp[to.fi])paint(to.fi);
}

ll p[N + 5][19], tin[MAXN], tout[MAXN], stn, Comp[MAXN], R;//, Down[MAXN];

void go(ll x, ll pr){
    p[x][0] = pr;
    for(int i = 1; i < 19; i++)p[x][i] = p[p[x][i - 1]][i - 1];
    Comp[x] = R;
    tin[x] = ++stn;
    for(auto to : V[x])if(to != pr){
        go(to, x);
    }
    tout[x] = stn;
}

bool is_less(ll a, ll b){
    if(tin[b] <= tin[a] && tout[a] <= tout[b])return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(is_less(a, b))return b;
    if(is_less(b, a))return a;
    for(int i = 18; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return p[a][0];
}

bool root[MAXN];

ll KOL[MAXN];

ll Up[MAXN], Down[MAXN];

void build(ll x){
    for(auto to : V[x])if(to != p[x][0]){
        if(Down[to] > 0 && Up[to] > 0)vout("No");
        build(to);
    }
}

ll calc(ll x){
    for(auto to : V[x])if(to != p[x][0]){
        calc(to);
        Up[x] += Up[to];
        Down[x] += Down[to];
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    tout[0] = 1e18;

    ll n, m, q;
    cin >> n >> m >> q;
    G.resize(m);
    for(int i = 0; i < m; i++){
        cin >> G[i].a >> G[i].b;
        if(G[i].a > G[i].b)swap(G[i].a, G[i].b);
        mp[{G[i].a, G[i].b}]++;
        v[G[i].a].p_b({G[i].b, i});
        v[G[i].b].p_b({G[i].a, i});
    }

    for(int i = 1; i <= n; i++)if(!fl[i]){
        fl[i] = 1;
        dfs(i);
    }

    for(int i = 0; i < m; i++)if(is_bridge[i]){
        if(mp[{G[i].a, G[i].b}] > 1)is_bridge[i] = 0;
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
    }else{
        KOL[comp[G[i].a]]++;
    }

    for(auto i : kek){
        V[i.fi].p_b(i.se);
        V[i.se].p_b(i.fi);
    }

    for(int i = 1; i <= r; i++)if(!Comp[i]){
        R++;
        root[i] = 1;
        go(i, 0);
    }

    while(q--){
        ll a, b;
        cin >> a >> b;

        if(comp[a] == comp[b]){
            continue;
        }

        a = comp[a];
        b = comp[b];
        if(Comp[a] != Comp[b])vout("No");
        ll c = lca(a, b);
        if(a == c){
            Down[b]++;
            Down[c]--;
        }else if(b == c){
            Up[a]++;
            Up[c]--;
        }else{
            Up[a]++;
            Up[c]--;
            Down[b]++;
            Down[c]--;
        }
    }


    for(int i = 1; i <= r; i++)if(root[i]){
        calc(i);
        build(i);
    }

    vout("Yes");

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}