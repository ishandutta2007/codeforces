///      That's a Cigarette Day, my Sun

#include <bits/stdc++.h>

#pragma pack(1)
#pragma GCC optimize("O3")


#define pb push_back
#define mp make_pair
#define fi first
#define prev asfansjfansjabfasjlbfa
#define se second
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define elif else if
#define out_files freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define y1 asnflainflawnfaw
#define y0 snalfklawnfasdaspqw
#define BLEAT cout << "bleat!!!\n"
#define files(x) ((x != "") ? freopen(x".in", "r", stdin), freopen(x".out", "w", stdout) : 0)
#define files_dat_sol(x)  ((x != "") ? freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout) : 0)
#define next askfnlabfae

using namespace std;
#define int long long

typedef std::vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <int, int> pii;
typedef std::vector <pii> vii;
typedef long double ld;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

const int inf = 1000000000;
const ll INF = 1LL*inf*inf;
const long double eps = 1e-9;
const ll md = 1e9 + 7;
const long double EPS = 1e-5;
const ll maxll = std::numeric_limits<ll>::max();
const long double PI = acos(-1.0);

template <typename name> inline name sqr(name x)
{
    return x*x;
}

ld log(ld base, ld n)
{
    return log(n) / log(base);
}

inline ll multmod(ll a, ll b, ll md)
{
    if (!a) return 0;
    if (a % 2 == 1)
        return (multmod(a-1, b, md) + b) % md;
    else
        return sqr(multmod(a/2, b, md)) % md;
}

template <typename name> inline name bpow(const name& base, ll exp, const ll& md = maxll)
{
    if (exp == 1) return base;
    if (exp % 2 == 1)
        return (bpow<name>(base, exp-1, md) * base) % md;
    else
    {
        name k = bpow<name>(base, exp/2, md);
        return (k*k)%md;
    }
}

unsigned char ccc;

inline void read(int &n)
{
    n = 0;
    bool _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
}

inline void read(int &n, int& m)
{
    read(n);
    read(m);
}

inline void read(int &n, int &m, int &k)
{
    read(n);
    read(m);
    read(k);
}

inline void read(std::string &s)
{
    s = "";
    while (true)
    {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        s += ccc;
    }
}

template<typename T1, typename T2> inline T1 min(const T1 x, const T2 y)
{
    return (x > y ? y : x);
}

template<typename T1, typename T2> inline T1 max(const T1 x, const T2 y)
{
    return (x < y ? y : x);
}

template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& rhs)
{
    os << rhs.fi << " " << rhs.se;
    return os;
}

template<typename T1> ostream& operator<<(ostream& os, const vector<T1>& rhs)
{
    for (int i=0; i<(int)rhs.size(); i++)
        cout << rhs[i] << (i == (int)rhs.size() - 1 ? "" : " ");
    return os;
}

///-------------------------End of Template-------------------------///

const int MAXN = 2e6;

int n, m, a[MAXN], bad[MAXN], cnt[MAXN], dp[MAXN], pred[MAXN];

int gcd (int a, int b, int & x, int & y)
{
	if (a == 0)
    {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int next (int a, int b, int c, int & x0, int & y0, int & g)
{
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return -1;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	if (x0<0){
        int k=abs(x0)/(b/g)+((abs(x0)%(b/g))>0);
        x0+=k*b/g;
	}
	else{
        int k=abs(x0)/(b/g);
        x0-=k*b/g;
	}
	return x0;
}

main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #else
        files("");
    #endif // LOCAL

    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>a[i],
        bad[a[i]] = 1;

    for (int i=1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            cnt[i] = m / i;
            for (int j=i; j<=m; j+=i)
            {
                if ((__gcd(j / i, m / i) != 1) || bad[j]) cnt[i]--;
            }

            if (i == m / i) continue;
            cnt[m / i] = i;
            for (int j=m / i; j <= m; j+= m / i)
            {
                if ((__gcd(j / (m / i), m / (m / i)) != 1) || bad[j]) cnt[m / i]--;
            }
        }
    }

    //if (!bad[0]) cnt[m] = 1;

    //for (int i=1; i<=m; i++)
    //    cout << i << " " << cnt[i] << "\n";

    for (int i=m; i>=1; i--)
    {
        if (m % i != 0) continue;
        int mx = 0, pos = -1;
        for (int j=i + i; j<=m; j+=i)
            if (mx < dp[j]) pos = j, mx = dp[j];
        pred[i] = pos;
        dp[i] = mx + cnt[i];
    }
    vi ans(0);
    map<int,bool> use_ans;
    int pos = 1, p = 1, last = 1;
    vi cur(0);
    while (pos != -1)
    {
        for (int i=pos; i<=m; i+=pos)
        {
            if ((__gcd(i / pos, m / pos) != 1) || bad[i]) continue;
            int q, w, e;
            if (use_ans[(p * next(last, m, i % m, q, w, e)) % m]||bad[(p * next(last, m, i % m, q, w, e)) % m]){
                pos=-1;
                goto labelka;
            }
            ans.pb(next(last, m, i % m, q, w, e));
            p = (p * next(last, m, i % m, q, w, e)) % m;
            use_ans[p]=1;
            last = i % m;
            cur.pb(p);
        }
        pos = pred[pos];
        labelka:;
    }
    cout<<ans.size()<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    //cout << "\n" << cur;
}