#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = double;
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


/*void update (int v, int tl, int tr, int pos, ll val) {
    if (tl==tr)
    {
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (pos<=tm)
    {
        update(2*v,tl,tm,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    else
    {
        update(2*v+1,tm+1,tr,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    //update(2*v,tl,tm,l,tm,val);
    //update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}



ll get (int v, int tl, int tr, int l, int r) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/


const ll M = 100;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<pair<ll,ll>> h(n), w(n);
    for (int i=0;i<n;i++)
    {
        cin >> w[i].X;
        w[i].Y = i;
    }
    sort(w.begin(),w.end());
    for (int i=0;i<n;i++)
    {
        cin >> h[i].X;
        h[i].Y = i;
    }
    sort(h.begin(),h.end());
    vector<ll> pos(n), p(n);
    for (int i=0;i<n;i++)
    {
        pos[w[i].Y] = i;
    }
    for (int i=0;i<n;i++)
    {
        p[pos[h[i].Y]] = i;
    }
    ll S = n/M;
    if (n%M!=0) S++;
    vector<ll> msk = {3,5,9,6,10,12};
    vector<vector<ll>> nxt(6), a(6);
    for (int i=0;i<6;i++)
    {
        int cur = msk[i];
        vector<int> b(5);
        int x = 1;
        for (int j=0;j<4;j++)
        {
            if (cur&(1<<j))
            {
                b[3-j] = 1;
                x += (1<<(j+1));
            }
        }
        b[4] = 1;
        for (int j=0;j<5;j++)
        {
            if (b[j]==0) continue;
            int v = x-(1<<(4-j));
            if (v<16)
            {
                for (int g=0;g<6;g++)
                {
                    if (msk[g]==v) nxt[i].push_back(g);
                }
                a[i].push_back(j-2);
            }
        }
    }
    vector<ll> H(n), W(n);
    for (int i=0;i<n;i++)
    {
        W[i] = w[i].X;
        H[i] = h[i].X;
    }
    ll INF = 1000000000LL*1000000000LL;
    vector<vector<vector<ll>>> dp(36,vector<vector<ll>>(S,vector<ll>(M+1,-INF)));
    for (int k=0;k<S;k++)
    {
        for (int i=0;i<6;i++)
        {
            dp[i*7][k][0] = 0;
        }
        for (int st=0;st<6;st++)
        for (int i=0,z=k*M;i<M and z<n;i++,z++)
        {
            for (int j=0;j<6;j++)
            {
                for (int s=0;s<nxt[j].size();s++)
                {
                    if (a[j][s]+z<0) continue;
                    if (a[j][s]+z>=n) continue;
                    if (a[j][s]+z==p[z]) continue;
                    dp[st+nxt[j][s]*6][k][i+1] = max(dp[st+nxt[j][s]*6][k][i+1],dp[st+j*6][k][i]+W[z]*H[a[j][s]+z]);
                }
            }
        }
        if (k==S-1)
        {
            for (int i=0;i<36;i++)
            {
                dp[i][k][M] = dp[i][k][n-k*M];
            }
        }
    }
    while (q--) {
        ll A, B;
        cin >> A >> B;
        A--, B--;
        A = pos[A];
        B = pos[B];
        swap(p[A], p[B]);
        ll k = A / M;
        for (int i = 0; i < 36; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][k][j] = -INF;
            }
        }
        for (int i = 0; i < 6; i++) {
            dp[i * 7][k][0] = 0;
        }
        for (int st = 0; st < 6; st++){
            for (ll i = 0, z = k * M; i < M and z < n; i++, z++) {
                for (int j = 0; j < 6; j++) {
                    for (int s = 0; s < nxt[j].size(); s++) {
                        if (a[j][s] + z < 0) continue;
                        if (a[j][s] + z >= n) continue;
                        if (a[j][s] + z == p[z]) continue;
                        dp[st + nxt[j][s] * 6][k][i + 1] = max(dp[st + nxt[j][s] * 6][k][i + 1],
                                                               dp[st + j * 6][k][i] + W[z] * H[a[j][s] + z]);
                    }
                }
            }
        }
        if (k==S-1)
        {
            for (int i=0;i<36;i++)
            {
                dp[i][k][M] = dp[i][k][n-k*M];
            }
        }
        k = B/M;
        for (int i=0;i<36;i++)
        {
            for (int j=0;j<=M;j++)
            {
                dp[i][k][j] = -INF;
            }
        }
        for (int i=0;i<6;i++)
        {
            dp[i*7][k][0] = 0;
        }
        for (int st = 0; st < 6; st++){
            for (ll i = 0, z = k * M; i < M and z < n; i++, z++) {
                for (int j = 0; j < 6; j++) {
                    for (int s = 0; s < nxt[j].size(); s++) {
                        if (a[j][s] + z < 0) continue;
                        if (a[j][s] + z >= n) continue;
                        if (a[j][s] + z == p[z]) continue;
                        dp[st + nxt[j][s] * 6][k][i + 1] = max(dp[st + nxt[j][s] * 6][k][i + 1],
                                                               dp[st + j * 6][k][i] + W[z] * H[a[j][s] + z]);
                    }
                }
            }
        }
        if (k==S-1)
        {
            for (int i=0;i<36;i++)
            {
                dp[i][k][M] = dp[i][k][n-k*M];
            }
        }
        vector<ll> cur(6,-INF);
        cur[0] = 0;
        for (int i=0;i<S;i++)
        {
            vector<ll> lul(6,-INF);
            for (int prv=0;prv<6;prv++)
            {
                for (int x=0;x<6;x++)
                {
                    lul[x] = max(lul[x],cur[prv]+dp[prv+x*6][i][M]);
                }
            }
            cur = lul;
        }
        cout << cur[0] << "\n";
    }
}