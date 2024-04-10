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

vector <ll> p[800001],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
void build(ll v, ll tl, ll tr){
    if(tl == tr)p[v].p_b(a[tl]); else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        p[v] = p[v << 1];
        ll i, nn = p[(v << 1 )+ 1].size();
        for(i = 0; i < nn; i++)p[v].p_b(p[(v << 1) + 1][i]);
        sort(all(p[v]));
    }
}
ll get(ll v, ll tl, ll tr, ll l, ll r, ll k){
    if(l > r)return 0;
    if(tl == l && tr == r){
        if(lower_bound(all(p[v]),k) == p[v].end())return 0;
        ll ke = lower_bound(all(p[v]), k) - p[v].begin();
        return p[v].size() - ke;
    }
    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm), k) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, k);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    build(1, 1, n);
    for(i = 1; i <= n; i++){
        ll l = 1, r = max(0ll, min(i - 1, a[i]));
        ans += get(1, 1, n, l, r, i);
    }
    vout(ans);
    return 0;
}