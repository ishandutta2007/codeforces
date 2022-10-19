#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<string , int> mp;
map<int , string> mp2;

int main()
{
    fast_io;

    mp["v"] = 0 ; mp["<"] = 1 ; mp["^"] = 2 ; mp[">"] = 3;
    mp2[0] = "v" ; mp2[1] = "<" ; mp2[2] = "^" ; mp2[3] = ">";

    string s , k;
    int n;
    cin >> s >> k >> n;

    string cw = mp2[(mp[s] + n) % 4] , ccw = mp2[(mp[k] + n) % 4];

    if(cw == k && ccw != s)
    {
        cout << "cw" << endl;
        return 0;
    }
    if(cw != k && ccw == s)
    {
        cout << "ccw" << endl;
        return 0;
    }
    cout << "undefined" << endl;

    return 0;
}