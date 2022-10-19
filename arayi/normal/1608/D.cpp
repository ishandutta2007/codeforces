//Arayi
#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int>
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
using namespace std;
 
lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };
 
 
const int N = 1e5 + 20; 
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 200;
 
lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}


int n;
int r0, r1, l0, l1;
str s[N];
lli f[N], ans;
lli c(int n, int k)
{
    lli ret = f[n]*bp(f[k]);
    ret%=mod;
    ret*=bp(f[n-k]);
    ret%=mod;
    return ret;
}
lli ss()
{
    int sm=0, a=0,b=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i][0]==s[i][1]&&s[i][0]=='?') sm++;
        else if(s[i][0]==s[i][1]) return 0;
        if(s[i][0]=='W'||s[i][1]=='B') a++;
        else if(s[i][0]=='B'||s[i][1]=='W') b++;
    }
    lli ret = bp(2,sm);
    if(a==0) ret--;
    if(b==0) ret--;
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    f[0]=1;
    for (lli i = 1; i <= n; i++)
    {
        f[i]=f[i-1]*1LL*i;
        f[i]%=mod;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if(s[i][0]=='W') l0++;
        else if(s[i][0]=='B') l1++;
        if(s[i][1]=='W') r0++;
        else if(s[i][1]=='B') r1++;
    }
    for (int i = 0; i <= n-l0-l1; i++)
    {
        int l00=l0+i;
        int l11=n-l00;
        int r00=l11;
        int r11=l00;
        if(r00<r0||r11<r1) continue;
        ans += (c(n-l0-l1, i)*c(n-r0-r1, r11-r1))%mod;
        ans%=mod; 
    }
    ans-=ss();
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}

/*
    __
  *(><)*
    \/ /
    ||/
  --||
    ||
    /\
   /  \
  /    \
 
*/