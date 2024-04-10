#include <bits/stdc++.h>
using namespace std;

template<class t>
void operator>>(istream &in , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cin >> vec[i];
    }
}
template<class t>
void operator << (ostream &out , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cout << vec[i] << " ";
    }
}

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

    ll n , k  , ans = 0;
    cin >> n >> k;
    vector<ll> a(n) , b(n);
    vector<pll> vec;
    cin >> a;   cin >> b;

    for(int i = 0; i < n; i++)
    {
        vec.push_back({a[i] - b[i] , a[i]});
    }

    Sort(vec);

    for(int i = 0 ;i < k ; i++)     ans += vec[i].Y;
    for(int i = k ;i < n ; i++)
    {
        if(vec[i].X > 0)
        {
            ans += vec[i].Y - vec[i].X;
        }
        else
        {
            ans += vec[i].Y;
        }
    }
    cout << ans << endl;

    return 0;
}