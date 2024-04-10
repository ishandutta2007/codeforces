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

const ll MAXN = 4e5 + 10;
ll n , c1 , c2 , ca , x , ans;
string s;
vector<ll> vec[2];
vector<pair<ll , pll>> q;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s >> x;
        if(s == "11")
        {
            ans += x;
            c1++;
            c2++;
            ca++;
        }
        if(s == "01")
        {
            vec[0].push_back(x);
        }
        if(s == "10")
        {
            vec[1].push_back(x);
        }
        if(s == "00")
        {
            q.push_back({x , {0 , 0}});
        }
    }
    Sort(vec[0]);
    Sort(vec[1]);

    while(vec[0].size() != 0 && vec[1].size() != 0)
    {
        ans += vec[0].back() + vec[1].back();
        c1++;
        c2++;
        ca += 2;
        vec[0].pop_back();
        vec[1].pop_back();
    }

    for(ll i = 0 ; i < 2 ; i++)
    {
        while(vec[i].size() != 0)
        {
            q.push_back({vec[i].back() , {i != 0 , i ==0}});
            vec[i].pop_back();
        }
    }
    sort(all(q) , greater<pair<ll , pll>>());

    for(ll i = 0 ; i < q.size() ; i++)
    {
        if((c1 + q[i].Y.X) * 2 >= (ca + 1) && (c2 + q[i].Y.Y) * 2 >= (ca + 1))
        {
            ans += q[i].X;
            c1 += q[i].Y.X;
            c2 += q[i].Y.Y;
            ca++;
        }
    }
    cout << ans << endl;

    return 0;
}