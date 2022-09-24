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

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    return a*b%mod;
}

inline ll pew(ll a, ll b)
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
int parent[600001];
int rnk[600001];
int suk[600001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
    suk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b and (suk[a]*suk[b]==0)) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
        suk[a] += suk[b];
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
    ll n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<pair<ll,pair<ll,ll>>> ord;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            ord.push_back({a[i][j],{i,j}});
        }
    }
    sort(ord.begin(),ord.end());
    vector<ll> num(n);
    vector<vector<ll>> kek(n), ans(n);
    vector<ll> val(n);
    for (int i=0;i<n;i++)
    {
        num[i] = i;
        kek[i].push_back(i);
        ans[i].push_back(1);
    }
    vector<vector<pair<ll,ll>>> lul(n);
    vector<ll> pos(n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            lul[i].push_back({a[i][j],j});
        }
        sort(lul[i].begin(),lul[i].end());
    }
    for (int q=0;q<ord.size();q++)
    {
        int L = num[ord[q].Y.X];
        int R = num[ord[q].Y.Y];
        if (L==R) continue;
        if (L>R) swap(L,R);
        ll mx = max(val[L],val[R]);
        for (int i=0;i<kek[L].size();i++)
        {
            for (int j=0;j<kek[R].size();j++)
            {
                mx = max(mx,a[kek[L][i]][kek[R][j]]);
            }
        }
        val[L] = mx;
        for (int j=0;j<kek[R].size();j++)
        {
            num[kek[R][j]] = L;
        }
        int flag = 0;
        for (int i=0;i<kek[L].size();i++)
        {
            ll cur = kek[L][i];
            while (pos[cur]<n and num[lul[cur][pos[cur]].Y]==L) pos[cur]++;
            if (pos[cur]<n and lul[cur][pos[cur]].X<val[L])
            {
                flag = 1;
            }
        }
        for (int j=0;j<kek[R].size();j++)
        {
            ll cur = kek[R][j];
            while (pos[cur]<n and num[lul[cur][pos[cur]].Y]==L) pos[cur]++;
            if (pos[cur]<n and lul[cur][pos[cur]].X<val[L])
            {
                flag = 1;
            }
        }
        ll sz1 = kek[L].size();
        ll sz2 = kek[R].size();
        vector<ll> nxt(sz1+sz2);
        nxt[0] = 1-flag;
        for (int i=0;i<sz1;i++)
        {
            for (int j=0;j<sz2;j++)
            {
                nxt[i+j+1] = (nxt[i+j+1]+ans[L][i]*ans[R][j])%mod;
            }
        }
        for (int j=0;j<sz2;j++)
        {
            kek[L].push_back(kek[R][j]);
        }
        ans[L] = nxt;
    }
    for (int i=0;i<n;i++)
    {
        cout << ans[0][i] << " ";
    }
    cout << endl;
}