#include <cstdio>
#include <cstring>
#include <algorithm>
#define M (1 << 17)
#define P 998244353
#define PII pair <int, int>
#define int long long
#define BUFSIZE 300000
namespace fib {char b[BUFSIZE]={},*f=b;}
#define gc ((*fib::f)?(*(fib::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
int g_i()
{
    int tmp=0; bool fu=0; char s;
    while(s=gc,s!='-'&&(s<'0'||s>'9')) ;
    if(s=='-') fu=1; else tmp=s-'0';
    while(s=gc,s>='0'&&s<='9') tmp=tmp*10+s-'0';
    if(fu) return -tmp; else return tmp;
}
#define gi g_i()
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    if(x<0) {pc('-'); x=-x;}
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}

using namespace std;

typedef long long ll;

int n, k, x, y, z, A[M], B[M], C[M], mmp[M], Comb[18][18];

ll O[M], Ans[4][M], S[4][M];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    x %= p;
    y = (y % (p - 1) + (p - 1)) % (p - 1);
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

signed main() {
    n = g_i(), k = g_i(), x = g_i(), y = g_i(), z = g_i();
    for(int i = 0; i < n; i++)
        A[i] = g_i(), B[i] = g_i() ^ A[i], C[i] = g_i() ^ A[i];
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= i; j++)
            Comb[i][j] = !j ? 1 : Comb[i - 1][j - 1] + Comb[i - 1][j];
    mmp[0] = 1;
    for(int i = 1; i <= k; i++) {
        mmp[i] = 1 - (i % 2);
        for(int j = 0; j < i; j++)
            mmp[i] -= Comb[i][j] * mmp[j];
    }
    for(int b1 = 0; b1 < 2; b1++)
        for(int b2 = 0; b2 < 2; b2++) {
            memset(O, 0, sizeof O);
            for(int i = 0; i < n; i++) O[(B[i] * b1) ^ (C[i] * b2)]++;
            for(int i = 1; i < (1 << k); i *= 2)
                for(int j = 0; j < (1 << k); j += i + i)
                    for(int k = j; k < j + i; k++)
                        O[k] = (O[k] + O[k + i]);
            for(int i = 0; i < (1 << k); i++) O[i] *= mmp[__builtin_popcount(i)];
            for(int i = 1; i < (1 << k); i *= 2)
                for(int j = 0; j < (1 << k); j += i + i)
                    for(int k = j; k < j + i; k++)
                        O[k + i] = (O[k + i] + O[k]);
            memcpy(Ans[b1 * 2 + b2], O, sizeof O);
        } // modulo P - 1
    S[0][1] = x - y - z;
    S[1][1] = x - y + z;
    S[2][1] = x + y - z;
    S[3][1] = (x + y + z) % P;
    for(int i = 0; i < 4; i++) {
        S[i][0] = 1;
        for(int j = 2; j <= n; j++) S[i][j] = S[i][j - 1] * S[i][1] % P;
    }
    for(int i = 0; i < (1 << k); i++) {
        ll _00 = Ans[0][i], _01 = Ans[1][i], _10 = Ans[2][i], _11 = Ans[3][i];
        ll __00 = (_01 + _10 + _11 - _00) / 2;
        ll __11 = _11 - __00;
        ll __01 = _10 - __00;
        ll __10 = _01 - __00;
        O[i] = S[0][__11] * S[1][__10] % P * S[2][__01] % P * S[3][__00] % P;
    }
    int tot = 0;
    for(int i = 0; i < n; i++) tot ^= A[i];
    for(int i = 1; i < (1 << k); i *= 2)
        for(int j = 0; j < (1 << k); j += i + i)
            for(int k = j; k < j + i; k++) {
                ll A = O[k], B = O[k + i];
                O[k] = (A + B);
                O[k + i] = (A - B);
            }
    ll r = powmod(1 << k);
    for(int i = 0; i < (1 << k); i++) pint((O[i ^ tot] % P * r % P + P) % P), pc(' ');
    pob;
    return 0;
}