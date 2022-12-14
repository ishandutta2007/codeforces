/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll Sqrt(ll x, ll y) {
    ll t = pow(x, 1. / y);
    for (ll i = max(0LL, t - 10); i <= t + 10; i++) {
        if (poww(i, y, ll(8e18)) == x) return i;
    }
    return -1;
}

set_random;

const ll MAXN = 1010;
const ll INF = 8e18;
const ll MOD1 = 998244353;
const ll MOD2 = 1e9 + 7;
const ll MOD3 = 1e9 + 9;

vector<ll> row[MAXN] , col[MAXN];
vector<pll> RL[MAXN] , CL[MAXN];
vector<pair<ll , pll>> stars;
Tree<pll> rowLines[MAXN] , colLines[MAXN];
ll n , m , cnt;
string s[MAXN];

ll getL(vector<ll> vec , ll i)
{
    return vec[lower_bound(all(vec) , i) - vec.begin() - 1];
}

ll getR(vector<ll> vec , ll i)
{
    return vec[upper_bound(all(vec) , i) - vec.begin()];
}

void addLine(Tree<pll> &lines , pll l)
{
    if(lines.size() == 0)
    {
        lines.insert(l);
        return;
    }
    pll p = *prev(lines.upper_bound({l.X , INF}));
    if(p.X <= l.X && l.X <= p.Y)
    {
        lines.erase(p);
        lines.insert({p.X , max(p.Y , l.Y)});
    }
    else
    {
        lines.insert(l);
    }
}

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++) cin >> s[i];

    for(ll i = 0 ; i < MAXN ; i++)
    {
        row[i].push_back(-1);
        row[i].push_back(m);
        col[i].push_back(-1);
        col[i].push_back(n);
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '.')
            {
                row[i].push_back(j);
                col[j].push_back(i);
            }
            else    cnt++;
        }
    }

    for(ll i = 0 ; i < MAXN ; i++)
    {
        sort(all(row[i]));
        sort(all(col[i]));
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '*')
            {
                pll r = {getL(row[i] , j) , getR(row[i] , j)};
                pll c = {getL(col[j] , i) , getR(col[j] , i)};
                ll x = min({j - r.X , r.Y - j , i - c.X , c.Y - i});
                if(x > 1)
                {
                    x--;
                    stars.push_back({x , {i + 1 , j + 1}});
                    RL[i].push_back({j - x , j + x});
                    CL[j].push_back({i - x , i + x});
                }
            }
        }
    }
    for(ll i = 0 ; i < MAXN ; i++)
    {
        Sort(RL[i]);
        for(ll j = 0 ; j < RL[i].size() ; j++)
        {
            addLine(rowLines[i] , RL[i][j]);
        }
        Sort(CL[i]);
        for(ll j = 0 ; j < CL[i].size() ; j++)
        {
            addLine(colLines[i] , CL[i][j]);
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '*')
            {
                ll ind = rowLines[i].order_of_key({j , INF});
                ind--;
                if(ind != -1)
                {
                    pll p = *rowLines[i].find_by_order(ind);
                    if(p.X <= j && j <= p.Y) {
                        cnt--;
                        continue;
                    }
                }
                ind = colLines[j].order_of_key({i , INF});
                ind--;
                if(ind != -1)
                {
                    pll p = *colLines[j].find_by_order(ind);
                    if(p.X <= i && i <= p.Y)
                    {
                        cnt--;
                        continue;
                    }
                }
            }
        }
    }

    if(cnt) return cout << -1 << endl , 0;
    cout << stars.size() << endl;
    for(pair<ll , pll> i : stars)
    {
        cout << i.Y.X << sep << i.Y.Y << sep << i.X << endl;
    }

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