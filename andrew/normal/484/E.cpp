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
#define sset ordered_set
#define next sosite_bibu_bitsi

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

struct vertex{
    ll suf, pref, ans, kol;

};

vertex T[MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr)T[v].kol = 1; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        T[v].kol = tr - tl + 1;
    }
}

vertex unite(vertex a, vertex b){
    vertex res;
    res.ans = max(a.ans, b.ans);

    res.ans = max(res.ans, a.suf + b.pref);

    res.kol = a.kol + b.kol;

    if(a.pref == a.kol){
        res.ans = max(res.ans, a.pref + b.pref);
        res.pref = a.pref + b.pref;
    }else{
        res.pref = a.pref;
    }

    if(b.suf == b.kol){
        res.ans = max(res.ans, a.suf + b.suf);
        res.suf = a.suf + b.suf;
    }else{
        res.suf = b.suf;
    }
    return res;

}

void modify(ll v, ll tl, ll tr, ll pos){

    if(tl == tr){
        T[v].suf = T[v].pref = T[v].ans = 1;
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos); else modify((v << 1) + 1, tm + 1, tr, pos);
        T[v] = unite(T[v << 1], T[(v << 1) + 1]);
    }

}

vertex clr;

vertex get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return clr;
    if(tl == l && tr == r)return T[v];
    ll tm = (tl + tr) >> 1;
    return unite(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

vector <ll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("teamwork.in","r",stdin);
    //freopen("balance.in","w",stdout);


    ll n;
    cin >> n;
    vector <ll> a(n + 1);

    set <ll> s;

    vector <ll> arr;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    map <ll, ll> mp;

    for(auto i : s){

        mp[i] = arr.size();

        arr.p_b(i);

    }

    vector < vector <ll> > pos(arr.size());

    for(int i = 1; i <= n; i++)pos[mp[a[i]]].p_b(i);

    build(1, 1, n);

    ll q;
    cin >> q;

    vector <ll> l(q), r(q), w(q);
    vector <ll> le(q), ri(q), mid(q);

    for(int i = 0; i < q; i++)cin >> l[i] >> r[i] >> w[i];

    for(int i = 0; i < q; i++)ri[i] = arr.size() - 1;

    for(int type = 0; type < 20; type++){
        for(int i = 0; i < q; i++)if(le[i] < ri[i]){
            mid[i] = (le[i] + ri[i]) >> 1;
            if(mid[i] == le[i])mid[i]++;
            v[mid[i]].p_b(i);
        }

        for(int i = arr.size(); i > 0;){
            i--;

            for(auto j : pos[i])modify(1, 1, n, j);

            for(auto j : v[i]){
                ll kol = get(1, 1, n, l[j], r[j]).ans;

                if(kol < w[j])ri[j] = mid[j] - 1; else le[j] = mid[j];

            }

            v[i].clear();
        }

        for(int i = 0; i < MAXN; i++){
            T[i].pref = T[i].suf = T[i].ans = 0;
        }

    }

    for(int i = 0; i < q; i++)cout << arr[le[i]] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}