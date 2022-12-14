#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ple pair<pll, ll>

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;


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

struct node{
    ll l, r;
    ll val;
};

node clr;

struct NDO{
private:
    vector <node> p;
public:

    void anons(){
        p.p_b(clr);
        p.p_b(clr);
    }

    void modify(ll v, ll tl, ll tr, ll pos, ll x){
        if(tl == tr)p[v].val = x; else {
            ll tm = (tl + tr) >> 1;
            if(pos <= tm){
                if(!p[v].l){
                    p[v].l = p.size();
                    p.p_b(clr);
                }
                modify(p[v].l, tl, tm, pos, x);
            }else{
                if(!p[v].r){
                    p[v].r = p.size();
                    p.p_b(clr);
                }
                modify(p[v].r, tm + 1, tr, pos, x);
            }
            p[v].val = 0;
            if(p[v].l)p[v].val += p[p[v].l].val;
            if(p[v].r)p[v].val += p[p[v].r].val;
        }
    }

    ll k(ll pos){
        return p[pos].val;
    }

    ll le(ll x){
        return p[x].l;
    }

    ll ri(ll x){
        return p[x].r;
    }

};


vector <NDO> T;

ll n, m;

ll get(ll a, ll b, ll v1, ll v2, ll tl, ll tr){
    if(tl == tr)return tl;
    ll tm = (tl + tr) >> 1;
    ll sa = T[a].k(T[a].le(v1));
    ll sb = T[b].k(T[b].le(v2));

    if(sa > sb){
        return get(a, b, T[a].le(v1), T[b].le(v2), tl, tm);
    }else{
        return get(a, b, T[a].ri(v1), T[b].ri(v2), tm + 1, tr);
    }

}

ll f(ll a, ll b){
    return get(a, b, 1, 1, 1, m);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("mooyomooyo.in","r",stdin);
    //freopen("mooyomooyo.out","w",stdout);

    cin >> n >> m;

    T.resize(n + 1);

    set <pll> s;

    ll kol = 0;

    for(int i = 1; i <= n; i++){
        ll k;
        cin >> k;
        T[i].anons();
        for(int j = 0; j < k; j++){
            ll x;
            cin >> x;
            T[i].modify(1, 1, m, x, 1);
        }

        kol += k;
        s.insert({k, i});

    }

    ll l, r;
    l = kol / n;
    r = kol / n + (kol % n > 0);

    vector <pair <pll, ll> > ans;

    while(1){
        if(((--s.end()) -> fi) > r || (s.begin() -> fi < l)){
            pll p1 = *(--s.end()), p2 = *(s.begin());
            s.erase(p1);
            s.erase(p2);
            ll pos = f(p1.se, p2.se);
            p1.fi--;
            p2.fi++;
            T[p1.se].modify(1, 1, m, pos, 0);
            T[p2.se].modify(1, 1, m, pos, 1);
            s.insert(p1);
            s.insert(p2);
            ans.p_b({{p1.se, p2.se}, pos});
        }else break;
    }

    cout << ans.size() << "\n";

    for(auto i : ans)cout << i.fi.fi << " " << i.fi.se << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}