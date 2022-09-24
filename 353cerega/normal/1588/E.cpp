#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = double;

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

/*
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
}*/


struct pt {
    ll x, y;
};

bool cmp (pt a, pt b) {
    return a.y < b.y || a.y == b.y && a.x < b.x;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
}

ll L2(pt a, pt b, ll R)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)>R*R;
}

bool cmp3(pt a, pt b)
{
    ll x = a.x*b.y-a.y*b.x;
    if (x>0) return true;
    if (x<0) return false;
    if (a.x*b.x>0) return true;
    if (a.y*b.y>0) return true;
    return false;
}

bool cmp2(pt a, pt b)
{
    ll Da = 1, Db = 1;
    if (a.y>0 or (a.y==0 and a.x>0)) Da = 0;
    if (b.y>0 or (b.y==0 and b.x>0)) Db = 0;
    if (Da!=Db) return Da<Db;
    return a.x*b.y-a.y*b.x>0;
}

bool cmp0(pair<pt,ll> a, pair<pt,ll> b)
{
    return cmp2(a.X,b.X);
}

vector<vector<pt>> D;
vector<pt> a;

bool check(ll i, ll j)
{
    pt d = {a[j].x-a[i].x,a[j].y-a[i].y};
    if (D[i].size()>0)
    {
        if (D[i][0].x*d.x+D[i][0].y*d.y>=0) return true;
    }
    if (D[i].size()>1)
    {
        if (D[i].back().x*d.x+D[i].back().y*d.y>=0) return true;
    }
    if (D[j].size()>0)
    {
        if (D[j][0].x*d.x+D[j][0].y*d.y<=0) return true;
    }
    if (D[j].size()>1)
    {
        if (D[j].back().x*d.x+D[j].back().y*d.y<=0) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, R;
    cin >> n >> R;
    a.resize(n);
    vector<pt> b(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
        b[i] = a[i];
    }
    convex_hull(b);
    ll m = b.size();
    D.resize(n);
    vector<ll> bad(n);
    ll ans = 0;
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            pt d = {a[i].x-b[j].x,a[i].y-b[j].y};
            if (L2(a[i],b[j],R)) D[i].push_back(d);
        }
        sort(D[i].begin(),D[i].end(),cmp2);
        if (D[i].size()>1)
        {
            ll p = -1;
            ll sz = D[i].size();
            for (ll j=0;j<sz;j++)
            {
                if (!cmp3(D[i][j],D[i][(j+1)%sz])) p = j+1;
            }
            if (p==-1) bad[i] = 1;
            vector<pt> T;
            for (ll j=0;j<sz;j++)
            {
                T.push_back(D[i][(j+p)%sz]);
            }
            D[i] = T;
        }
        if (D[i].size()>1)
        {
            if (!cmp3(D[i][0],D[i].back())) bad[i] = 1;
        }
    }
    for (ll i=0;i<n;i++)
    {
        if (bad[i]==1) continue;
        vector<pair<pt,ll>> kek(n);
        for (ll j=0;j<n;j++)
        {
            kek[j].X = a[j];
            kek[j].X.x -= a[i].x;
            kek[j].X.y -= a[i].y;
            kek[j].Y = j;
        }
        swap(kek[i],kek.back());
        kek.pop_back();
        sort(kek.begin(),kek.end(),cmp0);
        ll z1 = 0, z2 = 0;
        for (ll j=0;j<kek.size();j++)
        {
            pt d = {kek[j].X.y,-kek[j].X.x};
            ll Q = d.x*(b[z1].x-a[i].x)+d.y*(b[z1].y-a[i].y);
            ll Q2 = d.x*(b[z2].x-a[i].x)+d.y*(b[z2].y-a[i].y);
            while (Q<d.x*(b[(z1+1)%m].x-a[i].x)+d.y*(b[(z1+1)%m].y-a[i].y))
            {
                z1++;
                if (z1==m) z1 -= m;
                Q = d.x*(b[z1].x-a[i].x)+d.y*(b[z1].y-a[i].y);
            }
            while (m>2 and Q<=d.x*(b[(z1+m-1)%m].x-a[i].x)+d.y*(b[(z1+m-1)%m].y-a[i].y))
            {
                z1--;
                if (z1==-1) z1 += m;
                Q = d.x*(b[z1].x-a[i].x)+d.y*(b[z1].y-a[i].y);
            }
            while (Q2>d.x*(b[(z2+1)%m].x-a[i].x)+d.y*(b[(z2+1)%m].y-a[i].y))
            {
                z2++;
                if (z2==m) z2 -= m;
                Q2 = d.x*(b[z2].x-a[i].x)+d.y*(b[z2].y-a[i].y);
            }
            while (m>2 and Q2>=d.x*(b[(z2+m-1)%m].x-a[i].x)+d.y*(b[(z2+m-1)%m].y-a[i].y))
            {
                z2--;
                if (z2==-1) z2 += m;
                Q2 = d.x*(b[z2].x-a[i].x)+d.y*(b[z2].y-a[i].y);
            }
            if (bad[kek[j].Y]==1) continue;
            if (check(i,kek[j].Y)) continue;
            Q = max(Q,-Q2);
            if (Q*1.0>R*sqrt(d.x*d.x+d.y*d.y)) continue;
            ans++;
        }
    }
    cout << ans/2 << endl;
}