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
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll p[4 * MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p[v] = val; else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return p[v];
    ll tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll d;
    cin >> n >> m >> d;
    for(i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    modify(1, 1, n, 1, 1);
    ll uk = 1;
    for(i = m; i <= n; i++){
            while(a[i] - a[uk] > d)uk++;
            ll l = uk, r = i - m + 1;
            sc = get(1, 1, n, l, r);
            if(n == i){
                if(sc == 1)vout("YES");
                vout("NO");
            }
            modify(1, 1, n, i + 1, sc);
    }
    return 0;
}