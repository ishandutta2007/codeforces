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

ll n;
string x[] = {"O-|" , "-O|"} , y[] = {"-OOOO" , "O-OOO" , "OO-OO" , "OOO-O" , "OOOO-"};
stack<string> ans;

int main()
{
    fast_io;

    cin >> n;
    if(n == 0)  cout << x[0] + y[0] << endl;
    while(n != 0)
    {
        cout << x[n % 10 / 5] + y[n % 5] << endl;
        n /= 10;
    }

    return 0;
}