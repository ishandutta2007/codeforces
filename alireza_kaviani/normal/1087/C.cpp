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
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1010;
vector<pll> vec , ans;
ll x , y , mark[MAXN] , mp[MAXN][MAXN];

void go(pll f , pll s)
{
    for(ll i = f.Y ; i <= s.Y ; i++)
    {
        mp[f.X][i] = 1;
    }
    for(ll i = min(f.X , s.X) ; i <= max(f.X , s.X) ; i++)
    {
        mp[i][s.Y] = 1;
    }
}

ll dist(pll a , pll b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    for(ll i = 0 ; i < 3 ; i++)
    {
        cin >> x >> y;
        vec.push_back({y , x});
    }
    sort(all(vec));
    mp[vec[0].Y][vec[0].X] = 1;
    for(ll i = 1 ; i < 3 ; i++)
    {
        x = vec[i].Y , y = vec[i].X;
        ll x1 , y1 , d = 8e18;
        for(ll j = 0 ; j < MAXN ; j++)
        {
            for(ll k = 0 ; k < MAXN ; k++)
            {
                if(mp[j][k])
                {
                    if(dist({j , k} , {x , y}) < d)
                    {
                        d = dist({j , k} , {x , y});
                        x1 = j;
                        y1 = k;
                    }
                }
            }
        }
        //cout << x1 << sep << y1 << sep << x << sep << y << endl;
        go({x1 , y1} , {x , y});
    }

    for(ll i = 0 ; i < MAXN ; i++)
    {
        for(ll j = 0 ; j < MAXN ; j++)
        {
            if(mp[i][j])
            {
                ans.push_back({i , j});
            }
        }
    }
    cout << ans.size() << endl;
    for(pll i : ans)    cout << i.X << sep << i.Y << endl;

    return 0;
}