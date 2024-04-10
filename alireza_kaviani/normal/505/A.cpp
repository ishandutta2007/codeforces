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

bool ok(string s)
{
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != s[s.size() - i - 1]) return 0;
    }
    return 1;
}

int main()
{
    fast_io;

    string s;
    cin >> s;

    for(int i = 0 ; i <= s.size() ; i++)
    {
        for(int j = 0 ; j < 26 ; j++)
        {
            string x = s.substr(0 , i) + string(1 , j + 97) + s.substr(i , s.size());
            if(ok(x))   return cout << x << endl , 0;
        }
    }
    cout << "NA" << endl;

    return 0;
}