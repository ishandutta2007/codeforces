#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = 1000000007;

ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}

ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
    //if (a >= mod) a -= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    //if (a < 0) a += mod;
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


typedef complex<double> base;
long double PI = acos(-1);
/*
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

vector<vector<int>> g;
int sz1, sz2, n;
vector<ll> ans;

void rec(int l)
{
    for (int msk=0;msk<(1<<n);msk++)
    {
        if (msk&(1<<l)) continue;
        int cnt = 0;
        vector<int> lft, rgh;
        for (int j=0;j<n;j++)
        {
            if (msk&(1<<j))
            {
                lft.push_back(j);
                cnt++;
            } else{
                if (j!=l)
                    rgh.push_back(j);
            }
        }
        if (cnt!=sz1-1) continue;
        vector<ll> lans(1<<(sz1-1)), rans(1<<sz2);
        while(true)
        {
            int cur = 0;
            for (int i=0;i<sz1-2;i++)
            {
                cur*=2;
                cur += g[lft[i]][lft[i+1]];
            }
            cur *= 2;
            cur += g[lft[sz1-2]][l];
            lans[cur]++;
            if (!next_permutation(lft.begin(),lft.end()))
            {
                break;
            }
        }
        while(true)
        {
            int cur = g[l][rgh[0]];

            for (int i=0;i<sz2-1;i++)
            {
                cur *= 2;
                cur += g[rgh[i]][rgh[i+1]];
            }
            rans[cur]++;
            if (!next_permutation(rgh.begin(),rgh.end()))
            {
                break;
            }
        }
        for (int i=0;i<(1<<(sz1-1));i++)
        {
            for (int j=0;j<(1<<sz2);j++)
            {
                int cur = i*(1<<sz2)+j;
                ans[cur] += lans[i]*rans[j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    for (int i=0;i<n;i++)
    {
        g[i].resize(n);
        string s;
        cin >> s;
        for (int j=0;j<n;j++)
        {
            g[i][j] = s[j]-'0';
        }
    }
    /*vector<vector<ll>> cur(n), prv(n);
    for (int i=0;i<n;i++)
    {
        cur[i].resize((1<<(n-1)));
        prv[i].resize((1<<(n-1)));
    }
    for (int i=0;i<n;i++)
    {
        cur[i][0] = 1;
    }
    for (int len=1;len<n;len++)
    {
        swap(cur,prv);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {

            }
        }
    }*/
    if (n<=7)
    {
        vector<int> kek(n);
        for (int i=0;i<n;i++)
        {
            kek[i] = i;
        }
        ans.resize((1<<(n-1)));
        while(true)
        {
            int cur = 0;
            for (int i=0;i<n-1;i++)
            {
                cur*=2;
                cur += g[kek[i]][kek[i+1]];
            }
            ans[cur]++;
            if (!next_permutation(kek.begin(),kek.end()))
            {
                break;
            }
        }
        for (int i=0;i<(1<<(n-1));i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }
    sz1 = n/2;
    sz2 = n-sz1;
    ans.resize((1<<(n-1)));
    for (int i=0;i<n;i++)
    {
        rec(i);
    }
    for (int i=0;i<(1<<(n-1));i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}