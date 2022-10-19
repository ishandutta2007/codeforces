#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int SEGMAX = 2e5 + 10 , MOD = 1e9 + 7;
ll n , m , k , a[SEGMAX] , sag[2][4 * SEGMAX] , lazy[2][4 * SEGMAX];
struct SEGMENT
{
    ll ind;
    ll cmp(ll x , ll y) { return x + y;}

    void Build (ll id, ll l , ll r , ll arr[])
    {
        if(l == r)
        {
            sag[ind][id] = arr[l];
            return;
        }

        ll mid = (l + r) / 2;
        Build(id * 2 + 1 , l , mid , arr);
        Build(id * 2 + 2 , mid + 1 , r , arr);
        sag[ind][id] = cmp(sag[ind][id * 2 + 1] , sag[ind][id * 2 + 2]);
        return;
    }

    void Shift(ll id , ll l , ll r)
    {
        sag[ind][id] += (r - l + 1) * lazy[ind][id];
        if(l != r)
        {
            lazy[ind][id * 2 + 1] += lazy[ind][id];
            lazy[ind][id * 2 + 2] += lazy[ind][id];
        }
        lazy[ind][id] = 0;
    }

    void Modify(ll id , ll l , ll r , ll x , ll v)
    {
        if(l == r)
        {
            sag[ind][id] = v;
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
        sag[ind][id] = cmp(sag[ind][id * 2 + 1] , sag[ind][id * 2 + 2]);
    }
    void Add(ll id , ll l , ll r , ll ql , ll qr , ll diff)
    {
        Shift(id , l , r);
        if(l > r || l > qr || r < ql)   return;

        if(l >= ql && r <= qr)
        {
            sag[ind][id] += (r - l + 1) * diff;
            if(l != r)
            {
                lazy[ind][id * 2 + 1] += diff;
                lazy[ind][id * 2 + 2] += diff;
            }
            return;
        }

        ll mid = (l + r) / 2;
        Add(id * 2 + 1 , l , mid , ql , qr , diff);
        Add(id * 2 + 2 , mid + 1 , r , ql , qr , diff);
        sag[ind][id] = cmp(sag[ind][id * 2 + 1] , sag[ind][id * 2 + 2]);
    }

    ll Get(ll id , ll l , ll r , ll ql , ll qr)
    {
        Shift(id , l , r);
        if(ql > r || qr < l)  return 0;
        if(ql <= l && qr >= r)
        {
            return sag[ind][id];
        }
        ll mid = (l + r) / 2;
        return cmp(Get(id * 2 + 1, l , mid , ql , qr) , Get(id * 2 + 2 , mid + 1 , r , ql , qr));
    }

};

int main()
{
    fast_io;

    SEGMENT val , cnt;
    val.ind = 0;
    cnt.ind = 1;

    cin >> n >> m >> k;
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    val.Build(0 , 0 , n - 1 , a);

    vector<pair<pll , ll> > vec;
    for(ll i = 0 ; i < m ; i++)
    {
        ll l , r , x;
        cin >> l >> r >> x;
        vec.push_back({{l - 1 , r - 1} , x});
    }
    for(ll i = 0 ; i < k ; i++)
    {
        ll l , r;
        cin >> l >> r;
        l-- , r--;
        cnt.Add(0 , 0 , m - 1 , l , r , 1);
    }

    for(ll i = 0 ; i < m ; i++)
    {
        ll x = cnt.Get(0 , 0 , m - 1 , i , i);
        val.Add(0 , 0 , n - 1 , vec[i].X.X , vec[i].X.Y , vec[i].Y * x);
    }
    for(ll i = 0 ; i < n ; i++)
    {
        cout << val.Get(0 , 0 , n - 1 , i , i) << ends;
    }


    return 0;
}