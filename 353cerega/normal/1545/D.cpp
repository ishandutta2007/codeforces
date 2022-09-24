#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;

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

//ll t[3200000];
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

/*void update (int v, int tl, int tr, int p, ll val) {
    t[v] += val;
    if (tl==tr) return;
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
    if (p<=tm) update(2*v,tl,tm,p,val);
    else update(2*v+1,tm+1,tr,p,val);
}

ll get (int v, int tl, int tr, int l, int r) {
    if (tl==l and tr==r) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/

int m, n;

vector<vector<int>> a;
vector<ll> S;
ll D;
int w = -1;
ll del = 0;

bool rec(int u)
{
    int s = 0;
    if (w==0) s = 1;
    int val = a[w][u]+del;
    ll R = w-s;
    ll R2 = abs(R);
    for (int j=0;j<m;j++)
    {
        if ((val-a[s][j])%R2!=0) continue;
        ll V = (val-a[s][j])/R;
        if (V<=0 or V>1000 or a[s][j]+(n-1-s)*V>1000000) continue;
        for (int i=0;i<n;i++)
        {
            if (i==w) continue;
            ll x = a[s][j]+(i-s)*V;
            int l = 0;
            int r = m;
            while (r-l>1)
            {
                int q = (l+r)/2;
                if (a[i][q]>x) r = q;
                else l = q;
            }
            if (a[i][l]!=x) break;
            if (i==n-1) return true;
        }
    }
    return false;
}

void check()
{
    vector<int> pr(m,1);
    for (int s=0;s<n;s++)
    {
        if (s==w) continue;
        int R = w-s;
        if (R<0) R *= -1;
        if (del%R==0) continue;
        vector<int> cnt(R);
        for (int i=0;i<m;i++)
        {
            cnt[a[w][i]%R]++;
            cnt[a[s][i]%R]--;
        }
        for (int i=0;i<m;i++)
        {
            if (cnt[a[w][i]%R]<=0) pr[i] = 0;
        }
    }
    for (int j=0;j<m;j++)
    {
        if (pr[j]==1)
        {
            if (rec(j))
            {
                cout << w << " " << a[w][j]+del << endl;
                return;
            }
        }
    }
}

vector<ll> S2;

void check2()
{
    S2.resize(n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            S2[i] += a[i][j]*a[i][j];
        }
    }
    int q = 0;
    if (w<3) q = n-3;
    ll A = S2[q+1]-S2[q];
    ll B = S2[q+2]-S2[q];
    A = B/2-A;
    B = B/4-A;
    swap(A,B);
    for (int j=0;j<m;j++)
    {
        ll C = S2[w];
        C -= a[w][j]*a[w][j];
        C += (a[w][j]+del)*(a[w][j]+del);
        ll R = w-q;
        if (C==S2[q]+B*R*R+2*R*A)
        {
            cout << w << " " << a[w][j]+del << endl;
            return;
        }
    }
}

void solve()
{
    cin >> m >> n;
    a.resize(n,vector<int>(m));
    S.resize(n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> a[i][j];
            S[i] += a[i][j];
        }
        sort(a[i].begin(),a[i].end());
    }
    D = S[n-1]-S[n-2];
    ll D2 = S[1]-S[0];
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i=0;i+1<n;i++)
    {
        if (S[i+1]-S[i]==D) cnt1++;
        if (S[i+1]-S[i]==D2) cnt2++;
    }
    if (cnt1<cnt2) swap(D,D2);
    for (int j=1;j+1<n;j++)
    {
        if (S[j+1]-S[j]!=D and S[j]-S[j-1]!=D)
        {
            w = j;
        }
    }
    if (w==-1)
    {
        if (S[1]-S[0]!=D) w = 0;
        else w = n-1;
    }
    if (w!=0) del = D-(S[w]-S[w-1]);
    else del = S[w+1]-S[w]-D;
    check2();
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
}