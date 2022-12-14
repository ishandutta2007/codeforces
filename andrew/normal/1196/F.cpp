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

vector <pll> v[MAXN];

map <int, ll> mp[200101];

bool f[MAXN];

ll Ku[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n, m, k;
    cin >> n >> m >> k;
    k *= 2;
    for(int i = 1; i <= n; i++)Ku[i] = 1e18;
    vector <pair< ll, pll> > kek;
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        Ku[a] = min(Ku[a], c);
        Ku[b] = min(Ku[b], c);
        kek.p_b({c, {a, b}});
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }


    sort(all(kek));

    for(int i = 0; i < min(1000ll, ll(kek.size())); i++)f[kek[i].se.se] = f[kek[i].se.fi] = 1;

    set < pair <ll, pii> > st;

    for(int i = 1; i <= n; i++)if(f[i]){
        mp[i][i] = 0ll;
        for(auto j : v[i])if(f[j.fi]){
            mp[i][j.fi] = j.se;
            st.insert({j.se, {i, j.fi}});
            if(st.size() > k){
                st.erase(--st.end());
            }
        }
    }
   int to;
   ll val;

    while(!st.empty()){
        pair <ll, pii> xe = *st.begin();
        st.erase(st.begin());
        k--;
        if(!k)vout(xe.fi);
        for(auto i : v[xe.se.se])if(f[i.fi]){
            to = i.fi, val = xe.fi + i.se;
            if(mp[xe.se.fi].find(to) == mp[xe.se.fi].end() || mp[xe.se.fi][to] > val){
                st.erase({mp[xe.se.fi][to], {xe.se.fi, to}});
                mp[xe.se.fi][to] = val;
                st.insert({mp[xe.se.fi][to], {xe.se.fi, to}});
                if(st.size() > k){
                    st.erase(--st.end());
                }
            }
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}