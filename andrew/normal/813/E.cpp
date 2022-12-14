#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 5 * 1e6;

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
map <ll, vector <ll> > mp;
ll l[MAXN], r[MAXN], last[MAXN];
ll p[MAXN];
ll b[MAXN];
ll q1 = 1;
ll zapros = 0;

void build(ll v, ll tl, ll tr){
    last[v] = v;
    q1 = max(q1, v + 1);
    if(tl == tr)return;
    ll tm = (tl + tr) >> 1;
    l[v] = v << 1;
    r[v] = (v << 1) + 1;
    build(l[v], tl, tm);
    build(r[v], tm + 1, tr);
}

void modify(ll ve, ll v, ll tl, ll tr, ll pos,ll val){
    ll x = last[ve];
    last[ve] = v;
    if(tl == tr){
        p[v] = val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(pos <= tm){
        l[v] = q1++;
        r[v] = r[x];
        modify(ve << 1, l[v], tl, tm, pos, val);
    }else{
        l[v] = l[x];
        r[v] = q1++;
        modify((ve << 1) + 1, r[v], tm + 1, tr, pos, val);
    }
    p[v] = p[l[v]] + p[r[v]];
}

ll get(ll v, ll tl, ll tr, ll le, ll ri){
    if(le > ri)return 0;
    if(tl == le && tr == ri)return p[v];
    ll tm = (tl + tr) >> 1;
    return get(l[v], tl, tm, le, min(ri, tm)) + get(r[v], tm + 1, tr, max(le, tm + 1), ri);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k;
    cin >> n >> k;
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        mp[x].p_b(i);
        zapros++;
        modify(1, q1++, 1, n, i, 1);
        if(mp[x].size() > k){
            ll l = mp[x].size() - k - 1;
            modify(1, last[1], 1, n, mp[x][l], 0);
        }
        b[i] = last[1];
    }
    ll lst = 0;
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        l = ((l + lst) % n) + 1;
        r = ((r + lst) % n) + 1;
        if(l > r)swap(l, r);
        lst = get(b[r], 1, n, l, r);
        cout << lst << "\n";
    }
    return 0;
}