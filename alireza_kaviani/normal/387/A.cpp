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
inline int input(){int n; cin >> n ; return n;}

int f(char a , char b)
{
    return (a - 48) * 10 + (b - 48);
}

int main()
{
    fast_io;

    string s , t;
    cin >> s >> t;
    int x = f(s[0] , s[1]) * 60 + f(s[3] , s[4]) , y = f(t[0] , t[1]) * 60 + f(t[3] , t[4]) , d = (x - y + 24 * 60) % (24 * 60);
    int h = d / 60 , m = d % 60;
    cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << endl;

    return 0;
}