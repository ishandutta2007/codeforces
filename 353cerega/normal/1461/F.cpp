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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    string s;
    cin >> s;
    vector<char> ch = {'+','*','-'};
    vector<ll> ok(3);
    for (ll i=0;i<s.length();i++)
    {
        for (ll j=0;j<3;j++)
        {
            if (s[i]==ch[j]) ok[j] = 1;
        }
    }
    if (s.length()==1)
    {
        for (ll i=0;i+1<n;i++)
        {
            cout << a[i] << s;
        }
        cout << a[n-1];
        return 0;
    }
    if (ok[0]==0)
    {
        for (ll i=0;i+1<n;i++)
        {
            cout << a[i];
            if (a[i+1]==0) cout << "-";
            else cout << "*";
        }
        cout << a[n-1];
        return 0;
    }
    if (ok[1]==0)
    {
        for (ll i=0;i+1<n;i++)
        {
            cout << a[i] << "+";
        }
        cout << a[n-1];
        return 0;
    }
    vector<ll> A(n-1);
    ll mx = 100000000;
    for (ll p=0;p+1<n;p++)
    {
        if (a[p]==1 or a[p]==0)
        {
            A[p] = 0;
            continue;
        }
        ll L = p;
        vector<ll> x, pos, cnt;
        ll P = 1;
        ll P2 = 1;
        ll F = 0;
        ll R = L;
        ll C = 0;
        ll S = 0;
        for (ll j=p;j<=n;j++)
        {
            if (j==n or a[j]==0)
            {
                R = j-1-C;
                S -= C;
                break;
            }
            if (a[j]>1)
            {
                if (C>0)
                {
                    pos.push_back(j-C);
                    cnt.push_back(C);
                    C = 0;
                }
                P = P*a[j];
                P2 = P2*a[j];
                if (P2>mx)
                {
                    F = 1;
                    P2 = mx;
                    P = mx;
                }
                if (j+1==n or a[j+1]<2)
                {
                    x.push_back(P);
                }
                if (j+1<n and a[j+1]>=2) A[j] = 1;
                continue;
            }
            if (a[j]==1)
            {
                C++;
                S++;
                P = 1;
            }
        }
        p = R;
        if (R+1<n) A[R] = 0;
        if (F==1 or S<P2/2-3)
        {
            for (ll i=L;i<R;i++)
            {
                A[i] = 1;
            }
            continue;
        }
        ll sz = pos.size();
        ll n2 = (1LL<<sz);
        ll M = S;
        ll bst = 0;
        for (ll m=0;m<n2;m++)
        {
            ll W = 0;
            ll Q = x[0];
            for (ll b=0;b<sz;b++)
            {
                if (m&(1LL<<b))
                {
                    Q *= x[b+1];
                } else
                {
                    W += Q;
                    Q = x[b+1];
                    W += cnt[b];
                }
            }
            W += Q;
            if (W>M)
            {
                bst = m;
                M = W;
            }
        }
        for (ll b=0;b<sz;b++)
        {
            if (bst&(1LL<<b))
            {
                for (ll j=pos[b];j<=pos[b]+cnt[b];j++)
                {
                    A[j-1] = 1;
                }
            } else
            {
                for (ll j=pos[b];j<=pos[b]+cnt[b];j++)
                {
                    A[j-1] = 0;
                }
            }
        }
    }
    for (ll i=0;i+1<n;i++)
    {
        cout << a[i] << ch[A[i]];
    }
    cout << a[n-1];
}