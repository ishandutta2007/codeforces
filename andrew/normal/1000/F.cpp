#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<int,int>
//#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 30 * 1e6;

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

int last[500001];
set <int> mp[500001];
int root[1100000], l[MAXN], r[MAXN], now[4010000], a[800000];
pll p[MAXN];
int q1 = 1;

void build(int v, int tl, int tr){
    q1 = max(q1, v + 1);
    now[v] = v;
    if(tl == tr)return; else {
        int tm = (tl + tr) >> 1;
        l[v] = v << 1;
        build(v << 1, tl, tm);
        r[v] = (v << 1) + 1;
        build(r[v], tm + 1, tr);
        p[v] = min(p[l[v]], p[r[v]]);
    }
}

void modify(int v, int tl, int tr, int pos, pll val){
    ll x = now[v];
    now[v] = q1++;
    if(tl == tr)p[now[v]] = val; else{
        int tm = (tl + tr) >> 1;
        l[now[v]] = l[x];
        r[now[v]] = r[x];
        if(pos <= tm){
            modify(v << 1, tl, tm, pos, val);
            l[now[v]] = now[v << 1];
        }else{
            modify((v << 1) + 1, tm + 1, tr, pos, val);
            r[now[v]] = now[(v << 1) + 1];
        }
        p[now[v]] = min(p[l[now[v]]], p[r[now[v]]]);
    }
}

pll get(int v, int tl, int tr, int l1, int r1){
    if(l1 > r1)return m_p(1e9, 1e9);
    if(tl == l1 && tr == r1)return p[v];
    int tm = (tl + tr) >> 1;
    return min(get(l[v], tl, tm, l1, min(r1, tm)), get(r[v], tm + 1, tr, max(l1, tm + 1), r1));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("output.txt","r",stdin);
    //freopen("vivod.txt","w",stdout);
    int n, k;
    cin >> n;
    k = 1;
    root[1] = 1;
    set <int> :: iterator it, it1;
    set <int> s;
    for(int i = 0; i < MAXN; i++)p[i] = m_p(1e9, 1e9);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    root[s.size()] = 1;
    for(int i = 1; i <= n; i++){
        int x = a[i];
        int poz = i + s.size();
        if(mp[x].size() >= k){
            it = mp[x].begin();
            modify(1, 1, n, *it, m_p(1e9, 1e9));
            last[x] = *it;
            mp[x].erase(it);
        }
        mp[a[i]].insert(poz);
        root[i + s.size()] = root[i - 1 + s.size()];
        it = mp[x].begin();
        if(mp[x].size() >= k){
                root[i + s.size()] = q1;
                modify(1, 1, n, *it, m_p(last[x], x));
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        pll xe = get(root[r], 1, n, l, r);
        if(xe.fi < l)cout << xe.se << "\n"; else cout << "0\n";
    }
    return 0;
}