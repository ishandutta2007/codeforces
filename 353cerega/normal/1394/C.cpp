#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = (1LL<<32);

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

/*
ll t[8000001];

void build()
{
    for (int i=0;i<6000000;i++)
    {
        t[i] = 0;
    }
}

void update (int v, int tl, int tr, int pos, int add) {
    t[v] += add;
    if (tl==tr) return;
    int tm = (tl + tr) / 2;
    if (tm>=pos)
    {
        update(v * 2, tl, tm, pos, add);
    } else
    {
        update (v*2+1, tm+1, tr, pos, add);
    }
}

int get (int v, int tl, int tr, int l, int r) {
    if (tl == l and tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}


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
}*/



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> kek(n);
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<s.length();j++)
        {
            if (s[j]=='B')
            {
                kek[i].X++;
            } else
            {
                kek[i].Y++;
            }
        }
    }
    int l = -1, r = 10000000;
    int x, y;
    while (r-l>1)
    {
        int minx = 0, miny = 0, minxy = -10000000, maxxy = 10000000, maxx = 10000000, maxy = 10000000;
        int m = (r+l)/2;
        for (int i=0;i<n;i++)
        {
            minx = max(minx,kek[i].X-m);
            miny = max(miny,kek[i].Y-m);
            minxy = max(minxy,kek[i].X-kek[i].Y-m);
            maxx = min(maxx,kek[i].X+m);
            maxy = min(maxy,kek[i].Y+m);
            maxxy = min(maxxy,kek[i].X-kek[i].Y+m);
        }
        maxxy = min(maxxy,maxx-miny);
        minxy = max(minxy,minx-maxy);
        if (minx>maxx or miny>maxy or minxy>maxxy)
        {
            l = m;
            continue;
        }
        if (maxx-maxy>=minxy and maxx-maxy<=maxxy)
        {
            if (maxx+maxy>0)
            {
                x = maxx;
                y = maxy;
                r = m;
            } else
            {
                l = m;
            }
            continue;
        }
        if (maxx-maxy<minxy)
        {
            int curx = maxx;
            int cury = maxx-minxy;
            if (curx+cury>0)
            {
                x = curx;
                y = cury;
                r = m;
            } else
            {
                l = m;
            }
            continue;
        }
        if (maxx-maxy>maxxy)
        {
            int cury = maxy;
            int curx = maxxy+cury;
            if (curx+cury>0)
            {
                x = curx;
                y = cury;
                r = m;
            } else
            {
                l = m;
            }
            continue;
        }
    }
    cout << r << endl;
    for (int i=0;i<x;i++)
    {
        cout << "B";
    }
    for (int j=0;j<y;j++)
    {
        cout << "N";
    }
}