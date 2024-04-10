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

int find(string d[7] , string s)
{
    for(int i = 0 ; i < 7 ; i++)
        if(d[i] == s)   return i;
    return -1;
}

int main()
{
    fast_io;

    int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string d[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

    string s , t;
    cin >> s >> t;
    for(int i = 0 ; i < 12 ; i++)
    {
        if(d[(find(d , s) + m[i]) % 7] == t)    return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;

    return 0;
}