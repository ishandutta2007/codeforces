#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

template <typename T>
T sqr(T x)
{
    return x * x;
}

template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}

ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}

const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll p1[MAXN],p[MAXN];
void push(ll v,ll tl,ll tr){
    ll tm = (tl + tr) / 2;
    p[v * 2] += p1[v] * (tm - tl + 1);
    p[v * 2 + 1] += p1[v] * (tr - tm);
    p1[v * 2] += p1[v];
    p1[v * 2 + 1] += p1[v];
    p1[v] = 0;
    return;
}
void modify(ll v, ll tl, ll tr, ll l,ll r,ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        p1[v] += val;
        p[v] += (tr - tl + 1) * val;
        return;
    }
    push(v,tl,tr);
    ll tm = (tl + tr) / 2;
    modify(v *  2, tl , tm, l, min(r,tm),val);
    modify(v *  2 + 1, tm + 1 , tr, max(l , tm + 1),r,val);
    p[v] = p[v * 2] + p[v * 2 + 1];
}
ll get(ll v,ll tl,ll tr,ll pos){
    if(tl == tr)return p[v];
    push(v,tl,tr);
    ll tm = (tl + tr) / 2;
    if(pos <= tm)get(v * 2, tl, tm, pos);else get(v * 2 + 1, tm + 1, tr , pos);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    cin >> a1 >> b1;
    for(i = 1; i <= n; i++){
        ll l = (a1 - i + 1) + n, r = (b1 - i + 1) + n;
        if(l > n) l -= n;
        if(r > n) r -= n;
       // cout << i << " " << l << " " << r << endl;
        if(l >= r){
            modify(1, 1, n, l, n, a[i]);
            if(r != 1)modify(1, 1, n, 1, r - 1, a[i]);
        }else
        {
            if(r != 1) modify(1, 1, n, l, r - 1, a[i]);else
                modify(1, 1, n, l, n, a[i]);
        }
    }
    ll mx = -1e18, mxj;
    for(i = 1; i <= n; i++){
        x = get(1,1,n,i);
            //cout << i << " " << x << endl;
        if(mx < x){
            mx = x;
            mxj = i;
        }
    }
    //cout << mx << endl;
    cout << mxj << endl;
    return 0;
}