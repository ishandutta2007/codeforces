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
const int root = 30;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/

/*
void fft (vector<int> & a, bool invert) {
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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    vector<pair<pair<ll,ll>,ll>> ordx(n), ordy(n);
    vector<vector<ll>> nxt(n,vector<ll>(4,-1));
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].X >> a[i].Y;
        ordx[i].Y = i;
        ordy[i].Y = i;
        ordx[i].X = a[i];
        ordy[i].X = {a[i].Y,a[i].X};
    }
    sort(ordx.begin(),ordx.end());
    sort(ordy.begin(),ordy.end());
    vector<pair<ll,pair<ll,ll>>> ord;
    for (ll i=0;i+1<n;i++)
    {
        if (ordx[i].X.X==ordx[i+1].X.X)
        {
            ord.push_back({ordx[i+1].X.Y-ordx[i].X.Y,{ordx[i+1].Y,ordx[i].Y}});
            nxt[ordx[i].Y][0] = ordx[i+1].Y;
            nxt[ordx[i+1].Y][1] = ordx[i].Y;
        }
        if (ordy[i].X.X==ordy[i+1].X.X)
        {
            ord.push_back({ordy[i+1].X.Y-ordy[i].X.Y,{ordy[i+1].Y,ordy[i].Y}});
            nxt[ordy[i].Y][2] = ordy[i+1].Y;
            nxt[ordy[i+1].Y][3] = ordy[i].Y;
        }
    }
    sort(ord.begin(),ord.end());
    ll sz = n;
    for (ll i=0;i<n;i++) make_set(i);
    vector<ll> pos;
    vector<ll> num(n,-1);
    ll W = 0;
    if (n<=4)
    {
        W = n;
        for (ll i=0;i<n;i++)
        {
            if (parent[i]==i)
            {
                num[i] = pos.size();
                pos.push_back(i);
            }
        }
        for (ll i=0;i<n;i++)
        {
            if (num[i]==-1) num[i] = num[find_set(i)];
        }
    }
    ll C = 0;
    ll A = mod*mod;
    vector<pair<ll,pair<ll,ll>>> e;
    for (ll z=0;z<ord.size();z++)
    {
        ll u = ord[z].Y.X;
        ll v = ord[z].Y.Y;
        if (find_set(u)==find_set(v)) continue;
        union_sets(u,v);
        sz--;
        if (sz>=4) C = ord[z].X;
        if (sz==4)
        {
            W = 4;
            for (ll i=0;i<n;i++)
            {
                if (parent[i]==i)
                {
                    num[i] = pos.size();
                    pos.push_back(i);
                }
            }
            for (ll i=0;i<n;i++)
            {
                if (num[i]==-1) num[i] = num[find_set(i)];
            }
        }
        if (sz<4) e.push_back(ord[z]);
    }

    if (sz==1) A = e.back().X;
    if (sz>4)
    {
        cout << -1 << endl;
        return 0;
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++)
        {
            if (i==j) continue;
            if (a[i].X==a[j].X and a[i].Y>a[j].Y) continue;
            if (a[i].Y==a[j].Y and a[i].X>a[j].X) continue;
            vector<ll> q(W);
            ll Q = W;
            for (ll z=0;z<W;z++) q[z] = z;
            ll u = q[num[i]];
            ll v = q[num[j]];
            if (u!=v) Q--;
            for (ll z=0;z<W;z++) if (q[z]==v) q[z] = u;
            if (a[i].X==a[j].X or a[i].Y==a[j].Y)
            {
                ll L = a[j].Y+a[j].X-a[i].Y-a[j].X;
                L = L/2+L%2;
                L = max(L,C);
                for (ll z=0;z<W;z++) if (q[z]==v) q[z] = u;
                if (Q==1)
                {
                    A = min(A,L);
                    continue;
                }
                for (ll z=0;z<e.size();z++)
                {
                    L = max(L,e[z].X);
                    u = q[num[e[z].Y.X]];
                    v = q[num[e[z].Y.Y]];
                    if (u==v) continue;
                    Q--;
                    for (ll p=0;p<W;p++) if (q[p]==v) q[p] = u;
                    if (Q==1)
                    {
                        A = min(A,L);
                        break;
                    }
                }
                continue;
            }
            ll L = C;
            L = max(L,abs(a[j].Y-a[i].Y));
            L = max(L,abs(a[j].X-a[i].X));
            vector<pair<ll,pair<ll,ll>>> e2;
            if (a[j].Y>a[i].Y)
            {
                if (nxt[i][0]!=-1 and a[nxt[i][0]].Y>a[j].Y) e2.push_back({a[nxt[i][0]].Y-a[j].Y,{i,nxt[i][0]}});
            } else
            {
                if (nxt[i][1]!=-1 and a[nxt[i][1]].Y<a[j].Y) e2.push_back({-a[nxt[i][1]].Y+a[j].Y,{i,nxt[i][1]}});
            }
            if (a[j].X<a[i].X)
            {
                if (nxt[j][2]!=-1 and a[nxt[j][2]].X>a[i].X) e2.push_back({a[nxt[j][2]].X-a[i].X,{i,nxt[j][2]}});
            } else
            {
                if (nxt[j][3]!=-1 and a[nxt[j][3]].X<a[i].X) e2.push_back({-a[nxt[j][3]].X+a[i].X,{i,nxt[j][3]}});
            }
            sort(e2.begin(),e2.end());
            if (Q==1)
            {
                A = min(A,L);
                continue;
            }
            ll z = 0, z2 = 0;
            while (z<e.size() or z2<e2.size())
            {
                if (z2==e2.size() or (z<e.size() and e[z].X<=e2[z2].X))
                {
                    L = max(L,e[z].X);
                    u = q[num[e[z].Y.X]];
                    v = q[num[e[z].Y.Y]];
                    z++;
                    if (u==v) continue;
                    Q--;
                    for (ll p=0;p<W;p++) if (q[p]==v) q[p] = u;
                    if (Q==1)
                    {
                        A = min(A,L);
                        break;
                    }
                    continue;
                } else
                {
                    L = max(L,e2[z2].X);
                    u = q[num[e2[z2].Y.X]];
                    v = q[num[e2[z2].Y.Y]];
                    z2++;
                    if (u==v) continue;
                    Q--;
                    for (ll p=0;p<W;p++) if (q[p]==v) q[p] = u;
                    if (Q==1)
                    {
                        A = min(A,L);
                        break;
                    }
                    continue;
                }
            }
        }
    }
    if (A==mod*mod) cout << -1 << endl;
    else cout << A << endl;
}