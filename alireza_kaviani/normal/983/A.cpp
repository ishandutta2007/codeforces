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

bool check(ll q , ll b)
{
    while(q % b == 0 && b != 1)
    {
        q /= b;
        b = __gcd(q , b);
    }
    
    if(q == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    while(n--)
    {
        ll p , q , b , gcd;
        cin >> p >> q >> b;
        p = p % q;

        gcd = __gcd(p , q);
        p /= gcd;
        q /= gcd;

        if(p == 0 || check(q , __gcd(q , b)))
        {
            cout << "Finite" << endl;
        }
        else
        {
            cout << "Infinite" << endl;
        }
    }

    return 0;
}