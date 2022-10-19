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

const int SEGMAX = 2e5 + 10 , MOD = 1e9 + 7;
ll seg[4 * SEGMAX] , lazy[4 * SEGMAX];
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

    ll Get(ll id , ll l , ll r , ll ql , ll qr)
    {
        Shift(id , l , r);
        if(ql > r || qr < l)  return 8e18;
        if(ql <= l && qr >= r)
        {
            return seg[id];
        }
        ll mid = (l + r) / 2;
        return cmp(Get(id * 2 + 1, l , mid , ql , qr) , Get(id * 2 + 2 , mid + 1 , r , ql , qr));
    }

};

const int MAXN = 2e5 + 10;
int l[MAXN] , r[MAXN];

int main()
{
    fast_io;

    SEGMENT Seg;
    fill(l , l + MAXN , -1);
    int n , q , z = -1;
    cin >> n >> q;

    ll a[n + 1];
    a[0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(a[i] == 0)   { a[i] = a[i - 1]; z = i;}
    }
    Seg.Build(0 , 0 , n , a);

    for(int i = 1 ; i <= n ; i++)
    {
        if(l[a[i]] == -1)   l[a[i]] = i;
        r[a[i]] = i;
    }

    for(int i = 1 ; i <= q ; i++)
    {
        if(l[i] == -1)  continue;
        ll t = Seg.Get(0 , 0 , n , l[i] , r[i]);
        if(t < i)   return cout << "NO" << endl , 0;
    }

    if(l[q] == -1 && z == -1)   return cout << "NO" << endl , 0;
    if(l[q] == -1)  a[z] = q;
    cout << "YES" << endl;
    for(int i = 1 ; i <= n ; i++)   cout << a[i] << ends;

    return 0;
}