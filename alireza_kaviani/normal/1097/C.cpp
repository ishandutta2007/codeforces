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
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

ll n , ind , ans , cnt;
string s;
vector<pll> pos , neg;

pll get(string s)
{
    ll sum = 0 , mn = 0;
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '(') sum++;
        else            sum--;
        mn = min(mn , sum);
    }
    return {sum , mn};
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s;
        pll x = get(s);
        if(x.X > 0)
        {
            pos.push_back(get(s));
        }
        else if(x.X < 0)
        {
            neg.push_back(get(s));
        }
        else
        {
            if(x.Y >= 0)    cnt++;
        }
    }

    sort(all(pos));
    sort(all(neg) , greater<pll>());

    for(ll i = 0 ; i < pos.size() ; i++)
    {
        if(pos[i].Y < 0)    continue;
        for( ; ind < neg.size() ; ind++)
        {
            if(pos[i].X + neg[ind].X < 0)   break;
            if(neg[ind].Y + pos[i].X < 0)   continue;
            if(pos[i].X + neg[ind].X != 0)  continue;
            ans++, ind++;
            break;
        }
    }

    cout << ans + cnt / 2 << endl;

    return 0;
}