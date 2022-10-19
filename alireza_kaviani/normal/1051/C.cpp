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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1000;
ll n , a , b , s[MAXN] , type[MAXN] , cnt[MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        cnt[s[i]]++;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        if(cnt[s[i]] == 1)
        {
            if(a > b)   type[i] = 2 , b++;
            else    type[i] = 1 , a++;
        }
        if(cnt[s[i]] == 2)
        {
            type[i] = 1;
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        if(type[i] == 0)
        {
            if(a > b)   type[i] = 2 , b++;
            else type[i] = 1;
        }
    }

    if(a != b)  return cout << "NO" << endl , 0;
    cout << "YES" << endl;
    for(ll i = 0 ; i < n ; i++) cout << (type[i] == 1 ? "A" : "B");

    return 0;
}