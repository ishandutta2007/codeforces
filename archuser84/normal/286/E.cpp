#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

typedef vector<ll> vec;
const int mod = 7*17*(1<<23) + 1;
ll w[24];
ll wi[24];

void fft(vec& v, bool inv, int l, int r)
{
    static ll tmp[1<<21] = {};
    if(l+1 == r) return;
    int m = (l+r)/2;
    Loop(i,0,r-l)
    {
        if(i&1) tmp[m + (i>>1)] = v[l+i];
        else    tmp[l + (i>>1)] = v[l+i];
    }
    Loop(i,l,r) v[i] = tmp[i];
    fft(v, inv, l, m); fft(v, inv, m, r);
    int k = __builtin_ctz(r-l);
    ll wn = inv? wi[k]: w[k];
    ll wk = 1;
    Loop(i,0,m-l)
    {
        ll a = v[l+i];
        ll b = v[m+i];
        v[l+i] =  (a + wk*b) % mod;
        v[m+i] = ((a - wk*b) % mod + mod) % mod;
        if(inv){
            v[l+i] = v[l+i]&1? (v[l+i]+mod)>>1: v[l+i]>>1;
            v[m+i] = v[m+i]&1? (v[m+i]+mod)>>1: v[m+i]>>1;
        }
        wk = wk*wn % mod;
    }
}

void init()
{
    w [23] = 31;
    wi[23] = 128805723;
    LoopR(i,0,23) w [i] = w [i+1]*w [i+1] % mod;
    LoopR(i,0,23) wi[i] = wi[i+1]*wi[i+1] % mod;
}

vec a(1<<21);
vec b(1<<21);

int main()
{
    //FAST;
    init();
    //Loop(i,0,24) cout << wi[i] << ' ';
    int n, m;
    cin >> n >> m;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        b[x] = a[x] = 1;
    }
    b[0] = a[0] = 1;
    fft(b, 0, 0, 1<<21);
    Loop(i,0,1<<21) b[i] = b[i]*b[i] % mod;
    fft(b, 1, 0, 1<<21);
    vector<int> ans;
    Loop(i,1,m+1)
    {
        if(b[i] && !a[i]) Kill("NO\n");
        if(b[i] == 2) ans.push_back(i);
    }
    cout << "YES\n" << ans.size() << '\n';
    for(int x : ans)
        cout << x << ' ';
}