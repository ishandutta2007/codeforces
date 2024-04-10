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

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll g[MAXN], p[MAXN], gp[MAXN], p1[MAXN];

bool fp[MAXN];

void push(ll v){
    ll val = p1[v];
    p1[v] = 0;
    fp[v] = 0;
    p1[v << 1] = val;
    p1[(v << 1) + 1] = val;
    fp[v << 1] = 1;
    fp[(v << 1) + 1] = 1;
    p[v << 1] = mul(gp[v << 1], val);
    p[(v << 1) + 1] = mul(gp[(v << 1) + 1], val);
}

void install(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p[v] = mul(g[tl], val), gp[v] = g[tl];
    else {
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)install(v << 1, tl, tm, pos, val);
        else install((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = add(p[v << 1], p[(v << 1) + 1]);
        gp[v] = add(gp[v << 1], gp[(v << 1) + 1]);
    }
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(fp[v])push(v);
    if(tl == l && tr == r){
        p[v] = mul(gp[v], val);
        fp[v] = 1;
        p1[v] = val;
    }
    else{
        ll tm = (tl + tr) >> 1;
        modify(v << 1, tl, tm, l, min(r, tm), val);
        modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
        p[v] = add(p[v << 1], p[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(fp[v])push(v);
    if(tl == l && tr == r)return p[v];
    ll tm = (tl + tr) >> 1;
    return add(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    g[0] = 1;


    ll n, m, k;
    cin >> n >> m >> k;
    ll q = k + m;
    for(int i = 1; i <= n; i++)g[i] = mul(g[i - 1], 13);

    for(int i = 1; i <= n; i++){
        char a;
        cin >> a;
        install(1, 1, n, i, a - '0' + 1);
    }

    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll l, r, c;
            cin >> l >> r >> c;
            modify(1, 1, n, l, r, c + 1);
        }else{
            ll l, r, d;
            cin >> l >> r >> d;
            ll l1 = l, r1 = r - d, l2 = l + d, r2 = r;
            if(l + d - 1 == r){
                cout << "YES\n";
            }else{
                ll a = mul(g[l2 - 1], get(1, 1, n, l1, r1)), b = mul(g[l1 - 1], get(1, 1, n, l2, r2));
                if(a == b)cout << "YES\n"; else cout << "NO\n";
            }
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}