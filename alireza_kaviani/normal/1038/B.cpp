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

int main()
{
    fast_io;

    ll n , sum = 0;
    cin >> n;
    sum = n * (n + 1) / 2;

    for(ll i = 2 ; i * i <= sum ; i++)
    {
        if(sum % i == 0)
        {
            cout << "Yes" << endl;
            vector<ll> a , b;
            for(ll j = 1 ; j <= n ; j++)
            {
                if(j % i == 0)    a.push_back(j);
                else    b.push_back(j);
            }
            cout << a.size() << ends;
            for(ll i : a)   cout << i << ends;
            cout << endl << b.size() << ends;
            for(ll i : b)   cout << i << ends;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}