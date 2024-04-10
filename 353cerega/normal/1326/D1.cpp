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

ll base1 = 29;
ll base2 = 47;
ll mod1 = 998244353;
ll mod2 = 1000000007;

vector<pair<ll,ll>> hsh(string s)
{
    int n = s.length();
    vector<pair<ll,ll>> kek(n);
    kek[0].X = s[0]-'a';
    kek[0].Y = s[0]-'a';
    for (int i=1;i<n;i++)
    {
        kek[i].X = (kek[i-1].X*base1 + s[i]-'a')%mod1;
        kek[i].Y = (kek[i-1].Y*base2 + s[i]-'a')%mod2;
    }
    return kek;
}

void solve()
{
    string t, s;
    cin >> s;
    int n = s.length();
    t = s;
    reverse(t.begin(),t.end());
    vector<pair<ll,ll>> kek = hsh(s);
    vector<pair<ll,ll>> lul = hsh(t);
    vector<ll> p1(n), p2(n);
    p1[0] = 1;
    p2[0] = 1;
    for (int i=1;i<n;i++)
    {
        p1[i] = p1[i-1]*base1%mod1;
        p2[i] = p2[i-1]*base2%mod2;
    }
    vector<int> maxlen(n);
    int st = 0;
    for (int i=0;i+i<=n;i++)
    {
        if (s[i]==s[n-i-1])
        {
            st++;
        } else{
            break;
        }
    }
    if (n/2<=st)
    {
        cout << s << endl;
        return;
    }
    int pos = -1;
    int ans = st*2+1;
    string bst = "";
    for (int i=0;i<=st;i++)
    {
        bst += s[i];
    }
    for (int j=st-1;j>=0;j--)
    {
        bst += s[j];
    }
    vector<int> bestlen(n);
    for (int i=0;i<n;i++)
    {
        int l = 0, r = min(n-i,i+1);
        while (r-l>1)
        {
            int m = (l+r)/2;
            pair<ll,ll> hash1 = kek[i];
            if (i-m>0)
            {
                hash1.X -= kek[i-m-1].X*p1[m+1]%mod1;
                hash1.Y -= kek[i-m-1].Y*p2[m+1]%mod2;
                if (hash1.X<0)
                {
                    hash1.X += mod1;
                }
                if (hash1.Y<0)
                {
                    hash1.Y += mod2;
                }
            }
            pair<ll,ll> hash2 = lul[n-i-1];
            if (n-i-1-m>0)
            {
                hash2.X -= lul[n-i-m-2].X*p1[m+1]%mod1;
                hash2.Y -= lul[n-i-m-2].Y*p2[m+1]%mod2;
                if (hash2.X<0)
                {
                    hash2.X += mod1;
                }
                if (hash2.Y<0)
                {
                    hash2.Y += mod2;
                }
            }
            if (hash1.X==hash2.X and hash1.Y==hash2.Y)
            {
                l = m;
            } else{
                r = m;
            }
        }
        bestlen[i] = l;
        if (2*i<n)
        {
            if (i-l<=st)
            {
                if (ans<i*2+1)
                {
                    pos = i;
                    ans = i*2+1;
                }
            }
        } else{
            int j = n-1-i;
            if (j-l<=st)
            {
                if (ans<j*2+1)
                {
                    pos = i;
                    ans = j*2+1;
                }
            }
        }
    }
    if (pos!=-1)
    {
        int i = pos;
        if (2*i<n)
        {
            if (i-bestlen[i]<=st)
            {
                bst = "";
                for (int q=0;q<=i;q++)
                {
                    bst += s[q];
                }
                for (int q=i-1;q>=0;q--)
                {
                    bst += s[q];
                }
            }
        } else{
            int j = n-1-i;
            if (j-bestlen[i]<=st)
            {
                bst = "";
                for (int q=0;q<=j;q++)
                {
                    bst += t[q];
                }
                for (int q=j-1;q>=0;q--)
                {
                    bst += t[q];
                }
            }
        }
    }
    pos = -1;
    for (int i=0;i<n-1;i++)
    {
        int l = 0, r = min(n-i-1,i+1);
        if (s[i]!=s[i+1]) continue;
        while (r-l>1)
        {
            int m = (l+r)/2;
            pair<ll,ll> hash1 = kek[i];
            if (i-m>0)
            {
                hash1.X -= kek[i-m-1].X*p1[m+1]%mod1;
                hash1.Y -= kek[i-m-1].Y*p2[m+1]%mod2;
                if (hash1.X<0)
                {
                    hash1.X += mod1;
                }
                if (hash1.Y<0)
                {
                    hash1.Y += mod2;
                }
            }
            pair<ll,ll> hash2 = lul[n-i-2];
            if (n-i-2-m>0)
            {
                hash2.X -= lul[n-i-m-3].X*p1[m+1]%mod1;
                hash2.Y -= lul[n-i-m-3].Y*p2[m+1]%mod2;
                if (hash2.X<0)
                {
                    hash2.X += mod1;
                }
                if (hash2.Y<0)
                {
                    hash2.Y += mod2;
                }
            }
            if (hash1.X==hash2.X and hash1.Y==hash2.Y)
            {
                l = m;
            } else{
                r = m;
            }
        }
        bestlen[i] = l;
        if (2*i+1<n)
        {
            if (i-l<=st)
            {
                if (ans<i*2+2)
                {
                    ans = i*2+2;
                    pos = i;
                }
            }
        } else{
            int j = n-2-i;
            if (j-l<=st)
            {
                if (ans<j*2+2)
                {
                    ans = j*2+2;
                    pos = i;
                }
            }
        }
    }
    if (pos!=-1)
    {
        int i = pos;
        if (2*i+1<n)
        {
            if (i-bestlen[i]<=st)
            {
                bst = "";
                for (int q=0;q<=i;q++)
                {
                    bst += s[q];
                }
                for (int q=i;q>=0;q--)
                {
                    bst += s[q];
                }
            }
        } else{
            int j = n-2-i;
            if (j-bestlen[i]<=st)
            {
                bst = "";
                for (int q=0;q<=j;q++)
                {
                    bst += t[q];
                }
                for (int q=j;q>=0;q--)
                {
                    bst += t[q];
                }
            }
        }
    }
    cout << bst << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}