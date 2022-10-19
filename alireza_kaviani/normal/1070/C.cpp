#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> L[MAXN] , R[MAXN];
ll n , k , m , ans;
pll fen[MAXN];
pair<pll , pll> query[MAXN]; // {{p , c} , {l , r}}

void add(ll ind , ll x , ll y)
{
    for( ; ind < MAXN ; ind += (ind & (-ind)))
    {
        fen[ind].X += x;
        fen[ind].Y += y;
    }
}

pll get(ll ind)
{
    pll res = {0 , 0};
    for( ; ind > 0 ; ind -= (ind & (-ind)))
    {
        res.X += fen[ind].X;
        res.Y += fen[ind].Y;
    }
    return res;
}

ll check(ll x)
{
    pll res = get(x);
    return res.X >= k;
}

int main() {
    fast_io;
    set_random;

    cin >> n >> k >> m;
    for(ll i = 1 ; i <= m ; i++)
    {
        cin >> query[i].Y.X >> query[i].Y.Y >> query[i].X.Y >> query[i].X.X;
    }
    sort(query + 1 , query + m + 1);

    for(ll i = 1 ; i <= m ; i++)
    {
        L[query[i].Y.X].push_back(i);
        R[query[i].Y.Y].push_back(i);
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j : L[i])
        {
            add(j , query[j].X.Y , query[j].X.X * query[j].X.Y);
        }

        ll l = 0 , r = m + 1;
        while(r - l > 1)
        {
            ll mid = (r + l) / 2;
            if(check(mid))  r = mid;
            else            l = mid;
        }

        pll res = get(r);
        if(r == m + 1)  ans += res.Y;
        else            ans += res.Y - (res.X - k) * query[r].X.X;

        for(ll j : R[i])
        {
            add(j , -query[j].X.Y , -query[j].X.X * query[j].X.Y);
        }
    }
    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/