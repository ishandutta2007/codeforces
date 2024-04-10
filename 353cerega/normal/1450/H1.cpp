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


ll t[1200000];

void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 100000000;
    }
}

void update (int v, int tl, int tr, int pos, ll val) {
    if (tl==tr)
    {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (tm>=pos)
    {
        update(v * 2, tl, tm, pos, val);
    } else
    {
        update (v*2+1, tm+1, tr, pos, val);
    }
    t[v] = min(t[v*2],t[v*2+1]);
}

ll get (int v, int tl, int tr, int l, int r) {
    if (tl == l and tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return min(get(2*v,tl,tm,l,tm),get(2*v+1,tm+1,tr,tm+1,r));
}

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

const ll root = 31;
ll root_1 = -1;
const ll root_pw = 1<<23;

void fft (vector<ll> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pew(n, mod-2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    root_1 = pew(root,mod-2);
    cin >> n >> m;
    string s;
    cin >> s;
    ll cnt = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='w')
        {
            if (i%2==0)
            {
                cnt++;
            } else
            {
                cnt--;
            }
        }
        if (s[i]=='?')
        {
            if (i%2==0)
            {
                cnt1++;
            } else
            {
                cnt2++;
            }
        }
    }
    if (cnt<0)
    {
        cnt *= -1;
        swap(cnt1,cnt2);
    }
    ll obr2 = pew(2,mod-2);
    ll q = pew(obr2,cnt1+cnt2-1);
    vector<ll> a(cnt1+1), b(cnt2+1);
    vector<ll> f(max(cnt1,cnt2)+1),obrf(max(cnt1,cnt2)+1);
    f[0] = 1;
    obrf[0] = 1;
    for (int i=1;i<=cnt1 or i<=cnt2;i++)
    {
        f[i] = f[i-1]*i%mod;
        obrf[i] = pew(f[i],mod-2);
    }
    for (int i=0;i<=cnt1;i++)
    {
        a[i] = f[cnt1]*obrf[i]%mod*obrf[cnt1-i]%mod;
    }
    for (int i=0;i<=cnt2;i++)
    {
        b[i] = f[cnt2]*obrf[i]%mod*obrf[cnt2-i]%mod;
    }
    while (a.size()<(1<<19))
    {
        a.push_back(0);
    }
    while (b.size()<(1<<19))
    {
        b.push_back(0);
    }
    fft(a,false);
    fft(b,false);

    for (int i=0;i<(1<<19);i++)
    {
        a[i] *= b[i];
        a[i] %= mod;
    }
    fft(a,true);
    ll ans = 0;
    for (ll i=0;i<(1<<19);i++)
    {
        if (i%2 != (cnt2+cnt)%2) continue;
        ans += abs(i-cnt2+cnt)*a[i]%mod;
    }
    ans %= mod;
    ans = ans*q%mod*obr2%mod;
    cout << ans << endl;
}