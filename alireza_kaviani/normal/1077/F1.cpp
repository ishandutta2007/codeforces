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

const ll SEGN = 1010;
const ll MAXN = 1010;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

struct SegTree
{
    ll seg[SEGN * 2];
    //ll lazy[SEGN * 2];

    ll cmp(ll x , ll y)
    {
        return max(x , y);
    }

    void Build(ll id , ll l , ll r , ll arr[])
    {
        if(l == r)
        {
            seg[id] = arr[l];
            return;
        }
        ll mid = (l + r) / 2;
        Build(id * 2 + 1 , l , mid , arr);
        Build(id * 2 + 2 , mid + 1 , r , arr);
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }

    void Modify(ll id , ll l , ll r , ll x , ll val)
    {
        if(x < l || r < x)  return;
        if(l == r)
        {
            seg[id] = val;
            return;
        }
        ll mid = (l + r) / 2;
        Modify(id * 2 + 1 , l , mid , x , val);
        Modify(id * 2 + 2 , mid + 1 , r , x , val);
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }

    /*void Shift(ll id , ll l , ll r)
    {
        seg[id] += (r - l + 1) * lazy[id];
        if(l != r)
        {
            lazy[id * 2 + 1] += lazy[id];
            lazy[id * 2 + 2] += lazy[id];
        }
        lazy[id] = 0;
    }*/

    void Add(ll id , ll l , ll r , ll ql , ll qr , ll val)
    {
        //Shift(id , l , r);
        if(qr < l || r < ql)    return;
        if(ql <= l && r <= qr)
        {
            //lazy[id] += val;
            //Shift(id , l , r);
            return;
        }

        ll mid = (l + r) / 2;
        Add(id * 2 + 1 , l , mid , ql , qr , val);
        Add(id * 2 + 1 , mid + 1 , r , ql , qr , val);
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }

    ll Get(ll id , ll l , ll r , ll ql , ll qr)
    {
        //Shift(id , l , r);
        if(qr < l || r < ql)    return 0;
        if(ql <= l && r <= qr)  return seg[id];

        ll mid = (l + r) / 2;
        return cmp(Get(id * 2 + 1 , l , mid , ql , qr) , Get(id * 2 + 2 , mid + 1 , r , ql , qr));
    }

    void build(ll arr[])
    {
        Build(0 , 0 , SEGN - 1 , arr);
    }

    void modify(ll x , ll val)
    {
        Modify(0 , 0 , SEGN - 1 , x , val);
    }

    void add(ll ql , ll qr , ll val)
    {
        Add(0 , 0 , SEGN - 1 , ql , qr , val);
    }

    ll get(ll ql , ll qr)
    {
        return Get(0 , 0 , SEGN - 1 , ql , qr);
    }
};

ll n , k , x , p[MAXN];
SegTree dp[MAXN];

int main() {
    fast_io;
    set_random;

    cin >> n >> k >> x;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];

    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= min(x , i) ; j++)
        {
            ll mx = dp[j - 1].get(max(0LL , i - k) , i - 1) + p[i];
            if(mx == p[i] && i > k) continue;
            dp[j].modify(i , mx);
        }
    }

    ll ans = 0;
    for(ll i = 0 ; i <= x ; i++)
    {
        ans = max(ans , dp[i].get(n - k + 1 , n));
    }
    cout << (ans == 0 ? -1 : ans);

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