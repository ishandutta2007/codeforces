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

const int SEGMAX = 1e5 + 10;
ll seg[4 * SEGMAX];
bool mark[4 * SEGMAX];
struct SEGMENT
{
    void Build (ll id, ll l , ll r , ll arr[])
    {
        if(l == r)
        {
            mark[id] = 0;
            seg[id] = arr[l];
            return;
        }

        ll mid = (l + r) / 2;
        Build(id * 2 + 1 , l , mid , arr);
        Build(id * 2 + 2 , mid + 1 , r , arr);

        mark[id] = !mark[id * 2 + 1];
        if(mark[id])
        {
            seg[id] = seg[id * 2 + 1] | seg[id * 2 + 2];
        }
        else
        {
            seg[id] = seg[id * 2 + 1] ^ seg[id * 2 + 2];
        }
        return;
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

        if(mark[id])
        {
            seg[id] = seg[id * 2 + 1] | seg[id * 2 + 2];
        }
        else
        {
            seg[id] = seg[id * 2 + 1] ^ seg[id * 2 + 2];
        }
        return;
    }
};

int main()
{
    fast_io;

    SEGMENT Seg;
    ll n , m;
    cin >> n >> m;
    n = (1 << n);

    ll arr[n];
    for(int i = 0 ; i < n ; i++)    cin >> arr[i];
    Seg.Build(0 , 0 , n - 1 , arr);

    while(m--)
    {
        ll p , b;
        cin >> p >> b;
        Seg.Modify(0 , 0 , n , p , b);
        cout << seg[0] << endl;
    }

    return 0;
}