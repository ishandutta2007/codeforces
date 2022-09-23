//#pragma GCC optimize("Ofast")
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
    if (a>=mod) a -= mod;
    //a %= mod;
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
    else return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a);
        a = mul(a,a);
        b >>= 1LL;
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
    sz[v] = 1;
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



void solve()
{
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if ((n==1 and s[0]=='a'+p-1) or (n==2 and p==2 and s[0]=='b'))
    {
        cout << "NO\n";
        return;
    }
    if (p==2)
    {
        if (n==2) cout << "ba";
        else cout << "b";
        return;
    }
    for (ll j=n-1;j>=0;j--)
    {
        s[j]++;
        if (s[j]=='a'+p)
        {
            s[j] = 'a';
            if (j==0)
            {
                cout << "NO\n";
                return;
            }
        }
        else break;
    }
    ll FF = 0;
    for (ll j=n-1;j>=0;j--)
    {
        ll F = 0;
        while ((j>0 and s[j]==s[j-1]) or (j>1 and s[j]==s[j-2]) or FF==1)
        {
            FF = 0;
            F = 1;
            s[j]++;
            if (s[j]=='a'+p)
            {
                FF = 1;
                s[j] = 'a';
                break;
            }
        }
        if (F==1)
        {
            for (ll i=j+1;i<n;i++)
            {
                vector<ll> was(3);
                for (ll k=max(i-2,0LL);k<i;k++)
                {
                    ll x = s[k]-'a';
                    if (x>=3) continue;
                    was[x] = 1;
                }
                for (ll w=0;w<3;w++)
                {
                    if (was[w]==0)
                    {
                        s[i] = w+'a';
                        break;
                    }
                }
            }
        }
    }
    if (FF==1) cout << "NO\n";
    else cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}