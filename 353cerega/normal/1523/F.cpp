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

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
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
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
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
    //t[v] = min(t[2*v],t[2*v+1]);
}


ll get (int v, int tl, int tr, int p) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==tr)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> c1(n), c2(m);
    vector<int> t(m);
    for (int i=0;i<n;i++) cin >> c1[i].X >> c1[i].Y;
    for (int i=0;i<m;i++) cin >> c2[i].X >> c2[i].Y >> t[i];
    for (int i=0;i<m;i++)
    {
        for (int j=i+1;j<m;j++)
        {
            if (t[i]>t[j])
            {
                swap(t[i],t[j]);
                swap(c2[i],c2[j]);
            }
        }
    }
    int n2 = (1<<n);
    int INF = 1000010000;
    vector<vector<int>> d11(n2,vector<int>(n,INF)), d12(n2,vector<int>(m,INF));
    vector<vector<int>> d21(m,vector<int>(n,INF)), d22(m,vector<int>(m,INF));
    for (int msk=1;msk<n2;msk++)
    {
        for (int b=0;b<n;b++)
        {
            if ((1<<b)&msk) continue;
            for (int b2=0;b2<n;b2++)
            {
                if (((1<<b2)&msk)==0) continue;
                d11[msk][b] = min(d11[msk][b],abs(c1[b].X-c1[b2].X)+abs(c1[b].Y-c1[b2].Y));
            }
        }
        for (int b=0;b<n;b++)
        {
            if (((1<<b)&msk)==0) continue;
            for (int k=0;k<m;k++)
            {
                d12[msk][k] = min(d12[msk][k],abs(c1[b].X-c2[k].X)+abs(c1[b].Y-c2[k].Y));
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            d21[i][j] = abs(c1[j].X-c2[i].X)+abs(c1[j].Y-c2[i].Y);
        }
        for (int j=0;j<m;j++)
        {
            d22[i][j] = abs(c2[j].X-c2[i].X)+abs(c2[j].Y-c2[i].Y);
        }
    }
    int ans = 0;
    vector<vector<int>> dp2(n2,vector<int>(m,-1));
    vector<vector<int>> dp1(n2,vector<int>(m+1,INF));
    for (int i=0;i<m;i++) dp2[0][i] = 1;
    for (int i=0;i<n;i++) dp1[1<<i][0] = 0;
    for (int msk=0;msk<n2;msk++)
    {
        int k = 0;
        int i = 0;
        while (i<m or k<=m)
        {
            if (k==m+1 or (i!=m and t[i]<=dp1[msk][k]))
            {
                if (dp2[msk][i]==-1)
                {
                    i++;
                    continue;
                }
                int cur = dp2[msk][i];
                ans = max(ans,cur);
                for (int j=i+1;j<m;j++)
                {
                    if (t[j]-t[i]>=min(d22[i][j],d12[msk][j]))
                    {
                        dp2[msk][j] = max(dp2[msk][j],cur+1);
                    }
                }
                dp1[msk][cur] = min(dp1[msk][cur],t[i]);
                for (int j=0;j<n;j++)
                {
                    if (msk&(1<<j)) continue;
                    dp1[msk+(1<<j)][cur] = min(dp1[msk+(1<<j)][cur],t[i]+d21[i][j]);
                }
                i++;
            } else
            {
                int T = dp1[msk][k];
                if (T>=INF)
                {
                    k++;
                    continue;
                }
                for (int j=0;j<n;j++)
                {
                    if (msk&(1<<j)) continue;
                    if (msk==0) continue;
                    dp1[msk+(1<<j)][k] = min(dp1[msk+(1<<j)][k],T+d11[msk][j]);
                }
                for (int j=0;j<m;j++)
                {
                    if (d12[msk][j]+T<=t[j])
                    {
                        dp2[msk][j] = max(dp2[msk][j],k+1);
                    }
                }
                k++;
            }
        }
    }
    cout << ans << endl;
}