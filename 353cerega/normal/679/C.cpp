#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
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

inline ll pew(ll a, ll b, ll MOD)
{
    ll res = 1;
    while (b)
    {
        //if (b&1) res = mul(res,a);
        //a = mul(a,a);
        if (b&1) res = res*a%MOD;
        a = a*a%MOD;
        b /= 2;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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
}*/


int parent[1200001];
int rnk[1200001];
int sz[1200001];

void make_set (int v) {
    parent[v] = v;
    sz[v] = 1;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

//ll t[3200000];
//ll del[1200000];

/*
void build(int n)
{
    for (int i=0;i<=4*n;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] = (t[v]+val)%mod;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
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

ll get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);

}
*/



int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
    }
    vector<vector<ll>> pr(n,vector<ll>(n+1));
    for (ll i=0;i<n*n;i++) make_set(i);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++)
        {
            pr[i][j+1] = pr[i][j];
            if (s[i][j]=='.')
            {
                pr[i][j+1]++;
                if (i+1<n and s[i+1][j]=='.')
                {
                    union_sets(i*n+j,i*n+j+n);
                }
                if (j+1<n and s[i][j+1]=='.')
                {
                    union_sets(i*n+j,i*n+j+1);
                }
            }
        }
    }
    vector<ll> was(n*n);
    ll ans = 0;
    for (ll i=0;i<=n-k;i++)
    {
        vector<ll> val(n);
        for (ll j=0;j<n*n;j++) was[j] = 0;
        ll del = 0;
        for (ll j=0;j+1<k;j++)
        {
            for (ll z=i;z<i+k;z++)
            {
                if (s[z][j]=='X') continue;
                ll p = find_set(z*n+j);
                if (was[p]==0)
                {
                    del += sz[p];
                    was[p] = 2;
                }
            }
        }
        for (ll j=k-1;j<n;j++)
        {
            for (ll z=i;z<i+k;z++)
            {
                if (s[z][j]=='X') continue;
                ll p = find_set(z*n+j);
                if (was[p]==0)
                {
                    del += sz[p];
                    was[p] = 2;
                }
            }
            ll cur = k*k;
            for (ll z=i;z<i+k;z++)
            {
                cur -= pr[z][j+1]-pr[z][j-k+1];
            }
            vector<ll> kek;
            if (j!=n-1)
            {
                for (ll z=i;z<i+k;z++)
                {
                    if (s[z][j+1]=='X') continue;
                    ll p = find_set(z*n+j+1);
                    if (was[p]==0)
                    {
                        cur += sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                    if (was[p]==2)
                    {
                        cur += sz[p];
                        del -= sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                }
            }
            if (j!=k-1)
            {
                for (ll z=i;z<i+k;z++)
                {
                    if (s[z][j-k]=='X') continue;
                    ll p = find_set(z*n+j-k);
                    if (was[p]==0)
                    {
                        cur += sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                    if (was[p]==2)
                    {
                        cur += sz[p];
                        del -= sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                }
            }
            if (i!=0)
            {
                for (ll z=j-k+1;z<=j;z++)
                {
                    if (s[i-1][z]=='X') continue;
                    ll p = find_set((i-1)*n+z);
                    if (was[p]==0)
                    {
                        cur += sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                    if (was[p]==2)
                    {
                        cur += sz[p];
                        del -= sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                }
            }
            if (i!=n-k)
            {
                for (ll z=j-k+1;z<=j;z++)
                {
                    if (s[i+k][z]=='X') continue;
                    ll p = find_set((i+k)*n+z);
                    if (was[p]==0)
                    {
                        cur += sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                    if (was[p]==2)
                    {
                        cur += sz[p];
                        del -= sz[p];
                        was[p] = 1;
                        kek.push_back(p);
                    }
                }
            }
            ans = max(ans,cur+del);
            for (ll x: kek) was[x] = 0;
        }
    }
    cout << ans << endl;
}