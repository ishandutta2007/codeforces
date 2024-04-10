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

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , m , l , r , x , y , ans = INF , ind , block[MAXN];
pair<ll , pll> seg[MAXN];
vector<pll> line;
map<ll , ll> cnt;

void marge(pll s)
{
    if(r < s.X) return;
    r = max(r , s.Y);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    cnt[1] = 0;
    cnt[INF] = 0;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> block[i];
    }
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> l >> r >> y;
        seg[i] = {y , {l , r}};
    }

    sort(block , block + n);
    sort(seg , seg + m);

    y = -1 , l = 2 , r = 2;
    for(ll i = 0 ; i < m ; i++)
    {
        if(seg[i].X != y)
        {
            if(l <= 1 && r >= block[0])
            {
                line.push_back({l , r});
            }
            l = seg[i].Y.X;
            r = seg[i].Y.Y;
        }
        marge(seg[i].Y);
    }
    if(l <= 1 && r >= block[0])
    {
        line.push_back({l , r});
    }

    for(ll i = 0 ; i < n ; i++)
    {
        cnt[block[i] + 1]++;
    }
    for(ll i = 0 ; i < line.size() ; i++)
    {
        cnt[line[i].X]++;
        cnt[line[i].Y + 1]--;
    }

    for(auto &i : cnt)
    {
        x += i.Y;
        if(i.X > 0 && i.X <= ll(1e9))  ans = min(ans , x);
    }
    cout << (ans == INF ? 0 : ans) << endl;


    return 0;
}