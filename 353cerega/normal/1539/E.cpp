#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

const ll mod = 1000000007;

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


int parent[600001];
int rnk[600001];

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
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

//ll t[1200000];
//ll del[1200000];

/*void build(int n)
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

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl>=l and tr<=r)
    {
        del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
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
    t[v] = t[2*v]+t[2*v+1];
}*/


/*pair<ll,ll> get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> prv(2,vector<int>(n+1,-1));
    set<pair<int,int>> L, R;
    L.insert({0,0});
    R.insert({0,0});
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        int L1, R1, L2, R2;
        cin >> L1 >> R1 >> L2 >> R2;
        auto it = L.begin();
        while (it!=L.end())
        {
            if (it->X<L1)
            {
                L.erase(it);
                it = L.begin();
                continue;
            }
            break;
        }
        it = L.end();
        while (it!=L.begin())
        {
            it--;
            if (it->X>R1)
            {
                L.erase(it);
                it = L.end();
                continue;
            }
            break;
        }
        it = R.begin();
        while (it!=R.end())
        {
            if (it->X<L2)
            {
                R.erase(it);
                it = R.begin();
                continue;
            }
            break;
        }
        it = R.end();
        while (it!=R.begin())
        {
            it--;
            if (it->X>R2)
            {
                R.erase(it);
                it = R.end();
                continue;
            }
            break;
        }
        int ok = 0;
        int u1 = -1;
        if (R.size()>0) u1 = R.begin()->Y;
        int u2 = -1;
        if (L.size()>0) u2 = L.begin()->Y;
        if (x<L1 or x>R1) R.clear();
        if (x<L2 or x>R2) L.clear();
        if (x>=L1 and x<=R1)
        {
            if (u1!=-1)
            {
                ok = 1;
                L.insert({x,i});
                prv[0][i] = u1;
            }
        }
        if (x>=L2 and x<=R2)
        {
            if (u2!=-1)
            {
                ok = 1;
                R.insert({x,i});
                prv[1][i] = u2;
            }
        }
        if (ok==0)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    int cur = n;
    int q = 0;
    if (prv[q][cur]==-1) q = 1;
    vector<int> ans(n);
    while (cur>0)
    {
        int nxt = prv[q][cur];
        while (cur>nxt)
        {
            cur--;
            ans[cur] = q;
        }
        q = 1-q;
    }
    for (int i=0;i<n;i++) cout << ans[i] << " ";
}