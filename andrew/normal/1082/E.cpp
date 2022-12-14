#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

vector <ll> v[MAXN];

ll p[4 * MAXN], p1[4 * MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr)p[v] = 0, p1[v] = 0; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        p[v] = p1[v] = 0;
    }
}

void push(ll v){
    p[v << 1] += p1[v];
    p1[v << 1] += p1[v];
    p[(v << 1) + 1] += p1[v];
    p1[(v << 1) + 1] += p1[v];
    p1[v] = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(p1[v])push(v);
    if(tl == l && tr == r){
        p[v] += val;
        p1[v] += val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    p[v] = max(p[v << 1], p[(v << 1) + 1]);
}

ll get(){
    return p[1];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n + 1), pref(n + 2);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v[a[i]].p_b(i);
        pref[i] = pref[i - 1];
        if(a[i] == m)pref[i]++;
    }

    pref[n + 1] = pref[n];

    ll ans = v[m].size();

    for(int i = 1; i <= 500000; i++)if(!v[i].empty()){
        ll N = v[i].size();
        build(1, 1, N);
        ll pos = 0;
        for(auto &j : v[i]){
            pos++;
            ll kol = pref[j - 1];
            modify(1, 1, N, pos, pos, kol);
            modify(1, 1, N, 1, pos, 1);
            ans = max(ans, get() + pref[n + 1] - pref[j]);
        }
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}