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

typedef unsigned long long u64;

struct poly
{
    u64 p[10]={};
    poly& operator+=(const poly& p2)
    {
        Loop(i,0,10) p[i] += p2.p[i];
        return *this;
    }
    poly operator*(const poly& p2)
    {
        u64 tmp[19]={}; poly ans;
        Loop(i,0,10) Loop(j,0,10)
            tmp[i+j] += p[i] * p2.p[j];
        LoopR(i,10,19) tmp[i-10] += tmp[i];
        Loop(i,0,10) ans.p[i] = tmp[i];
        return ans;
    }
    poly operator*(int x)
    {
        u64 tmp[19]={}; poly ans;
        Loop(i,x,10+x) tmp[i] = p[i-x];
        LoopR(i,10,19) tmp[i-10] += tmp[i];
        Loop(i,0,10) ans.p[i] = tmp[i];
        return ans;
    }
    void trim()
    {
        LoopR(i,0,6)
        {
            p[i+0] -= p[i+4];
            p[i+1] += p[i+4];
            p[i+2] -= p[i+4];
            p[i+3] += p[i+4];
            p[i+4] -= p[i+4];
        }
    }
};

poly v[100000];

void nfft(bool in, int l=0, int r=100000)
{
    static poly t[100000];
    if(l+1 == r) return;
    int n = (r-l)/10;
    for(int k=0; k < 10; ++k) nfft(in, l + k*n, l + (k+1)*n);
    for(int k=0; k < 10; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            t[l + k*n + i] = {};
            for(int j = 0; j < 10; ++j)
            {
                if(in) t[l + k*n + i] += v[l + j*n + i] * ((100-k*j)%10);
                else   t[l + k*n + i] += v[l + j*n + i] * (k*j%10);
            }
        }
    }
    for(int i = l; i < r; ++i) v[i] = t[i];
}

poly mpow(poly a, int b)
{
    if(!b) return {1};
    poly ans = mpow(a, b/2);
    ans = ans*ans;
    if(b&1) ans = ans*a;
    return ans;
}

const int N = 100'010;
int n, a[N];

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i];
        v[a[i]].p[0]++;
    }
    nfft(0, 0, 100000);
    Loop(i,0,100000) v[i] = mpow(v[i], n);
    nfft(1, 0, 100000);
    Loop(i,0,100000) v[i].trim();
    Loop(i,0,100000) Loop(j,1,10) assert(v[i].p[j] == 0);
    Loop(i,0,100000) v[i].p[0] *= 6723469279985657373ll;
    Loop(i,0,100000) v[i].p[0] >>= 5;
    Loop(i,0,n)
    {
        cout << (v[i].p[0] & 0x3ffffffffffffff) << '\n';
    }
}