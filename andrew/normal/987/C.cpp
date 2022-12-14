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

vector <ll> v[MAXN],va;
string s1,s2,s3;
map <ll, ll> mp;
map <ll, ll> mp1;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll p[MAXN], p1[MAXN], sm[MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        p[v] = c[tl];
        p1[v] = 1e18;
    } else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
        p1[v] = min(p1[(v << 1) + 1], p1[v << 1]);
    }
}

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        p1[v] = min(p1[v], val);
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
        p1[v] = min(p1[(v << 1) + 1], p1[v << 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return p1[v];
    ll tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i], s.insert(a[i]);
    for(i = 1; i <= n; i++){
        cin >> x;
        b[i] = x;
        if(!mp1[a[i]] || mp1[a[i]] > x)mp1[a[i]] = x;
    }
    s.insert(-1e18);
    s.insert(1e18);
    m = s.size();
    set <ll> :: iterator it = s.begin();
    i = 0;
    for(; it != s.end(); ++it){
        ++i;
        c[i] = *it;
        mp[*it] = i;
    }
    build(1, 1, m);
    modify(1, 1, m, 1, 1e18);
    modify(1, 1, m, m, 1e18);
    ans = 1e18;
    for(i = 1; i <= n; i++){
        modify(1, 1, m, mp[a[i]], b[i]);
        sm[i] = get(1, 1, m, 1, mp[a[i]] - 1);
    }
    build(1, 1, m);
    modify(1, 1, m, 1, 1e18);
    modify(1, 1, m, m, 1e18);
    for(i = n; i >= 1; i--){
        modify(1, 1, m, mp[a[i]], b[i]);
        //cout << i << " " << sm[i] << " " << get(1, 1, m, a[i]) << " " << b[i] << " " << mp[a[i]] << endl;
        ans = min(ans, sm[i] + get(1, 1, m, mp[a[i]] + 1, m) + b[i]);
    }
    if(ans == 1e18)vout(-1);
    vout(ans);
    return 0;
}