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

struct qry{
    ll t, x, y;
};

const ll buben = 448;

ll p[MAXN], f[MAXN], zp, x1, y1;

ll get(ll x){
    if(x != p[x])p[x] = get(p[x]);
    return p[x];
}

multiset <ll> v[MAXN], v1[MAXN];

void dfs(ll x){
    if(f[x] == zp)return;
    f[x] = zp;
    for(auto to : v[x])dfs(to);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <qry> c(m);

    for(int i = 0; i < m; i++){
        cin >> c[i].t >> c[i].x >> c[i].y;
    }

    set <pll> st;

    ll l = 1;

    for(int i = 1; i <= n; i++)p[i] = i;

    string ans;
    ll last = 0;

    for(int i = 1; i <= m; i++){
        if(i % buben == 0){
            for(int j = 1; j <= n; j++)p[j] = j;
            for(ll j = 1; j <= n; j++){
                for(auto k : v1[j])st.insert({min(j, k), max(j, k)});
                v[j].clear();
                v1[j].clear();
            }

            vector <pll> S;

            for(int j = i; j <= min(i + buben - 1, m); j++)if(c[j - 1].t == 1){
                x1 = c[j - 1].x % n + 1;
                y1 = c[j - 1].y % n + 1;
                if(x1 > y1)swap(x1, y1);
                if(st.find({x1, y1}) != st.end()){
                    S.p_b({x1, y1});
                    st.erase({x1, y1});
                }
                x1 = (c[j - 1].x - 1) % n + 1;
                y1 = (c[j - 1].y - 1) % n + 1;
                if(x1 > y1)swap(x1, y1);
                if(st.find({x1, y1}) != st.end()){
                    S.p_b({x1, y1});
                    st.erase({x1, y1});
                }
            }

            for(auto j : st){
                if(get(j.fi) != get(j.se)){
                    p[get(j.fi)] = get(j.se);
                }
            }

            for(auto j : S){
                v[get(j.fi)].insert(get(j.se));
                v[get(j.se)].insert(get(j.fi));
                v1[j.fi].insert(j.se);
                v1[j.se].insert(j.fi);
            }

            S.clear();
            l = i;
        }

        if(c[i - 1].t == 1){
            c[i - 1].x = (c[i - 1].x + last - 1) % n + 1;
            c[i - 1].y = (c[i - 1].y + last - 1) % n + 1;
            ll ra = get(c[i - 1].x), rb = get(c[i - 1].y);
            if(v1[c[i - 1].x].find(c[i - 1].y) == v1[c[i - 1].x].end()){
                v[ra].insert(rb);
                v[rb].insert(ra);
                v1[c[i - 1].x].insert(c[i - 1].y);
                v1[c[i - 1].y].insert(c[i - 1].x);
            }else{
                v[ra].erase(v[ra].find(rb));
                v[rb].erase(v[rb].find(ra));
                v1[c[i - 1].x].erase(c[i - 1].y);
                v1[c[i - 1].y].erase(c[i - 1].x);
            }
        }else{
            c[i - 1].x = (c[i - 1].x + last - 1) % n + 1;
            c[i - 1].y = (c[i - 1].y + last - 1) % n + 1;
            if(get(c[i - 1].x) == get(c[i - 1].y)){
                last = 1;
            }else{
                zp++;
                dfs(get(c[i - 1].x));
                if(f[get(c[i - 1].y)] == zp)last = 1;
                else last = 0;
            }
            ans += char(last + '0');
        }
    }

    cout << ans << "\n";

    return 0;
}