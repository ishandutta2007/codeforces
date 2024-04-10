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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

map<string , int> mp;

int main()
{
    fast_io;

    mp["rat"] = 1;
    mp["woman"] = mp["child"] = 2;
    mp["man"] = 3;
    mp["captain"] = 4;

    int n;
    cin >> n;
    vector<pair<pii , string> > vec(n);
    for(int i = 0 ; i < n ; i++)
    {
        string s , t;
        cin >> s >> t;
        vec[i] = {{mp[t] , i} , s};
    }
    Sort(vec);
    for(int i = 0 ; i < n ; i++)    cout << vec[i].Y << endl;


    return 0;
}