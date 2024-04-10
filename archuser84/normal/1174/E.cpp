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

const int mod = 1e9 + 7;
class mint
{
private:
    int v;

    static int modDiv(int x, int y, int md)
    {
        if(x%y == 0) return x/y;
        return (x + (long long)modDiv(y - x%y, md%y, y)*md) / y;
    }

public:
    mint() : v(0){}
    mint(int x) {
        if(x >= mod) x %= mod;
        if(x < 0) x = x%mod + mod;
        v = x;
    }
    mint(long long x) {
        if(x >= mod) x %= mod;
        if(x < 0) x = x%mod + mod;
        v = x;
    }
    explicit operator int(){return v;}
    explicit operator long long(){return v;}

    mint& operator+=(mint x) {
        this->v += x.v;
        if(this->v >= mod) this->v -= mod;
        return *this;
    }
    mint& operator-=(mint x) {
        this->v -= x.v;
        if(this->v < 0) this->v += mod;
        return *this;
    }

    mint inverse() {return modDiv(1, v, mod);}
    mint& operator*=(mint x) {return *this = (long long)this->v * x.v;}
    mint& operator/=(mint x) {return *this = modDiv(this->v, x.v, mod);}
};

mint operator+ (mint x, mint y) {return x += y;}
mint operator- (mint x, mint y) {return x -= y;}
mint operator* (mint x, mint y) {return x *= y;}
mint operator/ (mint x, mint y) {return x /= y;}
bool operator==(mint x, mint y) {return int(x) == int(y);}
bool operator!=(mint x, mint y) {return int(x) != int(y);}


const int N = 1e6 + 10;
//const int mod = 1e9 + 7;
mint fc[N];

mint P(int n, int r)
{
    return fc[n] / fc[n-r];
}

int bg[20] = {};
int bg2g[20] = {};
int bg2b[20] = {};

mint solve2(int k, int rem, bool g = 1)
{
    mint ans = 1;
    if(g)
    {
        ans *= bg2g[k]*P(rem-1, bg2g[k]-1);
        rem -= bg2g[k];
        if(k) {
            bg2b[k-1] += bg2b[k];
            bg2b[k-1] -= bg2g[k];
            int tmp = 0;
            tmp += (int)solve2(k-1, rem, 0);
            tmp += (int)solve2(k-1, rem, 1);
            ans *= tmp;
        }
    }
    else
    {
        ans *= bg2b[k]*P(rem-1, bg2b[k]-1);
        rem -= bg2b[k];
        if(k) {
            ans *= solve2(k-1, rem, 0);
        }
    }
    return ans;
}

int main()
{
    FAST;
    fc[0] = 1;
    Loop(i,1,N) fc[i] = fc[i-1]*i;
    int n;
    cin >> n;
    int f = 0, f2 = 0;
    Loop(x,1,n+1){
        int k = __builtin_ctz(x);
        f = max(f, k);
        if(x%3 == 0) f2 = max(f2, k+1), bg2g[k+1]++;
        bg2b[k]++;
    }
    int rem = n;
    mint ans = solve2(f, n, 0);
    mint ans2 = 0;
    if(f2 == f) ans2 = solve2(f2, n);
    cout << int(ans+ans2) << '\n';
}