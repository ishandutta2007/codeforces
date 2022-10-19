#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

ll my_pow(ll x, ll e, int mod)
{
    ll ans = 1;
    for(; e; e >>= 1)
    {
        if(e&1)
            ans = (ans*x)%mod;
        x = (x*x)%mod;
    }
    return ans;
}

int mod;
ll W[31];
void reset(int k, int p, int root)
{
    mod = p;
    W[k] = root;
    LoopR(i,0,k)
        W[i] = W[i+1]*W[i+1]%mod;
}

typedef vector<ll> vec;
vec tmp;

void bad_fft(vec& a, int sp, int st)
{
    ll wn = W[0];
    for(int i = sp; i < a.size(); i += st)
    {
        tmp[i] = 0;
        ll wj = my_pow(wn, (i-sp)/st, mod);
        ll w = 1;
        for(int j = sp; j < a.size(); j += st)
        {
            tmp[i] += w*a[j];
            tmp[i] %= mod;
            w = (w*wj)%mod;
        }
    }
    for(int i = sp; i < a.size(); i += st)
        a[i] = tmp[i];
}

void fft(vec& a, int sp=0, int st=1)
{
    int N = a.size()/st;
    if(N&1)
    {
        bad_fft(a, sp, st);
        return;
    }
    fft(a, sp, 2*st);
    fft(a, sp+st, 2*st);
    int n = __builtin_ctz(N);
    int mid = st*(N/2);
    ll wn = W[n], w = 1;
    Loop(i,0,N/2)
    {
        tmp[st*i + sp      ] = a[st*2*i + sp] + w*a[st*(2*i+1) + sp];
        tmp[st*i + sp + mid] = a[st*2*i + sp] - w*a[st*(2*i+1) + sp];
        w = (w*wn)%mod;
    }
    for(int i = sp; i < a.size(); i += st)
        a[i] = (tmp[i]%mod+mod)%mod;
}

int n, m;
string a, b;
vec A, B;

void reset_vec()
{
    int n = mod-1;
    A.resize(n);
    B.resize(n);
    tmp.resize(n);
    Loop(i,0,n)
        A[i] = (i >= ::n? 0: a[i]-'a'),
        B[i] = (i >= ::n? 0: b[i]-'a');
}

int solve()
{
    reset_vec();
    fft(A);
    fft(B);
    int k = __builtin_ctz(mod-1);
    Loop(j, 1, mod-1)
    {
        if(A[j] == B[j])
        return my_pow(W[k], j, mod);
    }
    return -42;
}

const int mods[13] = {13313, 18433, 12289, 40961, 114689, 163841, 65537, 1179649, 786433, 5767169, 7340033, 23068673, 104857601,};
const int roots[13] = {3, 5, 11, 3, 3, 3, 3, 19, 10, 3, 3, 3, 3,};

int main()
{
    //FAST;
    //test2();
    cin >> n >> m;
    cin >> a >> b;
    Loop(i,0,13)
    {
        if(mods[i] < m)
            continue;
        reset(10+i, mods[i], roots[i]);
        int x = solve();
        if(x == -42)
            continue;
        cout << mod << ' ' << x << '\n';
        //test(mod, x);
        return 0;
    }
    cout << -42 << '\n';
}