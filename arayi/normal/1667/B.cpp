// Arayi
#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
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
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
char dc[] = {'R', 'D', 'L', 'U'};

const int N = 1e6 + 20;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 200;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream &operator<<(ostream &c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template <class T>
void maxi(T &a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T &a, T b)
{
    a = min(a, b);
}

int qq, n;
lli a[N], pr[N], dp[N], sm[N];
lli t[4*N], t1[4*N];
void upd(int q, lli v, int l=0, int r = n*2, int nd = 1)
{
    if(q>r||q<l) return;
    if(l==r) 
    {
        t[nd]=max(t[nd], v);
        return;
    }
    int md = (l+r)/2;
    upd(q,v,l,md,nd*2);
    upd(q,v,md+1,r,nd*2+1);
    t[nd]=max(t[nd*2], t[nd*2+1]);
}
void upd1(int q, lli v, int l=0, int r = n*2, int nd = 1)
{
    if(q>r||q<l) return;
    if(l==r) 
    {
        t1[nd]=max(t1[nd], v);
        return;
    }
    int md = (l+r)/2;
    upd1(q,v,l,md,nd*2);
    upd1(q,v,md+1,r,nd*2+1);
    t1[nd]=max(t1[nd*2], t1[nd*2+1]);
}
lli qry(int l, int r, int nl = 0, int nr = n*2, int nd = 1)
{
    if(l > nr || r < nl) return -mod;
    if(l==nl&&r==nr) return t[nd];
    int md = (nl + nr)/2;
    return max(qry(l,min(md,r),nl, md, nd*2), qry(max(md+1,l),r,md+1,nr,nd*2+1));
}
lli qry1(int l, int r, int nl = 0, int nr = n*2, int nd = 1)
{
    if(l > nr || r < nl) return -mod;
    if(l==nl&&r==nr) return t1[nd];
    int md = (nl + nr)/2;
    return max(qry1(l,min(md,r),nl, md, nd*2), qry1(max(md+1,l),r,md+1,nr,nd*2+1));
}
void fill(int l = 0, int r = n*2, int nd = 1)
{
    t[nd]=t1[nd]=-mod;
    if(l==r) return;
    fill(l,(l+r)/2,nd*2);
    fill((l+r)/2+1,r,nd*2+1);
}
int main()
{
    fastio;
    cin >> qq;
    while (qq--)
    {
        cin >> n;
        fill();
        vector<lli> fp;
        fp.ad(0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pr[i]=a[i];
            sm[i]=-mod;
            if(i) pr[i]+=pr[i-1];
            dp[i]=-mod;
            fp.ad(pr[i]);
        }
        for (int i = 0; i <= n; i++) sm[i+n]=-mod;
        sort(all(fp));
        int i1 = upper_bound(all(fp), 0)-fp.begin();
        upd(i1,0), upd1(i1,0);
        sm[i1]=0;
        for (int i = 0; i < n; i++)
        {
            i1 = upper_bound(all(fp), pr[i])-fp.begin();
            dp[i]=sm[i1];

            maxi(dp[i], qry(0,i1-1)+i+1);
            maxi(dp[i], qry1(i1+1,n*2)-i-1);
            upd(i1,dp[i]-i-1);
            upd1(i1,dp[i]+i+1);
            maxi(sm[i1], dp[i]);
        }
        cout << dp[n-1] << "\n";
    }
    
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