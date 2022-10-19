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

int f(int n , int m)
{
    return (n % m == 0 ? n / m : n / m + 1);
}

int main()
{
    fast_io;

    int l , d , p;
    cin >> l >> d >> p;

    int x = f(p , d * 2) , lr = p - d * 2 * (x - 1) , y = f(lr , 2);
    cout << x << ends << y << ends << (lr % 2 == 0 ? 'R' : 'L') << endl;

    return 0;
}