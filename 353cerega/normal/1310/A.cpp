#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
    return (a+b)%mod;
}

ll sub(ll a, ll b)
{
    return (a-b)%mod;
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
    }
    return res;
}


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


int t[4000001];

void push (int v) {
    if (t[v] != -1) {
        t[v*2] = t[v*2+1] = t[v];
        t[v] = -1;
    }
}

void update (int v, int tl, int tr, int l, int r, int color) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] = color;
    else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r,tm), color);
        update(v*2+1, tm+1, tr, max(l,tm+1), r, color);
    }
}

int get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> t(n);
    for (int i=0;i<n;i++)
    {
        cin >> t[i];
    }
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    ll ans = 0;
    multiset<int> kek;
    vector<pair<int,int>> ord(n);
    for (int i=0;i<n;i++)
    {
        ord[i] = {t[i],a[i]};
    }
    sort(ord.begin(),ord.end());
    int pos = 0;
    int tim = 0;
    while (true)
    {
        if (pos<n and tim<ord[pos].X and kek.empty()) tim = ord[pos].X;
        if (kek.empty() and pos==n) break;
        while (pos<n and tim==ord[pos].X)
        {
            sum += ord[pos].Y;
            kek.insert(-ord[pos].Y);
            pos++;
        }
        if (!kek.empty())
        {
            auto it = kek.begin();
            sum += *it;
            kek.erase(it);
        }
        ans += sum;
        tim++;
    }
    cout << ans << endl;
    return 0;
}