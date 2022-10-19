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

bool ok(string s)
{
    ll a[3] = {0 , 0 , 0};
    for(ll i = 0 ; i < s.size() ; i++)
    {
        if('0' <= s[i] && s[i] <= '9')  a[0] = 1;
        if('a' <= s[i] && s[i] <= 'z')  a[1] = 1;
        if('A' <= s[i] && s[i] <= 'Z')  a[2] = 1;
    }
    return (a[0] == 1 && a[1] == 1 && a[2] == 1);
}

int main()
{
    fast_io;

    ll q;
    cin >> q;
    while(q--)
    {
        string x[3] = {"1" , "A" , "a"};
        string s , ans;
        cin >> s;
        ll n = s.size() , mn = 1e9;

        for(ll i = 0 ; i < 8 ; i++)
        {
            string r = "";
            for(ll j = 0 ; j < 3 ; j++)
            {
                if(i & (1LL << j))  r += x[j];
            }
            for(ll j = 0 ; j <= n - r.size() ; j++)
            {
                if(ok(s.substr(0 , j) + r + s.substr(j + r.size())))
                {
                    if(r.size() < mn)   ans = s.substr(0 , j) + r + s.substr(j + r.size()) , mn = r.size();
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}