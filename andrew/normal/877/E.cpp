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
set <ll> s;
char cc;
ll b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll a[MAXN];
ll p[MAXN],p1[MAXN];
ll le[MAXN], ri[MAXN];
ll vh, vih;
void push(ll v, ll tl, ll tr){
    if(p1[v]){
        ll tm = (tl + tr) / 2;
        p[v * 2] = (tm - tl + 1) - p[v * 2];
        p[v * 2 + 1] = (tr - tm) - p[v * 2 + 1];
        p1[v * 2] = (p1[v * 2] + 1) % 2;
        p1[v * 2 + 1] = (p1[v * 2 + 1] + 1) % 2;
        p1[v] = 0;
    }
}
void build(ll v, ll tl, ll tr){
    if(tl == tr)p[v] = a[tl]; else{
        ll tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        p[v] = p[v * 2] + p[v * 2 + 1];
    }
}
void modify(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(tl == l && tr == r){
        p[v] = (tr - tl + 1) - p[v];
        p1[v] = (p1[v] + 1 ) % 2;
        return;
    }
    push(v, tl, tr);
    ll tm = (tl + tr) / 2;
    modify(v * 2, tl, tm, l, min(r, tm));
    modify(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    p[v] = p[v * 2] + p[v * 2 + 1];
    return;
}
ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return p[v];
    push(v, tl, tr);
    ll tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void dfs(ll x, ll pr){
    vh++;
    le[x] = vh;
    a[vh] = b[x];
    ll i, nn = v[x].size();
    for(i = 0; i < nn; i++)if(v[x][i] != pr)dfs(v[x][i], x);
    ri[x] = vh;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 2; i <= n; i++){
        cin >> x;
        v[x].p_b(i);
    }
    for(i = 1; i <= n; i++)cin >> b[i];
    dfs(1, 0);
    build(1,1,n);
    ll q;
    cin >> q;
    while(q--){
        cin >> s1 >> x;
        ll l = le[x], r = ri[x];
        if(s1 == "get")cout << get(1,1,n,l,r) << endl;else modify(1,1,n,l,r);
    }
    return 0;
}