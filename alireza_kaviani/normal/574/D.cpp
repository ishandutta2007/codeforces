#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll seg[4 * MAXN] , lazy[4 * MAXN];
struct SEGMENT
{
    ll cmp(ll x , ll y) { return min(x , y);}

    void Build (ll id, ll l , ll r , ll arr[])
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
        return;
    }

    void Shift(ll id , ll l , ll r)
    {
        seg[id] += lazy[id];
        if(l != r)
        {
            lazy[id * 2 + 1] += lazy[id];
            lazy[id * 2 + 2] += lazy[id];
        }
        lazy[id] = 0;
    }

    void Modify(ll id , ll l , ll r , ll x , ll v)
    {
        if(l == r)
        {
            seg[id] = v;
            return;
        }

        ll mid = (l + r) / 2;
        if(x <= mid)
        {
            Modify(id * 2 + 1 , l , mid , x , v);
        }
        else
        {
            Modify(id * 2 + 2 , mid + 1, r , x , v);
        }
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }
    void Add(ll id , ll l , ll r , ll ql , ll qr , ll diff)
    {
        Shift(id , l , r);
        if(l > r || l > qr || r < ql)   return;

        if(l >= ql && r <= qr)
        {
            seg[id] += diff;
            if(l != r)
            {
                lazy[id * 2 + 1] += diff;
                lazy[id * 2 + 2] += diff;
            }
            return;
        }

        ll mid = (l + r) / 2;
        Add(id * 2 + 1 , l , mid , ql , qr , diff);
        Add(id * 2 + 2 , mid + 1 , r , ql , qr , diff);
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }

    ll Get(ll id , ll l , ll r , ll ql , ll qr)
    {
        Shift(id , l , r);
        if(ql > r || qr < l)  return INF;
        if(ql <= l && qr >= r)
        {
            return seg[id];
        }
        ll mid = (l + r) / 2;
        return cmp(Get(id * 2 + 1, l , mid , ql , qr) , Get(id * 2 + 2 , mid + 1 , r , ql , qr));
    }

};

ll n , mx , p[MAXN] , ans[MAXN];

int main()
{
    fast_io;
    SEGMENT SEG;

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];
    p[0] = 1;
    p[n - 1] = 1;
    SEG.Build(0 , 0 , n - 1 , p);
    for(ll i = 1 ; i < n ; i++)
    {
        SEG.Add(0 , 0 , n - 1 , i , n - 1 , 1);
    }

    for(ll i = 0 ; i < n ; i++)
    {
        ans[i] = SEG.Get(0 , 0 , n - 1 , 0 , n - 1);
        SEG.Add(0 , 0 , n - 1 , 0 , i , 1);
        SEG.Add(0 , 0 , n - 1 , i + 1 , n - 1 , -1);
        mx = max(mx , ans[i]);
    }
    cout << mx << endl;

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