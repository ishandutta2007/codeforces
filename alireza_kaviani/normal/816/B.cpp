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

const ll MAXN = 2e5 + 5 , SEGMAX = 2e5 + 10 , MOD = 1e9 + 7;
ll n , k , q , l , r , a , b , seg[4 * SEGMAX] , lazy[4 * SEGMAX];
struct SEGMENT
{
    ll cmp(ll x , ll y) { return x + y;}

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
        seg[id] += (r - l + 1) * lazy[id];
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
            seg[id] += (r - l + 1) * diff;
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

    void Set(ll id , ll l , ll r)
    {
        Shift(id , l , r);
        if(l == r)
        {
            seg[id] = (seg[id] >= k);
            return;
        }
        ll mid = (l + r) / 2;
        Set(id * 2 + 1 , l , mid);
        Set(id * 2 + 2 , mid + 1 , r);
        seg[id] = cmp(seg[id * 2 + 1] , seg[id * 2 + 2]);
    }

    ll Get(ll id , ll l , ll r , ll ql , ll qr)
    {
        Shift(id , l , r);
        if(ql > r || qr < l)  return 0;
        if(ql <= l && qr >= r)
        {
            return seg[id];
        }
        ll mid = (l + r) / 2;
        return cmp(Get(id * 2 + 1, l , mid , ql , qr) , Get(id * 2 + 2 , mid + 1 , r , ql , qr));
    }

};

int main()
{
    fast_io;

    SEGMENT Seg;
    cin >> n >> k >> q;

    for(ll i = 0 ; i < n ; i++)
    {
        cin >> l >> r;
        Seg.Add(0 , 0 , MAXN , l , r , 1);
    }
    Seg.Set(0 , 0 , MAXN);

    while(q--)
    {
        cin >> a >> b;
        cout << Seg.Get(0 , 0 , MAXN , a , b) << endl;
    }

    return 0;
}