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

ll a[MAXN], p[MAXN];
ll mn[MAXN], mx[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p[v] = val; else {
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = min(p[v << 1], p[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return p[v];
    ll tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    set <ll> s;
    set <ll> s1;
    for(int i = 1; i <= m; i++){
        mn[i] = 1e18;
        mx[i] = -1e18;
    }
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 0; i < MAXN; i++)p[i] = 1e18;

    for(int i = 1; i <= n; i++){
        if(a[i])modify(1, 1, n, i, a[i]); else s.insert(i);
        ll x = a[i];
        mx[x] = i;
        ll ku = i;
        mn[x] = min(mn[x], ku);
    }
    if(s.size() == n){
        cout << "YES\n";
        for(int i = 1; i <= n; i++)cout << m << " ";
        cout << "\n";
        return 0;
    }
    for(int i = 1; i <= m; i++){
        if(mn[i] == 1e18)continue;
        ll l = mn[i], r = mx[i];
        ll kek = get(1, 1, n, l, r);
        if(kek < i)vout("NO");
    }

    for(int i = m; i > 0; i--)if(mn[i] != 1e18)break; else {
        if(s.empty())vout("NO");
        ll pos = *(s.begin());
        a[pos] = i;
        s.erase(pos);
        break;
    }

    set <ll> :: iterator it;
    for(int i = m; i >= 1; i--){
        if(mn[i] == 1e18)continue;
        ll l = mn[i], r = mx[i];
        it = s.lower_bound(l);
        while(it != s.end() && *it <= r){
            modify(1, 1, n, *it, i);
            a[*it] = i;
            s.erase(it);
            it = s.lower_bound(l);
        }
    }


    for(int i = 1; i <= n; i++)if(!a[i] && a[i - 1])a[i] = a[i - 1];
    for(int i = n; i > 0; i--)if(!a[i] && a[i + 1])a[i] = a[i + 1];

    cout << "YES\n";
    for(int i = 1; i < n; i++)cout << a[i] << " ";
    cout << a[n] << "\n";
    return 0;
}