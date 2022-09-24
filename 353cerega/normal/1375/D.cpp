//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

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


int t[4000001];
int delta[4000001];

void push (int v) {
    if (delta[v] != 0) {
        t[v*2] = t[v];
        t[v*2+1] = t[v];
        delta[v*2+1] = delta[v];
        delta[v*2] = delta[v];
        delta[v] = 0;
    }
}

void build()
{
    for (int i=0;i<3000000;i++)
    {
        t[i] = 20000000;
        delta[i] = 0;
    }
}

void update (int v, int tl, int tr, int pos, int val) {
    if (tl==tr)
    {
        t[v] = val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos<=tm) update(v*2, tl, tm, pos, val);
        else update(v*2+1, tm+1, tr, pos, val);
        t[v] = min(t[2*v],t[2*v+1]);
    }
}

int get (int v, int tl, int tr, int l, int r) {
    if (l==tl and r==tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return get(v*2, tl, tm, l, r);
    if (l>tm)
        return get(v*2+1, tm+1, tr, l, r);
    return min(get(v*2, tl, tm, l, tm),get(v*2+1, tm+1, tr, tm+1,r));
}



int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int num=0;num<t;num++)
    {
        int n;
        cin >> n;
        vector<int> kek(n);
        vector<int> cnt(n+1);
        int bad = n;
        for (int i=0;i<n;i++)
        {
            cin >> kek[i];
            if (kek[i]==i) bad--;
            cnt[kek[i]]++;
        }
        int mex = 0, maxmex = 0;
        vector<int> ans;
        for (int i=0;i<=n;i++)
        {
            if (cnt[i]==0)
            {
                mex = i;
                maxmex = mex;
                break;
            }
        }
        while (true)
        {
            if (mex==n)
            {
                break;
            }
            ans.push_back(mex+1);
            cnt[kek[mex]]--;
            int nxt = kek[mex];
            cnt[mex]++;
            kek[mex] = mex;
            bad--;
            if (cnt[nxt]==0 and nxt<maxmex)
            {
                mex = nxt;
            } else{
                for (int i=maxmex;i<=n;i++)
                {
                    if (cnt[i]==0)
                    {
                        mex = i;
                        maxmex = mex;
                        break;
                    }
                }
            }
        }
        vector<int> pos(n+1);
        vector<int> ok(n);
        for (int i=0;i<n;i++)
        {
            pos[kek[i]] = i;
        }
        int flag = 0;
        for (int i=0;i<n;i++)
        {
            if (cnt[i]==0)
            {
                flag = 1;
            }
        }
        if (flag==0) {
            for (int i = 0; i < n; i++) {
                if (kek[i] != i and ok[i] == 0) {
                    int cur = kek[i];
                    ok[i] = 1;
                    ans.push_back(i + 1);
                    while (cur != i) {
                        ok[cur] = 1;
                        ans.push_back(cur + 1);
                        cur = kek[cur];
                    }
                    ans.push_back(i+1);
                }
            }
        }
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}