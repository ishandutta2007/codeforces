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

int main()
{
    fast_io;

    ll n , ans = 1 , l = -1 , r = -1;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n ; i++)
    {
        cin >> vec[i];
        l = (l == -1 && vec[i] == 1 ? i : l);
        r = (vec[i] == 1 ? i : r);
    }

    for(int i = l + 1; i < n ; i++)
    {
        if(vec[i] == 1)
        {
            ans *= i - l;
            l = i;
        }
    }
    cout << (l == -1 ? 0 : ans) << endl;

    return 0;
}