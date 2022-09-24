#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
#define X first
#define Y second
 
ll mod = 998244353;
 
ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}
 
ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
    return a;
}
 
ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}
 
ll mul(ll a, ll b)
{
    return a*b%mod;
}
 
ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}
 
/*
typedef complex<double> base;
long double PI = acos(-1);
const ll root = 31;
const ll root_pw = 1<<23;
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;
 
    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);
 
    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
*/
int parent[100001];
int rnk[100001];
 
void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}
 
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}
 
/*
ll t[1200000];
 
void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
    }
}
 
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
}
 
ll get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos<=tm) return get(2*v,tl,tm,pos)+t[v];
    if (pos>tm) return get(2*v+1,tm+1,tr,pos)+t[v];
}*/
 
/*
ll base = 1000000000;
 
vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
 
vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
 
vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
*/
 
 
int main() {
    ios_base::sync_with_stdio(false);
    ll mod2 = 1000000007LL;
    ll n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    cin >> t;
    ll cur = s.length();
    ll mx = 1000005;
    ll mx2 = 1000005;
    for (int i=0;i<n;i++)
    {
        cur = cur*2+1;
        if (cur>mx)
        {
            break;
        }
    }
    if (cur<mx) mx = cur;
    vector<pair<ll,ll>> hash(mx+1), hash2(mx+1);
    vector<ll> b(mx2), b2(mx2);
    b[0] = 1;
    b2[0] = 1;
    b[1] = 29;
    b2[1] = 41;
    string pr = s;
    string suk = s;
    reverse(suk.begin(),suk.end());
    cur = 0;
    while (pr.length()<mx)
    {
        pr = pr+t[cur]+pr;
        suk = suk+t[cur]+suk;
        cur++;
    }
    for (ll i=2;i<mx2;i++)
    {
        b[i] = b[i-1]*29%mod;
        b2[i] = b2[i-1]*41%mod2;
    }
    for (int i=0;i<mx;i++)
    {
        hash[i+1].X = (hash[i].X+b[i]*(pr[i]-'a'))%mod;
        hash[i+1].Y = (hash[i].Y+b2[i]*(pr[i]-'a'))%mod2;
        hash2[i+1].X = (hash2[i].X+b[i]*(suk[i]-'a'))%mod;
        hash2[i+1].Y = (hash2[i].Y+b2[i]*(suk[i]-'a'))%mod2;
    }
    vector<ll> len(n+1);
    len[0] = s.length();
    for (ll i=0;i<n;i++)
    {
        len[i+1] = min(mx+1,len[i]*2+1);
    }
    vector<ll> p2(n+1);
    p2[0] = 1;
    for (ll i=1;i<=n;i++)
    {
        p2[i] = p2[i-1]*2%mod2;
    }
    vector<vector<ll>> cnt(n+1,vector<ll>(26));
    for (int i=20;i<n;i++)
    {
        for (int j=0;j<26;j++)
        {
            cnt[i][j] = cnt[i-1][j]*2%mod2;
        }
        cnt[i][t[i]-'a']++;
        cnt[i][t[i]-'a'] %= mod2;
    }
    while (q--)
    {
        ll ans = 0;
        ll k;
        string w;
        cin >> k >> w;
        ll m = w.length();
        if (m<=len[0])
        {
            for (int i=0;i<len[0]-m+1;i++)
            {
                int flag = 0;
                for (int j=0;j<m;j++)
                {
                    if (s[j+i]!=w[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag==0)
                {
                    ans = (ans + p2[k])%mod2;
                }
            }
        }
        vector<pair<ll,ll>> curh(m+1), curh2(m+1);
        for (int i=0;i<m;i++)
        {
            curh[i+1].X = (curh[i].X+b[i]*(w[i]-'a'))%mod;
            curh[i+1].Y = (curh[i].Y+b2[i]*(w[i]-'a'))%mod2;
            curh2[i+1].X = (curh2[i].X+b[i]*(w[m-1-i]-'a'))%mod;
            curh2[i+1].Y = (curh2[i].Y+b2[i]*(w[m-1-i]-'a'))%mod2;
        }
        for (int pos=0;pos<m;pos++)
        {
            ll L = pos;
            ll R = m-pos-1;
            for (int i=0;i<k and i<20;i++)
            {
                if (L>len[i] or R>len[i]) continue;
                if (t[i]!=w[pos]) continue;
                if (hash[R].X*b[pos+1]%mod==(curh[m].X-curh[pos+1].X+mod)%mod and hash[R].Y*b2[pos+1]%mod2==(curh[m].Y-curh[pos+1].Y+mod2)%mod2)
                {
                    if (hash2[L].X*b[m-pos]%mod==(curh2[m].X-curh2[m-pos].X+mod)%mod and hash2[L].Y*b2[m-pos]%mod2==(curh2[m].Y-curh2[m-pos].Y+mod2)%mod2)
                        ans = (ans+p2[k-1-i])%mod2;
                }
            }
            if (k>=20)
            {
                if (hash[R].X*b[pos+1]%mod==(curh[m].X-curh[pos+1].X+mod)%mod and hash[R].Y*b2[pos+1]%mod2==(curh[m].Y-curh[pos+1].Y+mod2)%mod2) {
                    if (hash2[L].X * b[m - pos] % mod == (curh2[m].X - curh2[m - pos].X + mod) % mod and hash2[L].Y * b2[m - pos] % mod2 == (curh2[m].Y - curh2[m - pos].Y + mod2) % mod2)
                        ans = (ans+cnt[k-1][w[pos]-'a'])%mod2;
                }
            }
        }
        cout << ans << endl;
    }
}